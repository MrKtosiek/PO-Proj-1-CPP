#include <conio.h>
#include "Human.h"
#include <stdlib.h>

Human::Human(const Vector2& pos) : Animal(pos, 'H')
{
}

Human::~Human()
{
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
		break;
	}
}
