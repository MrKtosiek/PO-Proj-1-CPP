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
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"

using namespace std;



void Program()
{
	World world(10, 10);

	// add the player
	Human* player = new Human({ world.GetSize().x / 2, world.GetSize().y / 2 }); // deallocated by the world object
	world.AddOrganism((Organism*)player);

	// populate the world
	int wolfCount = 0;
	int sheepCount = 5;
	int foxCount = 5;
	int turtleCount = 5;
	int antelopeCount = 5;
	for (int i = 0; i < wolfCount; i++)
	{
		Wolf* newWolf = new Wolf(world.GetRandomEmptyTile());
		world.AddOrganism(newWolf);
	}
	for (int i = 0; i < sheepCount; i++)
	{
		Sheep* newSheep = new Sheep(world.GetRandomEmptyTile());
		world.AddOrganism(newSheep);
	}
	for (int i = 0; i < foxCount; i++)
	{
		Fox* newFox = new Fox(world.GetRandomEmptyTile());
		world.AddOrganism(newFox);
	}
	for (int i = 0; i < turtleCount; i++)
	{
		Turtle* newTurtle = new Turtle(world.GetRandomEmptyTile());
		world.AddOrganism(newTurtle);
	}
	for (int i = 0; i < antelopeCount; i++)
	{
		Antelope* newAntelope = new Antelope(world.GetRandomEmptyTile());
		world.AddOrganism(newAntelope);
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
