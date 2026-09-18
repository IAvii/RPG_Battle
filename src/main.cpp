#include <iostream>
#include "Character.h"
#include "Goblin.h"

using namespace std;

int main() {
    Character hero("Hero", 100, 100, 15);

    hero.getStatus();
    
    return 0;
}
