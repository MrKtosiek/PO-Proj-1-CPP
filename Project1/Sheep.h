#pragma once
#include "Animal.h"

class Sheep : public Animal
{
public:
	Sheep(const Vector2& pos);
	~Sheep();

	std::string GetName() const;

private:

};
