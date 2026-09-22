#include "Character.h"
#include <iostream>

using namespace std;

class Goblin: public Character {

    public:
        Goblin(): Character("Goblin", 45, 45, 8) {};

        void attack(Character& target) {
            target.takeDamage(m_attackPower);

            cout << "The Orc smashes you for 5 damage!" << endl;
        }

};

class Orc: public Character {
    public:
        Orc(): Character("Orc", 100, 100, 12) {};

        void attack(Character& target) {
            target.takeDamage(m_attackPower);

            cout << "The Orc smashes you for 12 damage!" << endl;
        }

};