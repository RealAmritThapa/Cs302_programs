

/*
Name: Amrit Thapa
Class: Cs-302-001
Program #2

purpose:
This code consists of classes representing different types of cards in a card game:
Card, Obstacle, Reward, and Challenge. The Card class serves as the base class,
while the derived classes add specific features and behaviors. The classes encapsulate
attributes such as name, type, and description, and provide methods for displaying
card information, comparing types, and applying card effects. These classes
form the building blocks for creating and managing various cards in the game.

*/
#include "duomatch.h"

// ====================== CARDS =======================

class Card
{
private:
    char *name;
    string type;
    string description;

public:
    Card();                                                            // constructor
    ~Card();                                                           // destructor
    Card(char *car_name, string &card_type, string &card_description); // construct with paramaters
    Card(const Card &card);                                            // constructore
    Card &operator=(const Card &card);                                 // equality oveloaded
    virtual int display_card_info(ostream &show) const;                // displayes card info
    friend ostream &operator<<(ostream &show, const Card &card);       // insertion operator overloaded
    bool operator==(string user_type);                                 // equality operator overloaded
    int card_type();                                                   // returns the card type
};

// ====================== OBSTACLE Card =======================
class Obstacle : public Card
{
private:
    int step_back;
    string effect;

public:
    Obstacle();                                                     // constructor
    ~Obstacle();                                                    // destructor
    Obstacle(const Card &data, int user_step_back, string &effect); // constructor with paramaters
    virtual int display_obstacle_info(ostream &show) const;         // displays the info
    void give_effect(int &effect);                                  // returns the effects of the cards
    // Obstacle &operator=(const Obstacle &obstacle);

    friend ostream &operator<<(ostream &show, const Obstacle &obstacle); // overlaod the dipslay fucniton
};

// ====================== REWARD Card =======================
class Reward : public Card
{
private:
    int move_forward;
    string reward;
    string reward_power;

public:
    Reward(); // constructor 
    ~Reward(); // destructor 
    Reward(const Card &data, int move_forward, string &reward, string &reward_power); // constructor with paramaters
    virtual int display_reward_info(ostream &show) const; // display fucntion
    friend ostream &operator<<(ostream &show, const Reward &reward); // display fucntion using overlaoding
};

// ====================== CHALLENGE Card =======================
class Challenge : public Card
{
private:
    string question;
    string answer;
    int move_forward;

public:
    Challenge(); // constructor 
    ~Challenge(); // destructor 
    Challenge(const Card &data, string &question, string &answer, int move_forward); // construcor with pareameters
    virtual int display_challenge_info(ostream &show) const; // displya fucntion 
    friend ostream &operator<<(ostream &show, const Challenge &challenge); // display fucntion using overlaoding
    void give_effect(int &effect); // returns the effect of the card 
    bool check_answer(const string &user_answer); // checks answer ahd return a bool
};
