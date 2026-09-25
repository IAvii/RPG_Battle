#pragma once
#include <string>

using namespace std;

class Character;

class Item {
  private:
    string m_name;
    int m_quantity;
    bool m_isConsumable;
  public:
    Item(string name, int quantity, bool isConsumable) 
    : m_name(name), m_quantity(quantity), m_isConsumable(isConsumable) {}

    virtual ~Item() = default;

    virtual void use(Character* user) = 0;
    virtual int getAmount() const = 0;

    string getName() const { return m_name; }
    int getQuantity() const { return m_quantity; }
    bool isConsumable() const { return m_isConsumable; }

    void decreaseQuantity() { m_quantity--; }
    void IncreaseQuantity(int amount) { m_quantity += amount; }

};

class HealthPotion: public Item {
  private:
    int m_healAmount;
  public:
    HealthPotion();

    void use(Character* user) override;

    virtual int getAmount() const override;
};

class Sword: public Item {
  private:
    int m_boostAttack;
    bool m_isEquipped;
  public:
    Sword(int boostAttack, bool isEquipped);

    void use(Character* user) override;

    int getAmount() const override;
};