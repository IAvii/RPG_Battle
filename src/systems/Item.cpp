#include "Character.h"
#include <iostream>
#include "Item.h"


HealthPotion::HealthPotion()
            :Item("Health Potion", 2, true) {}

void HealthPotion::use(Character* user) {
  std::cout << user->getName() << " drinks a " << getName() << " and restores health!\n";
  user->heal(20);
}

int HealthPotion::getAmount() const {
  return m_healAmount;
}

Sword::Sword(int boostAttack, bool isEquipped)
      :Item("Sword", 1, false),m_boostAttack(boostAttack), m_isEquipped(isEquipped) {}

void Sword::use(Character* user) {
  if (m_isEquipped == false) {
    m_isEquipped = true;
    user->equipWeapon(m_boostAttack);
    cout << "You equipped the Sword! Attack increased."<< endl;
  } else {
    m_isEquipped = false;
    user->unEquipWeapon();
    cout << "You unequipped the Sword! Attack returned to normal."<<endl;
  }
}

int Sword::getAmount() const {
  return m_boostAttack;
}