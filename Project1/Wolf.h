#pragma once
#include "Animal.h"

class Wolf : public Animal
{
public:
	Wolf(const Vector2& pos);
	~Wolf();

	std::string GetName() const;

private:

};
