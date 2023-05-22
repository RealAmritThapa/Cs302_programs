
/*
Name: Amrit Thapa
Class: Cs-302-001
Program #2
purpose:

The purpose of this file is to define the classes Player and Duomatch
for the Duomatch game. It includes necessary headers, such as <iostream>, <string>,
and others. The Player class represents a player in the game, with functions for
displaying player information, managing the player's level and position, and generating
a report. The Duomatch class manages the game itself, including initializing the game,
loading data, executing the main game logic, and rolling the dice.
*/
#ifndef DUOMATCH_H
#define DUOMATCH_H

#include <iostream>
#include <string>
#include <array>
#include <list>
#include <cstring>
#include <fstream>
#include <memory>
#include <random>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "cards.h"
#include "data_structures.h"
#include "platform.h"

class Player
{
private:
    string name;
    int level;
    shared_ptr<Level_node> current_position;
    list<shared_ptr<Level_node>> storage;

public:
    Player();                                                          // constructor
    ~Player();                                                         // destructor
    Player(string &name, int user_level, shared_ptr<Level_node> data); // constructor with paramaters
    void display_player();                                             // displays info about player
    void report();                                                     // reports all the cards got by player
    void get_level(int &move);                                         // gets the levels of the players
    Player &operator=(const shared_ptr<Level_node> &data);             // equality operator overloaded
    // friend Player &operator+(int die_value, const Player &player);
    friend istream &operator>>(istream &input, Player &player); // inserts player info
    int path_check(int level, int roll);                        // checks the path and updates the levels
};

class Duomatch
{
private:
    LLL<Obstacle> obstacle_card;
    LLL<Challenge> challenge_card;
    LLL<Reward> reward_card;
    DLL path_manager;
    int levels;
    Player player_1;
    Player player_2;
    int turn;

public:
    Duomatch();             // constructor
    ~Duomatch();            // destructor
    void get_player_info(); // gathers info about the palyer
    void welcome();         // welcomes the user
    int main_game();        // runs the main game
    void start();           // this function runs the whole game
    void load();            // loads all cards into LLL
    void display() const;   // display the infotmainto
    void fill_path();       // fills DLL with cards from LLL
    void show();            // displays LLL
    int roll_die();         // rolls a die and returns the value
};

#endif