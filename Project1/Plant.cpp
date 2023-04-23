#include "Plant.h"
#include "World.h"
#include <cstdlib>
#include <typeinfo>

Plant::Plant(const Vector2& pos, const int strength, const int growChance, const char symbol)
	: Organism(pos, 0, strength, symbol), growChance(growChance)
{
}

void Plant::Action()
{
	if (rand() % 100 < growChance)
	{
		Grow();
	}
	else
	{
		std::cout << GetName() << " didn't grow\n";
	}
}

void Plant::Collide(Organism* other)
{
}

void Plant::Grow() const
{
	if (world->HasEmptyNeighbor(pos))
	{
		Vector2 childPos = world->GetEmptyNeighbor(pos);
		Plant* child = Clone(childPos);
		world->AddOrganism(child);
		std::cout << GetName() << " spread onto " << childPos << "\n";
	}
	else
	{
		std::cout << GetName() << " couldn't spread on " << pos << " (not enough space)\n";
	}
}
