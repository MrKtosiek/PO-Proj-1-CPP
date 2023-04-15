#include "Organism.h"

Organism::Organism(const Vector2& pos, const char symbol)
{
	this->pos = pos;
	this->symbol = symbol;
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

void Organism::Draw(char** buffer) const
{
	buffer[pos.x][pos.y] = symbol;
}

bool Organism::operator<(const Organism& other)
{
	return priority > other.priority;
}
