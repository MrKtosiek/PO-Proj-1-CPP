#pragma once
#include <string>
#include "Vector2.h"
//#include "World.h"
class World;

class Organism
{
public:
	Organism(const Vector2& pos, const int priority, const int strength, const char symbol);
	virtual ~Organism();

	virtual void SetWorld(World* world);
	virtual Vector2 GetPosition() const;
	virtual int GetPriority() const;

	virtual void Action() = 0;
	virtual void Collide(Organism* other) = 0;

	virtual void Draw(char** buffer) const;
	virtual std::string GetName() const = 0;

protected:
	Vector2 pos = { 0,0 };
	int priority = 0;
	int strength = 0;
	char symbol = '%';
	World* world = nullptr;
};
