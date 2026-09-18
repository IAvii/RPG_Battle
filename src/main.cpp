#include <iostream>
#include "Character.h"
#include "Goblin.h"

using namespace std;

int main() {
    Character hero("Aurther", 100, 100, 15);
    Goblin goblin;

    while(hero.isAlive() && goblin.isAlive()) {
        cout << "\n=======================================\n";
        hero.getStatus(); cout <<endl;
        goblin.getStatus(); cout <<endl;
        cout << "=======================================\n";

        cout << "1. Attack \n";
        cout << "2. Flee (Pass turn)\n";
        cout << "Choose your action";

        int choice;
        cin >> choice;
        cout << endl;

        switch(choice) {
            case 1:
                hero.attack(goblin);
                break;
            case 2:
                cout << hero.getName() << " hesitates in fear!!" << endl;
                break;
            default:
                cout << "Wrong option chosen" << endl;
        }

        if (goblin.isAlive()) {
            goblin.attack(hero);
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

    
    return 0;
}
