#include <iostream>
using namespace std;



class Character {
  protected:
    string m_name;
    int m_currentHP;
    int m_maxHP;
    int m_attackPower;
    int m_weaponBonus = 0;

    static int TotalCharacterCreated;
  public:
    Character(string charName, int hp, int maxHP, int attackPower)
      : m_name(charName), m_currentHP(hp), m_maxHP(maxHP), m_attackPower(attackPower) {
          TotalCharacterCreated++;
      };
      
    // Character(string charName)
    //   : m_name(charName),m_currentHP(50),m_maxHP(50),m_attackPower(10) {
    //     TotalCharacterCreated++;
    //   };


    static int getTotalCharacterCreated() {
      return TotalCharacterCreated;
    }

    void getStatus() const {
      cout << "Name: " << m_name << " | HP: " << m_currentHP << "/" << m_maxHP << " | ATK: " << m_attackPower << endl;
    }
        
    void takeDamage(int amount) {
        m_currentHP -=  amount;

        if (m_currentHP < 0) {
            m_currentHP = 0;
        }
    }

    void heal(int amount) {
      m_currentHP +=  amount;

      if (m_currentHP > m_maxHP) {
          m_currentHP = m_maxHP;
      }
    }

    bool isAlive() const {
        return m_currentHP > 0;
    }

    void equipWeapon(int bonusAmount) {
      m_weaponBonus = bonusAmount;
    }

    void unEquipWeapon() {
      m_weaponBonus = 0;
    }

    virtual void attack(Character& target) { 
      int totalDamage = m_attackPower + m_weaponBonus;
      target.takeDamage(totalDamage);

      cout << "Enemy smashes you for " << totalDamage <<" damage!" << endl;
    }

    string getName () const {
        return m_name;
    }
    
    int getHP() const {
        return m_currentHP;
    }
};

int Character::TotalCharacterCreated = 0;