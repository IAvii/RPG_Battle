#include "Character.h"
#include <vector>
#include "Spell.h"
#include <iostream>

using namespace std;

class Mage: public Character {
  private:
    vector<Spell*> m_spell;

  public:
  
    Mage(string charName): Character(charName, 75, 75, 8) {}

    ~Mage() {
      for (Spell* spell : m_spell) {
        delete spell;
      }
      m_spell.clear();

      cout << m_name <<"'s spells have been cleared from memory!" << endl;
    }

    void learnSpell(Spell* newspell) {
      if (newspell != nullptr) {
        m_spell.push_back(newspell);
      }
    }

    void castSpell(int spellIndex, Character* target) {
      if (spellIndex >=0 && spellIndex < m_spell.size()) {
        
        m_spell[spellIndex]->cast(this, target);

      } else {
        cout << m_name << "doesn't know a spell at that index!" << endl;
      }
    }


};