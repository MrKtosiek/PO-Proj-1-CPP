#include "Animal.h"
#include "World.h"
#include <cstdlib>
#include <typeinfo>

Animal::Animal(const Vector2& pos, const int priority, const int strength, const int breedingCooldown, const char symbol)
	: Organism(pos, priority, strength, symbol), breedingCooldown(breedingCooldown)
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
		Breed((Animal*)other);
	}
	else
	{
		// attack the other animal
		std::cout << GetName() << " attacked " << other->GetName() << " on " << pos.x << ',' << pos.y << "\n";
		if (GetStrength() >= other->GetStrength())
		{
			// this organism wins
			other->Die(this);
		}
		else
		{
			// other organism wins
			this->Die(other);
		}
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
		prevPos = pos;
		pos = target;
		std::cout << GetName() << " moved to " << pos.x << ',' << pos.y << '\n';
	}
	else
	{
		std::cout << GetName() << " couldn't move to " << target.x << ',' << target.y << '\n';
	}
}

void Animal::GoBack()
{
	pos = prevPos;
}

void Animal::Breed(Animal* other)
{
	GoBack();
	if (!world->HasEmptyNeighbor(other->GetPosition()))
	{
		std::cout << "Breeding failed on " << pos.x << ',' << pos.y << " (not enough space)\n";
		return;
	}
	if (currentBreedingCooldown > 0 || other->currentBreedingCooldown > 0)
	{
		std::cout << "Breeding failed on " << pos.x << ',' << pos.y << " (cooldown)\n";
		return;
	}

	Vector2 childPos = world->GetEmptyNeighbor(other->GetPosition());
	Animal* child = Clone(childPos);
	world->AddOrganism(child);

	currentBreedingCooldown = breedingCooldown;
	other->currentBreedingCooldown = other->breedingCooldown;
	child->currentBreedingCooldown = child->breedingCooldown;

	std::cout << "Breeding on " << child->pos.x << ',' << child->pos.y << "\n";
}
