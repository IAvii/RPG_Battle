#include <iostream>
#include "Character.h"



class Item {
  protected:
    int m_quantity;
  public:
    virtual void use(Character* user) = 0;
    virtual string getName() const = 0;
    virtual int getAmount() const = 0;

    virtual ~Item() = default;
};

class HealthPotion: public Item {
  private:
    string m_name = "HealthPotion";
    int m_healAmount = 25;
    int m_quantity = 5;
  public:
    void use(Character* user) override {
      if (m_quantity > 0) {
        m_quantity--;
        user->heal(m_healAmount);
        std::cout << "Your HP increased to " << user->getHP() << endl;
      } else {
        std::cout << "You have no health Potion left!" << endl;
      }
    }

    string getName() const override {
      return m_name;
    }

    int getAmount() const override {
      return m_healAmount;
    }
};

class Sword: public Item {
  private:
    string m_name = "Sword";
    int m_boostAttack = 10;
    bool m_isEquipped = false;
    int m_quantity = 1;
  public:

    void use(Character* user) override {
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

    string getName() const override {
      return m_name;
    }

    int getAmount() const override {
      return m_boostAttack;
    }
};