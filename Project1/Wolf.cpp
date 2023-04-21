#include "Wolf.h"
#include "World.h"
#include <stdlib.h>

Wolf::Wolf(const Vector2& pos) : Animal(pos, 5, 9, 'W')
{
}

Wolf::~Wolf()
{
}

std::string Wolf::GetName() const
{
	return "Wolf";
}
