#pragma once
#include "Vector2.h"
//#include "World.h"
class World;

class Organism
{
public:
	Organism(const Vector2& pos, const char symbol);
	virtual ~Organism();

	virtual void SetWorld(World* world);
	virtual Vector2 GetPosition() const;

	virtual void Action() = 0;
	virtual void Attack(Organism* other) = 0;

	virtual void Draw(char** buffer) const;

	bool operator<(const Organism& other);

protected:
	Vector2 pos = { 0,0 };
	int priority = 0;
	char symbol = '%';
	World* world = nullptr;
};
