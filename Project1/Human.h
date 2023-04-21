#pragma once
#include <string>
#include "Animal.h"

class Human : public Animal
{
public:
	Human(const Vector2& pos);
	~Human();

	virtual void Movement() override;
	void SetNextAction(const char code);

	std::string GetName() const;

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
