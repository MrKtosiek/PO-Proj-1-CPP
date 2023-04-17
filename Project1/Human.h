#pragma once
#include "Animal.h"

class Human : public Animal
{
public:
	Human(const Vector2& pos);
	~Human();

	virtual void Action() override;
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
