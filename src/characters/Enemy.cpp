#include "Enemy.h"
#include <iostream>

using namespace std;

void Goblin::attack(Character& target)
{
    target.takeDamage(m_attackPower);

    cout << "The Goblin smashes you for "
         << m_attackPower
         << " damage!" << endl;
}

void Orc::attack(Character& target)
{
    target.takeDamage(m_attackPower);

    cout << "The Orc smashes you for "
         << m_attackPower
         << " damage!" << endl;
}