<!-- 
# OOP Project Log

##  **learncpp.com chapters** to read that week

**Date:** 

**The feature** (what the game can now do)

**Location** (class/function name) [image ][link]

**why that concept exists**
(the bug, the awkward code, or the design smell)

**What happends if its not implemented**
(the bug, the awkward code, or the design smell)v

**the problem it solves in project**
(what you changed and why it worked)

**60-second interview answer:**
(write it exactly how you'd say it out loud)

**GfG-style definition:**
(the crisp one-liner)

--- -->
# OOP Project Log

## Basics

- **Date:** 6th Sept 2026 

- **The Concept:** 
  - [How Cpp Works](https://youtu.be/SfGuIVzE_Os)
  - [How Compiler Works](https://youtu.be/3tIqpEmWMLI)
  - [How Linker Works](https://youtu.be/H4s55GgAg0I)
  - [Cpp Header Files](https://youtu.be/9RJTQmK0YPI)

---
- **Date:** 7th Sept 2026 

- **The Concept:** 
  - [Pointers in C++](https://youtu.be/DTxHyVn0ODg)
  - [References in C++](https://youtu.be/IzoFn3dfsPA)
  - [Classes in C++](https://youtu.be/2BP8NhxjrO0)
  

---

## One Character, One Enemy and a Working Battle

- **Date:** 9th Sept 2026 

- **The Concept:** 
  - [Classes vs Struct in C++](https://youtu.be/fLgTtaqqJp0)
  - [Best Practices to write C++ class](https://youtu.be/3dHBFBw13E0)
  - [Static in C++](https://youtu.be/f3FVU-iwNuA)
  - [Static for Classes and Structs](https://youtu.be/V-BFlMrBtqQ)
  - [ENUMS in C++](https://youtu.be/x55jfOd5PEE)
  - [Inheritance in C++](https://youtu.be/X8nYM8wdNRE)

---

- **Date:** 12th Sept 2026 

- **The Concept:** 
  - [Contructors in C++](https://youtu.be/FXhALMsHwEY)
  - [Destructors in C++](https://youtu.be/D8cWquReFqw)
  - [Virtual Functions in C++](https://youtu.be/oIV2KchSyGQ)

---
- **Date:** 16th Sept 2026 

- **The Concept:** 
  - [Visibility in C++](https://youtu.be/6OVQ8nh3KP0)

---
- **Date:** 17th Sept 2026 

- **The Concept:** 
  - [Const in C++](https://youtu.be/4fJBrditnJU)

---

**The feature:** 
- Built a `Character` class with name, current hp, maximum hp and attacking power. Also added necessary getter functions and action functions.
- Created a `Goblin` class which inherits `Character` class.
- Created a `static` variable and member function for total characters created.
<br>

**Location:** [Character.cpp](./src/characters/Character.cpp) | [Character.h](./include/Character.h)  |  [Goblin.cpp](./src/characters/Goblin.cpp) | [Goblin.h](./include/Goblin.h)

**Why that concept exists:** 
- **`Inheritance`:** Used to give default members and member functions to the sub class so they could inherit the common properties.
- **Static:** Used to share a single variable accross all object of that class.
- Created a `static` variable and member function for total characters created.

**What happends if its not implemented:**
- **`Inheritance`:** we will have to explicitly define each member function for parent class as well as child class.

**the problem it solves in project:**
Implementing a base class as character helped to implement common attributes and function to all the specific characters without repeating the code and without explicitly assigning the attributes in each specific character class.

### Checkpoint questions
---
- Why does `Character` use protected instead of private for its members, given that `Goblin` needs to use them? <br>
through protected the subclass can access the member functions or member variable from the base class <br> but if the base class uses private those member function or variable would be accessible only to the base class and not the subclass
- what's the actual difference between overloading `Character`'s constructor and overriding `attack()` in `Goblin` — which one is resolved at compile time, and which at runtime?
<br>
`Overloading constructor` or member function means functions or contructor are overloaded using the same name but different parameter list and it is defined in the same class. Overloading is resolved at **compile time**.<br>
whereas `overriding` means the subclass provides its own implementation of the same function which is defined in the base class. `virtual` keyword is used to override the function in the sub class and it is resolved at **run time**.


---