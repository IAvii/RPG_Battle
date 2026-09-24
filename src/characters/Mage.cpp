#include "Character.h"
#include "Mage.h"
#include <vector>
#include "Spell.h"
#include <iostream>

using namespace std;


Mage::~Mage() {
  for (Spell* spell : m_spell) {
    delete spell;
  }
  m_spell.clear();

  cout << m_name <<"'s spells have been cleared from memory!" << endl;
}

void Mage::learnSpell(Spell* newspell) {
  if (newspell != nullptr) {
    m_spell.push_back(newspell);
  }
}

void Mage::castSpell(int spellIndex, Character* target) {
  if (spellIndex >=0 && spellIndex < m_spell.size()) {
    
    m_spell[spellIndex]->cast(this, target);

  } else {
    cout << m_name << "doesn't know a spell at that index!" << endl;
  }
}
