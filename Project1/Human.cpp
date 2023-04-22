#include "Human.h"
#include "World.h"
#include <stdlib.h>

Human::Human(const Vector2& pos) : Animal(pos, 4, 5, 10, 'H')
{
}

Human::~Human()
{
}

void Human::Movement()
{
	if (nextAction == HumanAction::NONE)
		return;

	Vector2 target = pos;
	
	if (nextAction == HumanAction::UP)
		target = { pos.x - 1, pos.y };
	if (nextAction == HumanAction::DOWN)
		target = { pos.x + 1, pos.y };
	if (nextAction == HumanAction::LEFT)
		target = { pos.x, pos.y - 1 };
	if (nextAction == HumanAction::RIGHT)
		target = { pos.x, pos.y + 1 };

	MoveTo(target);
}

Human* Human::Clone(const Vector2& pos) const
{
	return new Human(pos);
}

void Human::SetNextAction(char code)
{
	switch (code)
	{
	case 'w':
		nextAction = HumanAction::UP;
		break;
	case 's':
		nextAction = HumanAction::DOWN;
		break;
	case 'a':
		nextAction = HumanAction::LEFT;
		break;
	case 'd':
		nextAction = HumanAction::RIGHT;
		break;
	case 'e':
		nextAction = HumanAction::ABILITY;
		break;
	default:
		nextAction = HumanAction::NONE;
		break;
	}
}

std::string Human::GetName() const
{
	return "Human";
}

void Human::Die(Organism* killer)
{
	world->SetPlayerAlive(false);
	Animal::Die(killer);
}
