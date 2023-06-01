/*
Name: Amrit Thapa

This file defines the "Character" base class and three derived
classes ("WetWarriors," "DirtyTitans," and "PyroDemons") for the
"Elemental Clash" game. The base class provides common attributes
and functions, while the derived classes introduce unique attributes
and abilities for each character type. Each class includes functions for
attack, defend, and display_status, allowing characters to interact within the game environment.

*/
#include "ElementalClash.h"
// ========= CHARACTER =============

// Default Constructor
Character ::Character() {}

// Default Destructor
Character::~Character()
{
    health = 0;
    damage = 0;
}

// Constructor with paramaters
Character ::Character(string &user_name, string &user_type, int user_health, int user_damage) : name(user_name), type(user_type), health(user_health), damage(user_damage) {}

// virtual fucntion taht calls derived attack
int Character::attack()
{
    return 0;
}

// return the type of character
string Character ::get_type()
{
    return type;
}

// virtual function for defend
int Character::defend(int num)
{
    return 0;
}

// display fucntion for character
void Character::display_status()
{
    cout << "Name: " << name << endl;
    cout << "Type: " << type << endl;
    cout << "Health: " << health << endl;
    cout << "Damage: " << damage << endl;
}

// overloaded <
bool operator<(shared_ptr<Character> character, string &user_name)
{
    return character->name < user_name;
}

// overloaded <
bool operator<(string &user_name, shared_ptr<Character> character)
{
    return user_name < character->name;
}

// overloaded >=
bool operator>=(shared_ptr<Character> character, string &user_name)
{
    return character->name >= user_name;
}

// overloaded >=
bool operator>=(string &user_name, shared_ptr<Character> character)
{
    return user_name >= character->name;
}

// overlaoded the compare
bool operator==(string &name, shared_ptr<Character> character)
{
    return name == character->name;
}

// overlaoded the compare
bool operator==(shared_ptr<Character> character, string &name)
{
    return character->name == name;
}

// return the health for character
int Character::health_status()
{
    return health;
}

// ========= WET WARRIORS =============

// default constructor
WetWarriors ::WetWarriors() {}

// default destructor
WetWarriors::~WetWarriors()
{
    water_level = 0;
    magic_water = 0;
}

// constructor with paramaters
WetWarriors::WetWarriors(const Character &character, string &user_water_pressure, int user_water_level, int user_magic_water) : Character(character), water_pressure(user_water_pressure), water_level(user_water_level), magic_water(user_magic_water) {}

// return the attack of the character
int WetWarriors::attack()
{
    water_level -= 5;
    if (water_level < 0)
    {
        cout << "sorry cant do any damage as you are out of water." << endl;
        return 0;
    }
    else
    {
        return damage;
    }
    return 0;
}

// tkae the damage and substractes the opponent
// attack
int WetWarriors::defend(int num)
{
    health -= num;
    if (health < 0)
    {
        // cout << "you are dead " << endl;
        return 0;
    }
    return 1;
}

// special ability to heal
int WetWarriors::heal()
{
    magic_water -= 20;
    health += 10;
    if (magic_water < 0)
    {
        cout << "sorry you cant heal as you are out of magice water." << endl;
        return 0;
    }
    return 1;
}

// displays the status of characters
void WetWarriors::display_status()
{
    Character ::display_status();
    cout << "Water Pressure: " << water_pressure << endl;
    cout << "Water Level: " << water_level << endl;
    cout << "Magic Water: " << magic_water << endl;
}
// ========= DIRTY TITANS =============

// Default constructor
DirtyTitans ::DirtyTitans() {}

// default destructor
DirtyTitans::~DirtyTitans()
{
    hard_time = 0;
}

// Constructor with paramaters
DirtyTitans::DirtyTitans(Character &character, string &user_hardness, int user_hard_time) : Character(character), hardness(user_hardness), hard_time(user_hard_time) {}

// return the attack but take off hard time
int DirtyTitans::attack()
{
    hard_time -= 5;
    if (hard_time < 0)
    {
        cout << "sorry you are out of attack" << endl;
        return 0;
    }
    return damage;
}

// defends and take in opponent damage
int DirtyTitans::defend(int num)
{
    health -= num;
    if (health < 0)
    {
        cout << "you are dead " << endl;
        return 0;
    }
    return 1;
}

// special ability
int DirtyTitans::ground_pound()
{
    hard_time -= 10;
    if (hard_time < 0)
    {
        cout << "sorry you are out of attack" << endl;
        return 0;
    }
    return 20;
}

// displays info about dirty titans
void DirtyTitans::display_status()
{
    Character ::display_status();
    cout << "Hardness: " << hardness << endl;
    cout << "Hard Time: " << hard_time << endl;
}

// ========= PYRO DEMONS =============

// Default constructor
PyroDemons ::PyroDemons() {}

// destructor
PyroDemons::~PyroDemons()
{
    burn_time = 0;
}

// constructor with paramters
PyroDemons::PyroDemons(Character &character, string &user_hotness, int user_burn_time) : Character(character), hotness(user_hotness), burn_time(user_burn_time) {}

// return the attack value
int PyroDemons::attack()
{
    // burn_time -= ;
    // if (burn_time < 0)
    // {
    //     cout << "sorry you are out of attack" << endl;
    //     return 0;
    // }
    return damage;
}

// takes damge of the oponent
int PyroDemons::defend(int num)
{
    health -= num;
    if (health < 0)
    {
        cout << "you are dead " << endl;
        return 0;
    }
    return 1;
}

// special ability of pyrodmons
int PyroDemons::fiery_ball()
{
    burn_time -= 1;
    if (burn_time < 0)
    {
        cout << "sorry you are out of attack" << endl;
        return 0;
    }
    return 20;
}

// displays all info about pyrodmons
void PyroDemons::display_status()
{
    Character ::display_status();
    cout << "Hotness: " << hotness << endl;
    cout << "Burn Time: " << burn_time << endl;
}