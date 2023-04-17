#include <conio.h>
#include "World.h"
#include "Human.h"

World::World() : World::World(15, 15)
{
}
World::World(int height, int width)
{
	size = { height, width };
}
World::~World()
{
	for (size_t i = 0; i < organisms.size(); i++)
		delete organisms[i];
}

void World::AddOrganism(Organism* org)
{
	org->SetWorld(this);
	organisms.push_back(org);
}

void World::GenerateOrganisms()
{
	for (int i = 0; i < 3; i++)
	{
		Human* newHuman = new Human(GetRandomEmptyTile());
		AddOrganism(newHuman);
	}
}

Organism* World::GetOrganism(const Vector2& pos) const
{
	for (size_t i = 0; i < organisms.size(); i++)
	{
		if (pos == organisms[i]->GetPosition())
			return organisms[i];
	}
	return nullptr;
}

const Vector2& World::GetSize() const
{
	return size;
}

bool World::ContainsPos(Vector2 pos) const
{
	return
		pos.x >= 0 && pos.x < size.x&&
		pos.y >= 0 && pos.y < size.y;
}

Vector2 World::GetRandomEmptyTile() const
{
	Vector2 pos = {};

	const int safetyLimit = 1000;
	for (int i = 0; i < safetyLimit; i++)
	{
		pos.x = rand() % size.x;
		pos.y = rand() % size.y;
		// if there is no organism on the chosen tile, return the position
		if (GetOrganism(pos) == nullptr)
			break;
	}

	return pos;
}

void World::ExecuteTurn()
{
	// order organisms by their priority
	std::sort(organisms.begin(), organisms.end());

	// execute actions
	for (Organism* org : organisms)
	{
		org->Action();
		
		// handle collisions
		for (Organism* other : organisms)
		{
			if (org != other && org->GetPosition() == other->GetPosition())
			{
				org->Attack(other);
			}
		}
	}
}

void World::DrawWorld()
{
	// create a buffer for the drawing
	char** buffer = new char* [size.x];
	for (int x = 0; x < size.x; x++)
	{
		buffer[x] = new char[size.y + 1]();
		for (int y = 0; y < size.y; y++)
			buffer[x][y] = ' ';
	}

	// draw all organisms
	for (Organism* org : organisms)
	{
		org->Draw(buffer);
	}

	// draw the horizontal part of the frame
	_putch('#');
	for (int y = 0; y < size.y; y++)
		_putch('-');
	_cputs("#\n");

	// draw the buffer on the console
	for (int x = 0; x < size.x; x++)
	{
		_putch('|'); // vertical line
		_cputs(buffer[x]);
		_cputs("|\n"); // vertical line
	}

	// draw the horizontal part of the frame
	_putch('#');
	for (int y = 0; y < size.y; y++)
		_putch('-');
	_cputs("#\n");

	// deallocate the buffer
	for (int x = 0; x < size.x; x++)
		delete[] buffer[x];
	delete[] buffer;
}
