#include <conio.h>
#include <stdlib.h>
#include <iostream>

#include "World.h"
#include "Human.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Animal.h"
#include "Plant.h"

#include <crtdbg.h>

using namespace std;



void Program()
{
	World world(10, 10);

	// add the player
	Human* player = new Human({ world.GetSize().x / 2, world.GetSize().y / 2 }); // deallocated by the world object
	world.AddOrganism((Organism*)player);

	// populate the world
	for (int i = 0; i < 2; i++)
	{
		Wolf* newWolf = new Wolf(world.GetRandomEmptyTile());
		world.AddOrganism(newWolf);
	}
	for (int i = 0; i < 15; i++)
	{
		Sheep* newSheep = new Sheep(world.GetRandomEmptyTile());
		world.AddOrganism(newSheep);
	}


	world.DrawWorld();

	char input = 0;
	while (input != 'q')
	{
		input = _getch();

		if (world.IsPlayerAlive())
			player->SetNextAction(input);

		//system("cls"); // clear the screen
		world.ExecuteTurn();
		world.DrawWorld();
	}
}

int main()
{
	srand(time(nullptr));
	Program();
	_CrtDumpMemoryLeaks();
	return 0;
}
