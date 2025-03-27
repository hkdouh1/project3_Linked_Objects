#include <iostream>
#include "Commander.h"
using namespace std;

int main() 
{
    Commander commander1;
    Commander commander2;

    commander1.addCreature(Creature(10, 5));
    commander1.addCreature(Creature(8, 7));
    commander1.addCreature(Creature(12, 6));

    commander2.addCreature(Creature(9, 8));
    commander2.addCreature(Creature(11, 4));


    cout << "Starting battle..." << endl;

    while (commander1.isAlive() && commander2.isAlive()) 
    {
        commander1.battle(commander2);

        cout << "Commander 1 HP: " << commander1.getHitPoints() << endl;
        cout << "Commander 2 HP: " << commander2.getHitPoints() << endl;
    }

    if (!commander1.isAlive()) 
    {
        cout << "Commander 2 wins!" << endl;;
    }
    else {
        cout << "Commander 1 wins!" << endl;;
    }

    return 0;
}