#include "Item.h"
#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class Inventory {
  private:
    vector<unique_ptr<Item>> m_items;

  public:
    void addItem(unique_ptr<Item> newItem) {
      m_items.push_back(move(newItem));
    }

    void useItem(int index, Character* user) {
      m_items[index]->use(user);
    }

    void listItem() const {
      for (const auto& item: m_items) {
        string sign = item->getAmount() < 0? "-": " ";
        cout << item->getName() << " | " << sign << item->getAmount() << endl ;
      }
    }


};