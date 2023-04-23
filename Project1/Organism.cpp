#include "Organism.h"

Organism::Organism(const Vector2& pos, const int priority, const int strength, const char symbol)
	: pos(pos), prevPos(pos), priority(priority), strength(strength), symbol(symbol)
{
}
Organism::~Organism()
{
}

void Organism::SetWorld(World* world)
{
	this->world = world;
}

Vector2 Organism::GetPosition() const
{
	return pos;
}

int Organism::GetPriority() const
{
	return priority;
}

int Organism::GetStrength() const
{
	return strength;
}

void Organism::SetStrength(const int value)
{
	strength = value;
}

bool Organism::IsAlive() const
{
	return isAlive;
}

void Organism::Hit(Organism* attacker)
{
	std::cout << attacker->GetName() << " attacked " << GetName() << " on " << pos << "\n";
	if (attacker->GetStrength() >= GetStrength())
	{
		// attacker wins
		this->Die(attacker);
	}
	else
	{
		// this organism wins
		attacker->Die(this);
	}
}

void Organism::GoBack()
{
	pos = prevPos;
}

void Organism::Draw(char** buffer) const
{
	buffer[pos.x][pos.y] = symbol;
}

void Organism::Die(Organism* killer)
{
	isAlive = false;
	std::cout << GetName() << " was killed by " << killer->GetName() << '\n';
}
