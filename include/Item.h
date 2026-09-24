#pragma once

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
    void use(Character* user) override;

    string getName() const override;

    virtual int getAmount() const;
};

class Sword: public Item {
  private:
    string m_name = "Sword";
    int m_boostAttack = 10;
    bool m_isEquipped = false;
    int m_quantity = 1;
  public:

    void use(Character* user) override;

    string getName() const override;

    int getAmount() const override;
};