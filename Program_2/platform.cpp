/*
Name: Amrit Thapa
Class: Cs-302-001
Program #2
    purpose:
    This code defines classes related to game levels: Level, Level_node, and DLL.
    The Level class manages individual game levels, while the Level_node class represents
    nodes in the game path and handles card effects. The DLL class is a doubly linked list
    used to manage the game path and facilitate player movement.
*/
#include "duomatch.h"

// ====================== LEVEL =======================
// constructor
Level ::Level() : card(nullptr), level(1)
{
    player[0] = nullptr;
    player[1] = nullptr;
}

// constructor with paramaters
Level ::Level(shared_ptr<Card> real_card)
{
    card = real_card;
    player[0] = nullptr;
    player[1] = nullptr;
}

// destructor
Level ::~Level()
{
    level = 0;
}
// ====================== LEVEL NODE =======================

// constructor
Level_node ::Level_node() : next(nullptr), prev(nullptr) {}

// constructor with paramaters
Level_node ::Level_node(shared_ptr<Card> card) : Level(card), next(nullptr), prev(nullptr) {}

// destructor
Level_node::~Level_node()
{
    next = nullptr;
    prev = nullptr;
}

// sets the prev with passed in prev
void Level_node ::set_prev(Level_node *new_prev)
{
    prev = new_prev;
}

// sets the next pointer
void Level_node ::set_next(Level_node *new_next)
{
    next = new_next;
}

// gets the previous pointer
Level_node *&Level_node::get_prev()
{
    return prev;
}

// gets the next pointer
Level_node *&Level_node ::get_next()
{
    return next;
}

// displays the info in the node
int Level_node::display_node(int &user_level)
{
    int num = 0;
    if (card == nullptr)
    {
        // cout << "==========================" << endl;

        // cout << "this is level: " << level << endl;
    }
    else
    {
        // cout << "this is level: " << level << endl;
        // cout << *card << endl;
        num = effect();
    }

    user_level = level;
    return num;
}

// add the levels to nodes
Level_node &Level_node ::operator=(int user_level)
{
    level = user_level;
    return *this;
}

bool Level_node ::has_card()
{
    if (card)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// returns the effects of the cards
int Level_node::effect()
{
    int effect = 0;
    if (card == nullptr)
    {
        // cout << "here" << endl;
        return 0;
    }
    else
    {
        // cout << "here" << endl;
        if (*card == "obstacle")
        {
            shared_ptr<Obstacle> obstacle = dynamic_pointer_cast<Obstacle>(card);

            if (obstacle)
            {
                obstacle->give_effect(effect);
                cout << *obstacle;
            }
        }
        if (*card == "challenge")
        {
            shared_ptr<Challenge> challenge = dynamic_pointer_cast<Challenge>(card);
            if (challenge)
            {
                challenge->give_effect(effect);
                cout << *challenge;
            }
            else
            {
                cout << "NULLPTR" << endl;
            }
        }
        if (*card == "reward")
        {
            shared_ptr<Reward> reward = dynamic_pointer_cast<Reward>(card);
            cout << *reward;
        }
        // return 1;
    }
    return effect;
}

// retusn the type of each card
int Level_node ::cards_type()
{
    return card->card_type();
}

// check teh answer to the questions and returns a bool
bool Level_node::check_answer(const string &answer)
{
    bool correct;
    if (*card == "challenge")
    {
        shared_ptr<Challenge> challenge = dynamic_pointer_cast<Challenge>(card);
        if (challenge)
        {
            correct = challenge->check_answer(answer);
        }
        else
        {
            cout << "NULLPTR" << endl;
        }
    }
    return correct;
}
// ====================== DLL =======================

// constructor
DLL::DLL() : head(nullptr) {}

// destructor
DLL ::~DLL()
{
    if (!head)
    {
        return;
    }
    destroy(head);
}

// gets called int the fucntion above
void DLL ::destroy(Level_node *&head)
{
    if (!head)
    {
        return;
    }
    Level_node *hold = head->get_next();
    delete head;
    head = nullptr;
    head = hold;
    destroy(head);
}

// insers card into DLL
void DLL::insert(shared_ptr<Card> card, int num)
{
    Level_node *temp = nullptr;
    if (num == 1)
    {
        temp = new Level_node(card);
    }
    else
    {
        temp = new Level_node();
    }
    if (!head)
    {
        head = tail = temp;
        return;
    }
    tail->set_next(temp);
    temp->set_prev(tail);
    tail = temp;
    return;
}

// sets the levels in DLL
void DLL::set_dll()
{
    if (!head)
    {
        return;
    }
    int count = 0;
    return set_dll(head, count);
}

// gets called int he fucntion above
void DLL ::set_dll(Level_node *&head, int count)
{
    if (!head)
    {
        return;
    }
    *head = count;
    return set_dll(head->get_next(), ++count);
}

// retusn the node when moveing player
shared_ptr<Level_node> DLL ::move_player(int num)
{
    if (!head)
    {
        return nullptr;
    }

    int count = 0;
    return move_player(head, num, count);
    // Level_node *ptr = head;
    // while (count < num && ptr != tail)
    // {
    //     ptr = ptr->get_next();
    //     ++count;
    // }
    // return make_shared<Level_node>(*ptr);
}

shared_ptr<Level_node> DLL ::move_player(Level_node *head, int num, int count)
{
    if (!head)
    {
        return nullptr;
    }
    if (count == num || head == tail)
    {
        return make_shared<Level_node>(*head);
    }
    return move_player(head->get_next(), num, ++count);
}