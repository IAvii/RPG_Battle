#include "Inventory.h"
#include <vector>
#include <iostream>
#include <memory>

using namespace std;


void Inventory::addItem(unique_ptr<Item> newItem) {
  m_items.push_back(move(newItem));
}

void Inventory::useItem(int index, Character* user) {

  if (index < 0 || index >= static_cast<int>(m_items.size())) {
    std::cout << "Invalid item selection!\n";
    return;
  }
  
  Item* itemToUse = m_items[index].get();
  itemToUse->use(user);

  if (itemToUse->isConsumable()) {
    itemToUse->decreaseQuantity();
    cout << "[SYSTEM]: " << itemToUse->getName() 
    << " remaining: " << itemToUse->getQuantity() << "\n";

    if (itemToUse->getQuantity() <= 0) {
      m_items.erase(m_items.begin()+index);
      cout << "[SYSTEM]: " << itemToUse->getName() << " is completely used up!\n";
    }
  }
}

void Inventory::listItem() const {
  if (m_items.empty()) {
    cout << "Your Inventory is empty!\n";
    return;
  }

  for (int i=0; i<m_items.size(); ++i) {
    cout << i << ": " << m_items[i]->getName();

    if (m_items[i]->isConsumable()) {
      cout << "(x" << m_items[i]->getQuantity() << ")";
    } else {
      cout << "[Equippable]";
    }
    cout << endl;
  }
}
