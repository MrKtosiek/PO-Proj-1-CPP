#include "Guarana.h"
#include "World.h"
#include <stdlib.h>

Guarana::Guarana(const Vector2& pos) : Plant(pos, 0, 15, 'g')
{
}

Guarana::~Guarana()
{
}

void Guarana::Hit(Organism* attacker)
{
	attacker->SetStrength(attacker->GetStrength() + 3);
	Plant::Hit(attacker);
	std::cout << GetName() << " made " << attacker->GetName() << " stronger\n";
}

Guarana* Guarana::Clone(const Vector2& pos) const
{
	return new Guarana(pos);
}

std::string Guarana::GetName() const
{
	return "Guarana";
}
