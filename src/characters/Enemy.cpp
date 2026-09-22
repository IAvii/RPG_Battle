#include "Character.h"
#include <iostream>

using namespace std;

class Goblin: public Character {

    public:
        Goblin(): Character("Goblin", 30, 30, 5) {};

        void attack(Character& target) {
            target.takeDamage(m_attackPower);

            cout << "The Orc smashes you for 5 damage!" << endl;
        }

};

class Orc: public Character {
    public:
        Orc(): Character("Orc", 60, 60, 12) {};

        void attack(Character& target) {
            target.takeDamage(m_attackPower);

            cout << "The Orc smashes you for 12 damage!" << endl;
        }

};