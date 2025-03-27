#include "Creature.h"

Creature::Creature(int str, int def) : strength(str), defense(def), next(nullptr) {}

Creature::~Creature(){}

int Creature::getStrength() const
{
    return strength;
}

int Creature::getDefense() const
{
    return defense;
}

Creature* Creature::getNext() const
{
    return next;
}

void Creature::setNext(Creature* nextCreature)
{
    next = nextCreature;
}
