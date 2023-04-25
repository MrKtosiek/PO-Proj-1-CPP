#include <conio.h>
#include <stdlib.h>
#include <iostream>

#include "Game.h"

int main()
{
	srand(time(nullptr));

	Game game(20, 20);

	char input = 0;
	while (input != 'q')
	{
		input = _getch();

		switch (input)
		{
		case 'c':
			game.SaveWorld();
			break;
		case 'v':
			game.LoadWorld();
			break;
		case 'q':
			break;
		default:
			game.SimulateWorld(input);
			break;
		}
	}

	return 0;
}
