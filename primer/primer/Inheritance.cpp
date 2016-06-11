#include <string>
#include <iostream>

class Enemy
{
public :
	Enemy() :
		m_hp{ 5 },
		attack{ "bite" }
	{ std::cout << "Enemy here!\n"; }
	Enemy(int hp) : m_hp(hp) { std::cout << "Enemy here again!!!\n"; };
	virtual void greet() const { std::cout << "I am an enemy! I have " << health() << " health!\n"; }
	int health() const { return m_hp; }
	virtual void phrase(std::string &str) const { std::cout << str << attack << "\n"; }

private :
	std::string attack;
	int m_hp;

};

class Puff : public Enemy
{
public :
	Puff() : Enemy(10) { std::cout << "Puff here!\n"; }
	void greet() { std::cout << "I am a puff enemy! I have " << health() << " health!\n"; }
	void phrase(std::string &str) const override { std::cout << str << "\n"; }
};

class Flobb : public Enemy
{
public:
	Flobb() : Enemy(15) { std::cout << "Flobb here!\n"; }
	void greet() { std::cout << "I am a flobb enemy! I have " << health() << " health!\n"; }
};

int maina()
{
	Enemy e;
	Puff p;
	Flobb f;

	e.greet();
	e.phrase(std::string("My attack is "));
	p.greet();
	p.phrase(std::string("Puff is ready!"));
	f.greet();

}