#ifndef COMMANDER_H
#define COMMANDER_H

#include "Creature.h"

class Commander
{
private:

    int hitPoints;

    Creature* firstCreature;
    Creature* deepCopyCreatureChain(const Creature* creature);

public:

    Commander();
    ~Commander();

    void addCreature(const Creature& creature);
    void battle(Commander& other);

    int getHitPoints() const;
    bool isAlive() const;
};

#endif
