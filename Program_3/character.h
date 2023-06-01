/*
Name: Amrit Thapa
Class: Cs-302-001
This code defines four classes for the "Elemental Clash" game: "Character," "WetWarriors," "DirtyTitans," and "PyroDemons." These classes encapsulate the attributes and behaviors of characters in the game, providing functions for attack, defend, special abilities, and displaying status.

*/
#include "ElementalClash.h"
class Character
{
private:
    string name;
    string type;

protected:
    int health;
    int damage;

public:
    Character();                                                                       // constructor
    Character(string &user_name, string &user_type, int user_health, int user_damage); // paramater constructor
    ~Character();                                                                      // destructor
    friend bool operator<(shared_ptr<Character> character, string &name);              // overloaded <
    friend bool operator<(string &name, shared_ptr<Character> character);              // overloaded <
    friend bool operator>=(shared_ptr<Character> character, string &name);             // overloaded >=
    friend bool operator>=(string &name, shared_ptr<Character> character);             // overloaded >=

    friend bool operator==(string &name, shared_ptr<Character> character); // overloaded ==
    friend bool operator==(shared_ptr<Character> character, string &name); // overloaded ==
    int health_status();                                                   // return health status
    string get_type();                                                     // gets the type of character
    virtual int attack();                                                  // virtual attack
    virtual int defend(int num);                                           // virtaul defend
    virtual void display_status();                                         // virtual display
};

class WetWarriors : public Character
{
private:
    string water_pressure;
    int water_level;
    int magic_water;

public:
    WetWarriors();                                                                                     // constructor
    WetWarriors(const Character &character, string &water_pressure, int water_level, int magic_water); // paramater constructor
    ~WetWarriors();                                                                                    // destructor
    int attack();                                                                                      // return the attack value
    int defend(int num);                                                                               // takes damange from oponent
    int heal();                                                                                        // special ability
    void display_status();                                                                             // displays the current status
};
class DirtyTitans : public Character
{
private:
    string hardness;
    int hard_time;

public:
    DirtyTitans();                                                      // constructor
    DirtyTitans(Character &character, string &hardness, int hard_time); // paramater constructor
    ~DirtyTitans();                                                     // destructor
    int attack();                                                       // return the attack value
    int defend(int num);                                                // takes damange from oponent
    int ground_pound();                                                 // special ability
    void display_status();                                              // displays the current status
};
class PyroDemons : public Character
{
private:
    string hotness;
    int burn_time;

public:
    PyroDemons();                                                     // constructor
    PyroDemons(Character &character, string &hotness, int burn_time); // paramater constructor
    ~PyroDemons();                                                    // destructor
    int attack();                                                     // return the attack value
    int defend(int num);                                              // takes damange from oponent
    int fiery_ball();                                                 // special ability
    void display_status();                                            // displays the current status
};