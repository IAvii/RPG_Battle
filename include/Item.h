#include "Character.h"

class Item {
  public:
    virtual void use(Character* user) = 0;
    virtual string getName() const = 0;
    virtual int getAmount() const = 0;

    virtual ~Item() = default;
};

class HealthPotion: public Item {
  private:
    string m_name;
    int m_healAmount;
  public:
    void use(Character* user) override;

    string getName() const override;

    virtual int getAmount() const;
};