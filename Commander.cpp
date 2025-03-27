#include "Commander.h"
#include <iostream>

using namespace std;

Commander::Commander() : hitPoints(40), firstCreature(nullptr) {}

Commander::~Commander()
{
    while (firstCreature)
    {
        Creature* temp = firstCreature;
        firstCreature = firstCreature->getNext();
        delete temp;
    }
}

Creature* Commander::deepCopyCreatureChain(const Creature* creature)
{
    if (!creature) return nullptr;

    Creature* newCreature = new Creature(creature->getStrength(), creature->getDefense());
    newCreature->setNext(deepCopyCreatureChain(creature->getNext()));

    return newCreature;
}

void Commander::addCreature(const Creature& creature)
{
    Creature* newCreature = deepCopyCreatureChain(&creature);

    if (!firstCreature || firstCreature->getDefense() < newCreature->getDefense() ||
        (firstCreature->getDefense() == newCreature->getDefense() && firstCreature->getStrength() < newCreature->getStrength()))
    {
        newCreature->setNext(firstCreature);
        firstCreature = newCreature;
    }
    else
    {
        Creature* current = firstCreature;

        while (current->getNext() && (current->getNext()->getDefense() > newCreature->getDefense() ||
            (current->getNext()->getDefense() == newCreature->getDefense() && current->getNext()->getStrength() > newCreature->getStrength())))
        {
            current = current->getNext();
        }
        newCreature->setNext(current->getNext());
        current->setNext(newCreature);
    }
}

void Commander::battle(Commander& other)
{
    Creature* current1 = firstCreature;
    Creature* current2 = other.firstCreature;

    while (current1 && current2)
    {
        int damage1 = current1->getStrength();
        int damage2 = current2->getStrength();

        cout << "Creature 1 deals " << damage1 << " damage to Creature 2" << endl;
        cout << "Creature 2 deals " << damage2 << " damage to Creature 1" << endl;

        bool creature1Dies = (damage2 >= current1->getDefense());
        bool creature2Dies = (damage1 >= current2->getDefense());

        if (creature1Dies)
        {
            Creature* temp = current1;
            current1 = current1->getNext();
            delete temp;
        }

        if (creature2Dies)
        {
            Creature* temp = current2;
            current2 = current2->getNext();
            delete temp;
        }

        if (!creature1Dies && !creature2Dies)
        {
            break;
        }
    }

    firstCreature = current1;
    other.firstCreature = current2;

    if (!current1 && current2)
    {
        hitPoints -= current2->getStrength();
        cout << "Commander 1 takes " << current2->getStrength() << " damage" << endl;
    }
    else if (current1 && !current2)
    {
        other.hitPoints -= current1->getStrength();
        cout << "Commander 2 takes " << current1->getStrength() << " damage" << endl;
    }
}

int Commander::getHitPoints() const
{
    return hitPoints;
}

bool Commander::isAlive() const
{
    return hitPoints > 0;
}

