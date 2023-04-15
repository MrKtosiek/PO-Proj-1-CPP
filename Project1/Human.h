#pragma once
#include "Animal.h"

class Human : Animal
{
public:
	Human(const Vector2& pos);
	~Human();

	void SetNextAction(const char code);

private:
	enum class HumanAction
	{
		NONE,
		UP,
		DOWN,
		LEFT,
		RIGHT,
		ABILITY
	} nextAction = HumanAction::NONE;
};
