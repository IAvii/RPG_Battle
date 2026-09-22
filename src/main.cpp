#include <iostream>
#include <vector>
#include "Character.h"
#include "Enemy.h"
#include "Mage.h"
#include "Spell.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    cout << "Choose your class:\n1. Mage\n2. Warrior\n";
    int classChoice;
    cin >> classChoice;

    Character* hero = nullptr;

    if (classChoice == 1) {
        Mage* mageHero = new Mage("Aurther the Wise");
        mageHero->learnSpell(new Fireball());
        mageHero->learnSpell(new Heal());
        
        hero = mageHero;
        cout << "You chose the path of Magic!\n";
    } else {
        hero = new Character("Aurther the Brave", 120, 120, 15);
        cout << "You chose the path of Steel!\n";
    }

    vector<Character*> enemyPool;
    enemyPool.push_back(new Goblin());
    enemyPool.push_back(new Orc());

    int randomIndex = rand() % enemyPool.size();

    Character* activeEnemy = enemyPool[randomIndex];



    while(hero->isAlive() && activeEnemy->isAlive()) {
        cout << "\n=======================================\n";
        hero->getStatus(); cout <<endl;
        activeEnemy->getStatus(); cout <<endl;
        cout << "=======================================\n";

        Mage* mageCheck = dynamic_cast<Mage*>(hero);


        cout << "1. Attack \n";

        if (mageCheck != nullptr) {
            cout << "2. Cast Spell \n";
            cout << "3. Flee (Pass turn) \n";
        } else {
            cout << "2. Flee (Pass turn)\n";
        }
        cout << "Choose your action";

        int choice;
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            hero->attack(*activeEnemy);
        }
        else if (choice == 2 && mageCheck != nullptr) {
            cout << "Availabe Spells:\n0. Fireball\n1. Heal\n Choose a Spell index:";
            int spellChoice;
            cin >> spellChoice; 
            cout << endl;

            mageCheck->castSpell(spellChoice, activeEnemy);
        }
        else if ((choice == 3 && mageCheck != nullptr) || (choice == 2 && mageCheck == nullptr)) {
            cout << hero->getName() << " hesitates in fear!!" << endl;
        } else{
            cout << "wrong option chosen" << endl;
        }


        if (activeEnemy->isAlive()) {
            activeEnemy->attack(*hero);
        } else {
            cout << "The " << activeEnemy->getName() <<" collapses before it can strike back!!" << endl;
        }
    }

    cout << "\n========================================\n";
    cout << "               BATTLE OVER              \n";
    cout << "========================================\n";

    if (hero->isAlive()) {
        cout << "Victory!!" << hero->getName() << " defeated the " << activeEnemy->getName() << " \n";
    } else {
        cout << "💀 Defeat... The " << activeEnemy->getName() << " overwhelmed " << hero->getName() << ".\n";
    }

    delete enemyPool[0];
    delete enemyPool[1];

    delete hero;

    return 0;
}
