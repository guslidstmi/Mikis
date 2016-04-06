#include <string>
#include <iostream>

class Enemy
{
public :
	Enemy() { hp = 5; }
	virtual void greet() { std::cout << "I am an enemy! I have " << health() << " health!" << std::endl; }
	int health() { return hp; }

private :
	int hp;

};

class Puff : Enemy
{
public :
	void greet() { std::cout << "I am a puff enemy! I have " << health() << " health!" << std::endl; }
};

class Flobb : Enemy
{
public:
	void greet() { std::cout << "I am a flobb enemy! I have " << health() << " health!" << std::endl; }
};

int main()
{
	Enemy e;
	Puff p;
	Flobb f;

	e.greet();
	p.greet();
	f.greet();

}