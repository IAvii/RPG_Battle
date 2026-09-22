#pragma once
#include <string>

using namespace std;


class Character {
    protected:
        string m_name;
        int m_currentHP;
        int m_maxHP;
        int m_attackPower;

        static int TotalCharacterCreated;
    public:

        Character(string charName, int hp, int maxHP, int attackPower);

        static int getTotalCharacterCreated() {
            return TotalCharacterCreated;
        }

        void getStatus() const;
            
        void takeDamage(int amount);

        bool isAlive() const;

        virtual void attack(Character& target);

        string getName () const;
        
        int getHP() const;
};

int Character::TotalCharacterCreated = 0;