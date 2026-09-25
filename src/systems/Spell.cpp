#include "Character.h"
#include <iostream>
#include "Spell.h"



void Fireball::cast(Character* caster, Character* target) {
  int fireballDamageAmount = 16;
  target->takeDamage(fireballDamageAmount);

  std::cout << caster->getName() <<" casts Fireball on "<< target->getName() <<" for 25 damage!"<< endl;
}

void Heal::cast(Character* caster, Character* target) {
  int healAmount = 25;
  caster->heal(healAmount);

  std::cout << caster->getName() <<" healed themselves for " << healAmount << " HP!"<< endl;
}
