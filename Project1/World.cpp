#include <conio.h>
#include "World.h"
#include "Wolf.h"
#include "Sheep.h"
#include <iostream>

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
		Wolf* newWolf = new Wolf(GetRandomEmptyTile());
		AddOrganism(newWolf);
		Sheep* newSheep = new Sheep(GetRandomEmptyTile());
		AddOrganism(newSheep);
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

bool World::HasEmptyNeighbor(const Vector2 pos) const
{
	for (size_t i = 0; i < 4; i++)
	{
		Vector2 n = pos.GetNeighbor(i);
		if (ContainsPos(n) && GetOrganism(n) == nullptr)
			return true;
	}
	return false;
}

Vector2 World::GetEmptyNeighbor(const Vector2 pos) const
{
	std::vector<Vector2> targets;
	for (size_t i = 0; i < 4; i++)
	{
		Vector2 n = pos.GetNeighbor(i);
		if (ContainsPos(n) && GetOrganism(n) == nullptr)
			targets.push_back(n);
	}

	if (targets.size() > 0)
		return targets[rand() % targets.size()];
	else
		return { -1,-1 };
}

void World::ExecuteTurn()
{
	// order organisms by their priority
	struct ComparePriorities
	{
		bool operator() (const Organism* org1, const Organism* org2)
		{
			return (org1->GetPriority() > org2->GetPriority());
		}
	};
	std::sort(organisms.begin(), organisms.end(), ComparePriorities());


	// execute actions
	size_t orgCount = organisms.size();
	for (size_t i = 0; i < orgCount; i++)
	{
		std::cout << i + 1 << ". ";
		organisms[i]->Action();
		
		// handle collisions
		for (size_t j = 0; j < organisms.size(); j++)
		{
			if (i != j && organisms[i]->GetPosition() == organisms[j]->GetPosition())
			{
				organisms[i]->Collide(organisms[j]);
			}
		}
	}

	std::cout << "Turn " << ++turnNumber << " finished\n";
}

void World::DrawWorld()
{
	// create a buffer for the drawing
	char** buffer = new char* [size.x];
	int** density = new int* [size.x];
	for (int x = 0; x < size.x; x++)
	{
		buffer[x] = new char[size.y + 1]();
		density[x] = new int[size.y + 1]();
		for (int y = 0; y < size.y; y++)
		{
			buffer[x][y] = ' ';
			density[x][y] = 0;
		}
	}

	// draw all organisms
	for (Organism* org : organisms)
	{
		org->Draw(buffer);
		density[org->GetPosition().x][org->GetPosition().y]++;
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
		for (int y = 0; y < size.y; y++)
		{
			if (density[x][y] > 1)
				_putch(density[x][y] + '0');
			else
				_putch(' ');
		}
		_cputs("|\n"); // vertical line
	}

	// draw the horizontal part of the frame
	_putch('#');
	for (int y = 0; y < size.y; y++)
		_putch('-');
	_cputs("#\n");

	// deallocate the buffer
	for (int x = 0; x < size.x; x++)
	{
		delete[] buffer[x];
		delete[] density[x];
	}
	delete[] buffer;
	delete[] density;
}
