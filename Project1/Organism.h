#pragma once
#include <iostream>
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
	virtual int GetStrength() const;
	virtual bool IsAlive() const;

	virtual void Action() = 0;
	virtual void Collide(Organism* other) = 0;

	virtual void Draw(char** buffer) const;
	virtual std::string GetName() const = 0;
	virtual Organism* Clone(const Vector2& pos) const = 0;
	virtual void Die(Organism* killer);

protected:
	Vector2 pos = { 0,0 };
	Vector2 prevPos = { 0,0 };
	int priority = 0;
	int strength = 0;
	char symbol = '%';
	bool isAlive = true;
	World* world = nullptr;
};
