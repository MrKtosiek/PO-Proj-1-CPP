#include <conio.h>
#include <iostream>

#include "World.h"
#include "Human.h"
#include "Animal.h"
#include "Plant.h"

#include <crtdbg.h>

using namespace std;



void Program()
{
	World world;

	Human* player = new Human({ world.GetSize().x / 2, world.GetSize().y / 2 }); // deallocated by the world object
	world.AddOrganism((Organism*)player);

	char input = 0;
	while (input != 'q')
	{
		input = _getch();

		player->SetNextAction(input);

		world.ExecuteTurn();
		world.DrawWorld();
	}
}

int main()
{
	Program();
	_CrtDumpMemoryLeaks();
	return 0;
}
