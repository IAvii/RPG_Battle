#include "Item.h"
#include "Inventory.h"
#include <vector>
#include <iostream>
#include <memory>

using namespace std;


void Inventory::addItem(unique_ptr<Item> newItem) {
  m_items.push_back(move(newItem));
}

void Inventory::useItem(int index, Character* user) {
  m_items[index]->use(user);
}

void Inventory::listItem() const {
  for (const auto& item: m_items) {
    string sign = item->getAmount() < 0? "-": " ";
    cout << item->getName() << " | " << sign << item->getAmount() << endl ;
  }
}
