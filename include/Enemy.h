#pragma once

#include "Character.h"

class Goblin: public Character {
  public:
      Goblin(): Character("Goblin", 30, 30, 5) {};

};

class Orc: public Character {
  public:
      Orc(): Character("Orc", 60, 60, 12) {};

      void attack(Character& target) override;

};