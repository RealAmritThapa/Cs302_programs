/*
Name: Amrit Thapa
Class: Cs-302-001
The "ElementalClash" class manages the gameplay of the
"Elemental Clash" game, including character handling, battles,
and game flow.

*/
#ifndef ELEMENTAL_CLASH_H
#define ELEMENTAL_CLASH_H

#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <fstream>
#include <random>
#include <vector>

using namespace std;
#include "character.h"
#include "DataStructure.h"
class ElementalClash
{
private:
    Tree database;
    int turn;
    vector<string> character_names;
    shared_ptr<Character> player;
    shared_ptr<Character> cpu;

public:
    ElementalClash();                                 // constructor
    ~ElementalClash();                                // destructro
    int check(const string &name);                    // checks name
    int to_lower(string &name);                       // lowercase
    void get_characters();                            // fetched characters
    void special_move(shared_ptr<Character> players); // special move
    int menu(shared_ptr<Character> players);          // menu for battle
    void load();                                      // puts in binary tree
    int attack_cpu();                                 // attack cpu
    int attack_player();                              // attack player
    void show_status();                               // shows status
    void display();                                   // display
    void battle();                                    // batles main event
    void start_battle();                              // starts the battel
};
#endif