#pragma once
#include <vector>
#include <algorithm>
#include "Vector2.h"
#include "Organism.h"
//class Organism;

class World
{
public:
	World();
	World(int height, int width);
	~World();

	void AddOrganism(Organism* org);
	void RemoveOrganism(Organism* org);
	Organism* GetOrganism(const Vector2& pos) const;
	const Vector2& GetSize() const;

	bool IsPlayerAlive() const;
	void SetPlayerAlive(const bool& value);

	bool ContainsPos(Vector2 pos) const;
	Vector2 GetRandomEmptyTile() const;
	bool HasEmptyNeighbor(const Vector2 pos) const;
	Vector2 GetEmptyNeighbor(const Vector2 pos) const;

	void ExecuteTurn();
	void DrawWorld();

private:
	Vector2 size;
	std::vector<Organism*> organisms;
	size_t turnNumber = 0;
	bool playerAlive = true;
};
