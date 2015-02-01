#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include "TextObject.h"



using namespace std;
using namespace sf;
using Text_it = vector<TextObject>::iterator;

constexpr unsigned int windowWidth{ 800 }, windowHeight{ 600 };
constexpr float ballRadius{ 10.f }, ballVelocity{ 8.f };
constexpr float paddleWidth{ 60.f }, paddleHeight{ 20.f }, paddleVelocity{ 10.f };

constexpr float blockWidth{ 60.f }, blockHeight{ 20.f };
constexpr int countBlocksX{ 11 }, countBlocksY{ 4 };
Font myFont;

int lives = 3;
int points = 0;
int tempLives = lives;

//Let's create a class for our Ball
//'struct' == 'class' in C++

struct Player_rank
{
	string name;
	string points;

	Player_rank(string pName, string pPoints)
	{
		name = pName;
		points = pPoints;
	}
};

struct Ball
{
	// circleShape is an SFMLclass that
	//defines a renderable circle
	CircleShape shape;

	// 2D vector that stores the Ball's velocity
	Vector2f velocity{ -ballVelocity, -ballVelocity };

	// Let's create the Ball constructor
	// argument mX -> starting x coordinate
	// argument mY -> starting y coordinate

	Ball(float mX, float mY)
	{
		// Apply position, radius, colour and origin
		// to the CircleShape 'shape'.
		shape.setPosition(mX, mY);
		shape.setRadius(ballRadius);
		shape.setFillColor(Color::Red);
		shape.setOrigin(ballRadius, ballRadius);
	}

	// Let's update the ball: move its shape
	// by the current velocity
	void update()
	{ 
		shape.move(velocity);

		// We need to keep the ball "inside the screen"

		// If it's leaving toward the left, we need to set
		// horizontal velocity to a positive value (towards the right)

		if (left() < 0) velocity.x = ballVelocity;

		// Otherwise, if it's leaving towards the right, we need to
		// set the velocity to a negative value (towards the left)
		else if (right() > windowWidth) velocity.x = -ballVelocity;

		// the same idea can be applied for top/bottom collisions
		if (top() < 0) velocity.y = ballVelocity;
		else if (bottom() > windowHeight)
		{
			lives -= 1;
			shape.setPosition(float(windowWidth / 2), float(windowHeight / 2));
		}
	}

	float x()		{ return shape.getPosition().x; }
	float y()		{ return shape.getPosition().y; }
	float left()	{ return x() - shape.getRadius(); }
	float right()	{ return x() + shape.getRadius(); }
	float top()		{ return y() - shape.getRadius(); }
	float bottom()	{ return y() + shape.getRadius(); }
};


struct Paddle
{
	RectangleShape shape;
	Vector2f velocity;

	Paddle(float mX, float mY)
	{
		shape.setPosition(mX, mY);
		shape.setSize({ paddleWidth, paddleHeight });
		shape.setFillColor(Color::Red);
		shape.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);
	}

	void update()
	{
		shape.move(velocity);

		// To move the paddle, we check if the user is pressing
		// the left or right arrow key: if so, we change the velocity

		// To keep the paddle "inside the window", we change the velocity
		// only if it's position is inside the window
		if (Keyboard::isKeyPressed(Keyboard::Key::Left)
			&& left() > 0) velocity.x = -paddleVelocity;
		else if (Keyboard::isKeyPressed(Keyboard::Key::Right)
			&& right() < windowWidth) velocity.x = paddleVelocity;

		// If the user isn't pressing anything, stop moving
		else velocity.x = 0;
	}

	float x()		{ return shape.getPosition().x; }
	float y()		{ return shape.getPosition().y; }
	float left()	{ return x() - shape.getSize().x / 2.f; }
	float right()	{ return x() + shape.getSize().x / 2.f; }
	float top()		{ return y() - shape.getSize().x / 2.f; }
	float bottom()	{ return y() + shape.getSize().x / 2.f; }
	
};

struct Brick
{
	RectangleShape shape;

	// This boolean value will be used to check whether a brick has been hit or not
	bool destroyed{ false };

	// The constructor is almost identical to the Paddle one
	Brick(float mX, float mY)
	{
		shape.setPosition(mX, mY);
		shape.setSize({ blockWidth, blockHeight });
		shape.setFillColor(Color::Yellow);
		shape.setOrigin(blockWidth / 2.f, blockHeight / 2.f);
	}

	float x()		{ return shape.getPosition().x; }
	float y()		{ return shape.getPosition().y; }
	float left()	{ return x() - shape.getSize().x / 2.f; }
	float right()	{ return x() + shape.getSize().x / 2.f; }
	float top()		{ return y() - shape.getSize().x / 2.f; }
	float bottom()	{ return y() + shape.getSize().x / 2.f; }
};

// Dealing with collisions: let's define a generic function
// to check if two shapes are intersecting (colliding)
template<class T1, class T2> bool isIntersecting(T1& mA, T2& mB)
{
	return mA.right() >= mB.left() && mA.left() <= mB.right()
		&& mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
}

// Let's define a function that deals with paddle/ball collision
void testCollision(Paddle& mPaddle, Ball& mBall)
{

	// If there's no intersection, get out of the function
	if (!isIntersecting(mPaddle, mBall)) return;

	// Otherwiselet;s "push the ball upwards
	mBall.velocity.y = -ballVelocity;

	// And let;s direct it dependently on the position where the paddle was hit
	if (mBall.x() < mPaddle.x()) mBall.velocity.x = -ballVelocity;
	else mBall.velocity.x = ballVelocity;

}

void testCollision(Brick& mBrick, Ball& mBall)
{
	if (!isIntersecting(mBrick, mBall)) return;

	mBrick.destroyed = true;
	points += 5;

	float overlapLeft{ mBall.right() - mBrick.left() };
	float overlapRight{ mBrick.right() - mBall.left() };
	float overlapTop{ mBall.bottom() - mBrick.top() };
	float overlapBottom{ mBrick.bottom() - mBall.top() };

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));

	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

	if (abs(minOverlapX) < abs(minOverlapY))
		mBall.velocity.x = ballFromLeft ? -ballVelocity : ballVelocity;
	else
		mBall.velocity.y = ballFromTop ? -ballVelocity : ballVelocity;

}

void Highscore(RenderWindow& window)
{
	
	ofstream outfile;
	bool temp = true;

	TextObject HighscoreText{ myFont, 200, 250 };

	HighscoreText.mText.setString("Insert your name to save your highscore!");

	TextObject SaveNameText{ myFont, 200, 350 };
	
	Event event;
	string str = "";
	while (temp)
	{
		window.clear(Color::Black);
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Escape) break;
				else if (event.key.code == Keyboard::BackSpace)
				{
					str.pop_back();
					
				}
				else if (event.key.code == Keyboard::Return)
				{	
					outfile.open("Highscore.txt", fstream::app);
					outfile << str << "." << points << "\n";
					outfile.close();
					temp = false;

				}
			}

			if (event.type == Event::TextEntered)
			{
				if (event.text.unicode < 128 && event.text.unicode > 30)
				{
					str += static_cast<char>(event.text.unicode);
					SaveNameText.mText.setString(str);

				}
			}
			

			
		}
		window.draw(HighscoreText.mText);
		window.draw(SaveNameText.mText);
		window.display();
	}
	
	TextObject displayText{ myFont, 300, 5 };

	TextObject highscore1{ myFont, 300, 100 };
	TextObject highscore2{ myFont, 300, 150 };
	TextObject highscore3{ myFont, 300, 200 };
	TextObject highscore4{ myFont, 300, 250 };
	TextObject highscore5{ myFont, 300, 300 };

	vector<TextObject> highscoreText;
	highscoreText.push_back(highscore1);
	highscoreText.push_back(highscore2);
	highscoreText.push_back(highscore3);
	highscoreText.push_back(highscore4);
	highscoreText.push_back(highscore5);

	vector<Player_rank> highscores;
	ifstream infile("Highscore.txt");
	string line = "";
	
	if (infile.is_open())
	{
		while (getline(infile, line))
		{	
			string temp = line.substr(line.find_first_of('.') + 1);
			Player_rank player{ line.substr(0, line.find_first_of('.')), temp };
			highscores.emplace_back(player);
		}
	}

	auto compare = [](const Player_rank& a, const Player_rank& b) { return (stoi(a.points) > stoi(b.points)); };
	sort(highscores.begin(), highscores.end(), compare);
	

	vector<Player_rank>::iterator vecIt = highscores.begin();
	for (Text_it it = highscoreText.begin(); it != highscoreText.end(); ++it)
	{
		if (vecIt == highscores.end())
		{
			it->mText.setString("");
		}
		else
		{
			it->mText.setString(vecIt->name + "\t\t\t" + vecIt->points);
			++vecIt;
		}
		
	}


	while (true)
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) break;

		window.clear(Color::Black);
		window.draw(displayText.mText);

		for (auto& x : highscoreText)
		{
			window.draw(x.mText);
		}

		window.display();
	}
}


int main()
{
	

	// Let's create an instance of 'Ball'
	// positioned at the center of the window
	Ball ball{ float(windowWidth / 2), float(windowHeight / 2) };
	Paddle paddle{ float(windowWidth / 2), float(windowHeight - 50) };

	vector<Brick> bricks;

	for (int iX{ 0 }; iX < countBlocksX; ++iX)
		for (int iY{ 0 }; iY < countBlocksY; ++iY)
			bricks.emplace_back((iX + 1) * (blockWidth + 3) + 22,
								(iY + 2) * (blockHeight + 3));

	RenderWindow window{ { windowWidth, windowHeight }, "Arkanoid - Game" };
	window.setFramerateLimit(60);

	if (!myFont.loadFromFile("Sansation_Light.ttf"))
	{
		cout << "Error loading font\n";
	}
	TextObject livesText{ myFont, 0, 0 };
	TextObject pointsText{ myFont, 100, 0 };
	
	while (bricks.size() > 0 && lives != 0)
	{
		window.clear(Color::Black);

		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) break;

		// Every loop iteration, we need to update the ball
		ball.update();
		paddle.update();

		// Lets test the collision every game loop iteration
		testCollision(paddle, ball);

		for (auto& brick : bricks) testCollision(brick, ball);

		bricks.erase(remove_if(begin(bricks), end(bricks), 
			[](const Brick& mBrick){return mBrick.destroyed; }), 
			end(bricks));

		livesText.mText.setString("Lives: " + to_string(lives));
		pointsText.mText.setString("Points: " + to_string(points));
		// Let's render the Ball instance on the window
		window.draw(ball.shape);
		window.draw(paddle.shape);
		window.draw(livesText.mText);
		window.draw(pointsText.mText);

		for (auto& brick : bricks) window.draw(brick.shape);
		window.display();
	}

	window.clear(Color::Black);
	Highscore(window);

	return 0;
}