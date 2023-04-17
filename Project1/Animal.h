#pragma once
#include "Organism.h"

class Animal : public Organism
{
public:
	Animal(const Vector2& pos, const char symbol);

	virtual void Action() override;
	virtual void Attack(Organism* other) override;
	virtual void MoveTo(const Vector2& target);

protected:
	int breedingCooldown = 5;
	int currentBreedingCooldown = 0;
};
