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

void Organism::Draw(char** buffer) const
{
	buffer[pos.x][pos.y] = symbol;
}
