/*
Name: Amrit Thapa
Class: Cs-302-001
Program #2

purpose:
This code defines classes for a card game, including Card, Obstacle, Reward, and Challenge.
The Card class represents a generic card with a name, type, and description, offering
functions to display information and compare types. The Obstacle class extends Card
and adds a step back value, displaying obstacle information and providing the effect
of stepping back. The Reward class extends Card and includes a move forward value,
displaying reward information. The Challenge class extends Card and introduces a
question, answer, and move forward value, providing functions to display challenge
information, check answers, and give the move forward effect. These classes enable
the implementation of different card types and actions in the game.



*/
#include "duomatch.h"
// ====================== CARDS =======================
// Default constructor for Card class
Card ::Card() : name(nullptr) {}

// Constructor with parameters for Card class.
Card ::Card(char *card_name, string &card_type, string &card_description) : name(nullptr), type(card_type), description(card_description)
{
    name = new char[strlen(card_name) + 1];
    strcpy(name, card_name);
}

// Destructor for Card class.
Card ::~Card()
{
    delete[] name;
    name = nullptr;
}

// Assinment operator overloaded
Card &Card ::operator=(const Card &card)
{
    if (this == &card)
    {
        return *this;
    }
    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
    }
    name = new char[strlen(card.name) + 1];
    strcpy(name, card.name);
    type = card.type;
    description = card.description;
    return *this;
}

//copy constructor for the card class
Card ::Card(const Card &card) : name(nullptr), type(card.type), description(card.description)
{
    name = new char[strlen(card.name) + 1];
    strcpy(name, card.name);
}

//display information about the card
int Card ::display_card_info(ostream &show) const
{
    // cout << "========= CARD INFO ==============\n"
    //      << endl;
    cout << "Name: " << name << endl;
    cout << "Type: " << type << endl;
    cout << "Description: " << description << endl;
    return 1;
}

//insertion operator overloaded
ostream &operator<<(ostream &show, const Card &card)
{
    card.display_card_info(show);
    return show;
}

// equality operator oveloaded
bool Card ::operator==(string user_type)
{
    if (type == user_type)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// returns the type of the card
int Card ::card_type()
{
    if (type == "obstacle")
    {
        return 1;
    }
    if (type == "challenge")
    {
        return 2;
    }
    if (type == "reward")
    {
        return 3;
    }
    return 0;
}
// ====================== OBSTACLE =======================


// constructor for obstacle
Obstacle ::Obstacle() : step_back(0) {}

// constructor with paramaters
Obstacle ::Obstacle(const Card &data, int user_step_back, string &card_effect) : Card(data), step_back(user_step_back) {}

// Destructor
Obstacle ::~Obstacle()
{
    step_back = 0;
}

// display obstacle info
int Obstacle ::display_obstacle_info(ostream &show) const
{
    cout << "========= OBSTACLE CARD INFO ==============\n"
         << endl;
    display_card_info(show);
    cout << "You wil have to step Back " << (step_back * -1) << " spaces" << endl;
    return 1;
}

// oveload to display the info 
ostream &operator<<(ostream &show, const Obstacle &obstacle)
{
    obstacle.display_obstacle_info(show);
    return show;
}

// returns the effect of the card
void Obstacle ::give_effect(int &effect)
{
    effect = step_back;
}
// ====================== REWARD =======================

// constructor reward class
Reward ::Reward() : move_forward(0)
{
}

//destructor for reward
Reward ::~Reward()
{
    move_forward = 0;
}

//constructor for reward class with paramaters
Reward ::Reward(const Card &data, int user_move_forward, string &card_reward, string &card_reward_power) : Card(data), move_forward(user_move_forward), reward(card_reward), reward_power(card_reward_power)
{
}

// display for reward class
int Reward ::display_reward_info(ostream &show) const
{
    cout << "========= REWARD CARD INFO ==============\n"
         << endl;

    display_card_info(show);
    cout << "Reward: " << reward << endl;
    cout << "You get to move forward " << reward_power << " spaces" << endl;
    return 1;
}

// overlaoded fucntion to display the infor baout reward class
ostream &operator<<(ostream &show, const Reward &reward)
{
    reward.display_reward_info(show);
    return show;
}

// ====================== CHALLENGE =======================

//constructor for challenge class
Challenge ::Challenge() : move_forward(0) {}

// destructor for challenge class
Challenge ::~Challenge()
{
    move_forward = 0;
}

// constrructor for challenge with parrameters
Challenge ::Challenge(const Card &data, string &user_question, string &user_answer, int user_move_forward) : Card(data), question(user_question), answer(user_answer), move_forward(user_move_forward)
{
}

//displays the infor about the challgne card
int Challenge ::display_challenge_info(ostream &show) const
{
    cout << "========= CHALLENGE CARD INFO ==============\n"
         << endl;

    display_card_info(show);
    cout << "Question: " << question << endl;
    return 1;
}

// takes answer from user and check it
bool Challenge ::check_answer(const string &user_answer)
{
    if (answer != user_answer)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// ovelaod the display fucction
ostream &operator<<(ostream &show, const Challenge &challenge)
{
    challenge.display_challenge_info(show);
    return show;
}

//it returns the effect of the card
void Challenge ::give_effect(int &effect)
{
    effect = move_forward;
}