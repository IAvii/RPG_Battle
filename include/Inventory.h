#pragma once

#include "Item.h"
#include <vector>
#include <memory>

class Character;

class Inventory {
  private:
    vector<unique_ptr<Item>> m_items;

  public:
    void addItem(unique_ptr<Item> newItem);

    void useItem(int index, Character* user);

    void listItem() const;
};