#include "Animal.h"
#include "World.h"
#include <cstdlib>
#include <typeinfo>
#include <iostream>

Animal::Animal(const Vector2& pos, const char symbol) : Organism(pos, symbol)
{
}

void Animal::Action()
{
	// move the animal
	const size_t safetyLimit = 10;
	for (size_t i = 0; i < safetyLimit; i++)
	{
		Vector2 target = pos.GetNeighbor(std::rand() % 4);
		if (world->ContainsPos(target))
		{
			pos = target;
			break;
		}
	}


	currentBreedingCooldown--;
}

void Animal::Collision(Organism* other)
{
	if (typeid(this) == typeid(other))
	{
		// breed the animals
		std::cout << "Breeding on " << pos.x << ',' << pos.y;
	}
}
