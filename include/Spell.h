#pragma once
#include <iostream>

class Character;

class Spell {
  public:
    virtual void cast(Character* caster, Character* target) = 0;

    virtual ~Spell() = default;
};

class Fireball : public Spell {
  public:
    void cast(Character* caster, Character* target) override;
};

class Heal : public Spell {
  public:
    void cast(Character* caster, Character* target) override;
};