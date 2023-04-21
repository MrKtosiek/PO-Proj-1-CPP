#include "Sheep.h"
#include "World.h"
#include <stdlib.h>

Sheep::Sheep(const Vector2& pos) : Animal(pos, 4, 4, 'S')
{
}

Sheep::~Sheep()
{
}

std::string Sheep::GetName() const
{
	return "Sheep";
}
