#pragma once

#include "Character.h"
#include <vector>
#include "Spell.h"

using namespace std;

class Mage: public Character {
  private:
    vector<Spell*> m_spell;

  public:
  
    Mage(): Character("Mage", 75, 75, 8) {};

    ~Mage();

    void learnSpell(Spell* newspell);

    void castSpell(int spellIndex, Character* target);

};