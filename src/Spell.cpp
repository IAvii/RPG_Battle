#include "Character.h"
#include <iostream>

class Spell {
  public:
    virtual void cast(Character* caster, Character* target) = 0;

    virtual ~Spell() = default;
};

class Fireball : public Spell {
  public:
    void cast(Character* caster, Character* target) override {
      int fireballDamageAmount = 25;
      target->takeDamage(fireballDamageAmount);

      std::cout << caster->getName() <<" casts Fireball on "<< target->getName() <<" for 25 damage!"<< endl;
    }
};

class Heal : public Spell {
  public:
    void cast(Character* caster, Character* target) override {
      int healAmount = 25;
      caster->heal(healAmount);

      std::cout << caster->getName() <<" healed themselves for " << healAmount << " HP!"<< endl;
    }
};