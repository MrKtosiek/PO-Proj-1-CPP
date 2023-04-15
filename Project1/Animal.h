#pragma once
#include "Organism.h"

class Animal : Organism
{
public:
	Animal(const Vector2& pos, const char symbol);

	virtual void Action() override;
	virtual void Collision(Organism* other) override;

private:
	int breedingCooldown = 5;
	int currentBreedingCooldown = 0;
};
