#ifndef CREATURE_H
#define CREATURE_H

#include <memory>

class Creature
{
public:

    Creature(int str, int def);
    ~Creature();

    int getStrength() const;
    int getDefense() const;

    Creature* getNext() const;

    void setNext(Creature* nextCreature);

private:

    int strength;
    int defense;
    Creature* next;
};

#endif
