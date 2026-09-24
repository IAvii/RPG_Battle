#include <iostream>
#include "Character.h"
#include "Item.h"

void HealthPotion::use(Character* user) {
  if (m_quantity > 0) {
    m_quantity--;
    user->heal(m_healAmount);
    std::cout << "Your HP increased to " << user->getHP() << endl;
  } else {
    std::cout << "You have no health Potion left!" << endl;
  }
}

string HealthPotion::getName() const {
  return m_name;
}

int HealthPotion::getAmount() const {
  return m_healAmount;
}


void Sword::use(Character* user) {
  if (m_isEquipped && m_quantity == 1) {
    m_isEquipped = false;
    user->equipWeapon(m_boostAttack);
    cout << "You equipped the Sword! Attack increased."<< endl;
  } else {
    m_isEquipped = false;
    user->unEquipWeapon();
    cout << "You unequipped the Sword! Attack returned to normal."<<endl;
  }
}

string Sword::getName() const {
  return m_name;
}

int Sword::getAmount() const {
  return m_boostAttack;
}