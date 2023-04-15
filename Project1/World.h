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
	World(int width, int height);
	~World();

	void AddOrganism(Organism* org);
	Organism* GetOrganism(const Vector2& pos);
	const Vector2& GetSize() const;

	bool ContainsPos(Vector2 pos) const;

	void ExecuteTurn();
	void DrawWorld();

private:
	Vector2 size;
	std::vector<Organism*> organisms;
};
