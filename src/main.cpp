#include <iostream>
#include <vector>
#include "Character.h"
#include "Enemy.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    Character hero("Aurther", 100, 100, 15);

    vector<Character*> enemyPool;
    enemyPool.push_back(new Goblin());
    enemyPool.push_back(new Orc());

    int randomIndex = rand() % enemyPool.size();

    Character* activeEnemy = enemyPool[randomIndex];



    while(hero.isAlive() && activeEnemy->isAlive()) {
        cout << "\n=======================================\n";
        hero.getStatus(); cout <<endl;
        activeEnemy->getStatus(); cout <<endl;
        cout << "=======================================\n";

        cout << "1. Attack \n";
        cout << "2. Flee (Pass turn)\n";
        cout << "Choose your action";

        int choice;
        cin >> choice;
        cout << endl;

        switch(choice) {
            case 1:
                hero.attack(*activeEnemy);
                break;
            case 2:
                cout << hero.getName() << " hesitates in fear!!" << endl;
                break;
            default:
                cout << "Wrong option chosen" << endl;
        }

        if (activeEnemy->isAlive()) {
            activeEnemy->attack(hero);
        } else {
            cout << "The Goblin collapses before it can strike back!!" << endl;
        }
    }

    cout << "\n========================================\n";
    cout << "               BATTLE OVER              \n";
    cout << "========================================\n";

    if (hero.isAlive()) {
        cout << "Victory!!" << hero.getName() << " defeated the Goblin\n";
    } else {
        cout << "💀 Defeat... The Goblin overwhelmed " << hero.getName() << ".\n";
    }

    delete enemyPool[0];
    delete enemyPool[1];

    
    return 0;
}
