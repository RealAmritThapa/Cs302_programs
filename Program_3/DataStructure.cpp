/*
Name: Amrit Thapa
Class: Cs-302-001

This code defines two classes: "Node" and "Tree." The "Node" class represents
a node in a tree structure and holds a shared pointer to a "Character" object.
 It includes functions for creating, displaying, and accessing child nodes, as
 well as retrieving character data. The "Tree" class manages a binary tree and
 provides functions for destroying the tree, inserting nodes, displaying nodes
 in-order, removing nodes based on a given name, and fetching character data
 based on a given name. Together, these classes establish the structure and
 operations of a binary tree that stores "Character" pointer for the "Elemental Clash" game.
*/
#include "ElementalClash.h"

// Default constructro
Node ::Node() : left(nullptr), right(nullptr) {}

// Destructro
Node ::~Node()
{
}

// paramater constructro
Node ::Node(shared_ptr<Character> user_character)
{
    character = user_character;
}

// displays the node
int Node ::display_node()
{
    character->display_status();
    return 1;
}

// returns the left node
shared_ptr<Node> &Node::get_left()
{
    return left;
}

// returns the right node
shared_ptr<Node> &Node::get_right()
{
    return right;
}

// returns the node of the chosen character
shared_ptr<Character> Node ::get_data()
{
    return character;
}

// set left pointer
void Node ::set_left(Node &node)
{
    left = make_shared<Node>(node);
}

// sets the right pointer
void Node ::set_right(Node &node)
{
    right = make_shared<Node>(node);
}

// overloaded <
bool operator<(shared_ptr<Node> node, string &name)
{
    return node->character < name;
}

// overloaded <
bool operator<(string &name, shared_ptr<Node> node)
{
    return name < node->character;
}

// overloaded >=
bool operator>=(shared_ptr<Node> node, string &name)
{
    return node->character >= name;
}

// overloaded >=
bool operator>=(string &name, shared_ptr<Node> node)
{
    return name >= node->character;
}

// overloaded ==
bool operator==(string &name, shared_ptr<Node> node)
{
    return name == node->character;
}

// overloaded ==
bool operator==(shared_ptr<Node> node, string &name)
{
    return node->character == name;
}
// ========= TREE =============

// default constructor
Tree ::Tree()
{
}

// default destructor
Tree ::~Tree()
{
    if (!root)
    {
        return;
    }
    destroy(root);
}

// deletes all the nodes using postorder traversal
int Tree ::destroy(shared_ptr<Node> &root)
{
    if (!root)
    {
        return 0;
    }
    destroy(root->get_left());
    destroy(root->get_right());
    root.reset();
    return 1;
}

// inserts in the tree wrapper
int Tree::insert(shared_ptr<Character> user_character, string &name)
{
    if (!root)
    {
        root = make_shared<Node>(Node(user_character));
        return 1;
    }
    return insert(root, user_character, name);
}

// main insert code to be called in the wrapper
int Tree ::insert(shared_ptr<Node> &root, shared_ptr<Character> user_character, string &name)
{
    if (!root)
    {
        root = make_shared<Node>(Node(user_character));
        return 1;
    }
    if (name < root)
    {
        insert(root->get_left(), user_character, name);
    }
    else
    {
        insert(root->get_right(), user_character, name);
    }
    return 0;
}

// wrapper for the display fucntion
int Tree::display()
{
    if (!root)
    {
        return 0;
    }
    int count = 1;
    return display(root, count);
}

// main display fucntion to be callled in the wr4apper
int Tree ::display(shared_ptr<Node> root, int &count)
{
    if (!root)
    {
        return 0;
    }
    display(root->get_left(), count);
    cout << count << ": " << endl;
    root->display_node();
    cout << '\n'
         << endl;
    ++count;
    display(root->get_right(), count);
    return 1;
}
// wrapper function for the remove function
int Tree ::remove(string &name)
{

    if (!root)
    {
        return 0;
    }
    return remove(root, name);
}

// recursive function for the remove
// takes a user term to find a match
// the once match is found it removes that term from the tree
int Tree ::remove(shared_ptr<Node> &root, string &name)
{
    if (!root)
    {
        return 0;
    }

    else
    {
        if (name < root)
        {
            remove(root->get_left(), name);
        }

        if (name == root)
        {
            if (root->get_left() == nullptr && root->get_right() == nullptr)
            {

                root.reset();
                root = nullptr;
            }

            else if (root->get_left() == nullptr)
            {
                shared_ptr<Node> hold = root->get_right();
                root.reset();
                root = hold;
            }

            else if (root->get_right() == nullptr)
            {
                shared_ptr<Node> hold = root->get_left();
                root.reset();
                root = hold;
            }

            // else
            // {
            //     dict hold;
            //     find_successer(hold);
            //     root->info.copy_info(hold);
            //     --num;
            // }
            return 1;
        }
        else
        {
            remove(root->get_right(), name);
        }
        return 1;
    }
}

// feteche the name of the character
shared_ptr<Character> Tree::fetch(string &name)
{
    if (!root)
    {
        static shared_ptr<Character> empty;
        return empty;
    }
    return fetch(root, name);
}

// gets called in the fucniton above
shared_ptr<Character> Tree ::fetch(shared_ptr<Node> root, string &name)
{
    if (!root)
    {
        static shared_ptr<Character> empty;
        return empty;
    }
    if (name == root)
    {
        shared_ptr<Character> character = root->get_data();
        return character;
    }
    if (name < root)
    {
        return fetch(root->get_left(), name);
    }
    else
    {
        return fetch(root->get_right(), name);
    }

    static shared_ptr<Character> empty;
    return empty;
}