#include "Animal.h"
#include "World.h"
#include <cstdlib>
#include <typeinfo>
#include <iostream>

Animal::Animal(const Vector2& pos, const int priority, const int strength, const char symbol) : Organism(pos, priority, strength, symbol)
{
}

void Animal::Action()
{
	Movement();

	currentBreedingCooldown--;
}

void Animal::Collide(Organism* other)
{
	std::cout << "Collision on " << pos.x << ',' << pos.y << " (" << GetName() << ", " << other->GetName() << ")\n";
	if (GetName() == other->GetName())
	{
		// breed the animals
		std::cout << "Breeding on " << pos.x << ',' << pos.y << '\n';
	}
	else
	{
		// attack the other animal

	}
}

void Animal::Movement()
{
	MoveTo(pos.GetNeighbor(rand() % 4));
}

void Animal::MoveTo(const Vector2& target)
{
	if (world->ContainsPos(target))
	{
		pos = target;
		std::cout << GetName() << " moved to " << pos.x << ',' << pos.y << '\n';
	}
	else
	{
		std::cout << GetName() << " couldn't move to " << target.x << ',' << target.y << '\n';
	}
}
