#include <iostream>
#include "Inventory.h"
using namespace std;


int Character::TotalCharacterCreated = 0;

Character::Character(string charName, int hp, int maxHP, int attackPower)
    : m_name(charName), m_currentHP(hp), m_maxHP(maxHP), m_attackPower(attackPower) {
        TotalCharacterCreated++;
    };
      
int Character::getTotalCharacterCreated() {
    return TotalCharacterCreated;
}

void Character::getStatus() const {
    cout << "Name: " << m_name << " | HP: " << m_currentHP << "/" << m_maxHP << " | ATK: " << m_attackPower << endl;
}
    
void Character::takeDamage(int amount) {
    m_currentHP -=  amount;

    if (m_currentHP < 0) {
        m_currentHP = 0;
    }
}

void Character::heal(int amount) {
    m_currentHP +=  amount;

    if (m_currentHP > m_maxHP) {
        m_currentHP = m_maxHP;
    }
}

bool Character::isAlive() const {
    return m_currentHP > 0;
}

void Character::equipWeapon(int bonusAmount) {
    m_weaponBonus = bonusAmount;
}

void Character::unEquipWeapon() {
    m_weaponBonus = 0;
}

void Character::attack(Character& target) { 
    int totalDamage = m_attackPower + m_weaponBonus;
    target.takeDamage(totalDamage);

    cout << "Enemy smashes you for " << totalDamage <<" damage!" << endl;
}

string Character::getName () const {
    return m_name;
}

int Character::getHP() const {
    return m_currentHP;
}

// Character(string charName)
    //   : m_name(charName),m_currentHP(50),m_maxHP(50),m_attackPower(10) {
    //     TotalCharacterCreated++;
    //   };