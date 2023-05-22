/*

Name: Amrit Thapa
Class: Cs-302-001
Program #2

purpose:
The purpose of this code is to define classes and their member
functions for managing game levels and player interactions in
the Duomatch game.
*/
#include "duomatch.h"
class Player;
class Level
{
protected:
    shared_ptr<Card> card;
    int level;
    array<Player *, 2> player;

public:
    Level();                      // constructro
    ~Level();                     // destructor
    Level(shared_ptr<Card> card); // constructro with paramater
};

class Level_node : public Level
{
public:
    Level_node();                            // constructor
    ~Level_node();                           // destructor
    Level_node(shared_ptr<Card> card);       // constructo with paramater
    void set_prev(Level_node *new_prev);     // sets the prev
    void set_next(Level_node *new_next);     // sets the next pointer
    Level_node *&get_prev();                 // gets the prev pointer
    Level_node *&get_next();                 // gets the next pointer
    int display_node(int &user_level);       // display the info contained in teh node
    bool has_card();                         // returns whether there is a card or not
    int effect();                            // returns the effect of the card
    int cards_type();                        // returns the type of the card
    Level_node &operator=(int level);        // equality overlaoded
    bool check_answer(const string &answer); // checks where the anser is correct or not

private:
    Level_node *prev;
    Level_node *next;
};

class DLL
{
private:
    Level_node *head;
    Level_node *tail;

    void set_dll(Level_node *&head, int count); // sets all the levels in DLL
    void destroy(Level_node *&head); // deletes the DLL
    shared_ptr<Level_node> move_player(Level_node * head, int num, int count); // moves players and returns the cards

public:
    DLL();                                       // constructro
    ~DLL();                                      // destructor
    void insert(shared_ptr<Card> card, int num); // inserts node in the DLL
    void set_dll();                              // sets the levels in DLL
    shared_ptr<Level_node> move_player(int num); // retrieve the node that the player lands on

};