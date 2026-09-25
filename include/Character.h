#pragma once
#include <string>
#include "Inventory.h"

using namespace std;


class Character {
    protected:
        string m_name;
        int m_currentHP;
        int m_maxHP;
        int m_attackPower;
        int m_weaponBonus = 0;
        Inventory inventory;

        static int TotalCharacterCreated;

    public:
        Character(string charName, int hp, int maxHP, int attackPower);

        static int getTotalCharacterCreated();

        void getStatus() const;
            
        void takeDamage(int amount);

        void heal(int amount);

        bool isAlive() const;

        void equipWeapon(int bonusAmount);
        
        void unEquipWeapon();

        Inventory& getInventory();

        virtual void attack(Character& target);

        string getName () const;
        
        int getHP() const;
};