/*
Name: Amrit Thapa
Class: Cs-302-001

This code has two classes: "Node" represents a tree node with functions for creation, display, and access. "Tree" manages the tree structure, including insertion, removal, display, and fetching. These classes enable storing "Character" ptr for the "Elemental Clash" game.
*/
#include "ElementalClash.h"
class Node
{
private:
    shared_ptr<Character> character;
    shared_ptr<Node> left;
    shared_ptr<Node> right;

public:
    Node();// defalut constructor
    ~Node(); // destructor
    Node(shared_ptr<Character> user_character);// paramater constructro
    int display_node();// displays the node
    void set_left(Node &node); // sets left ptr
    shared_ptr<Character> get_data(); // gets the data
    void set_right(Node &node);// sets the right ptr
    shared_ptr<Node> &get_left();// gets left ptr
    shared_ptr<Node> &get_right();// get right ptr
    friend bool operator<(shared_ptr<Node> node, string &name); // overlaoded <
    friend bool operator<(string &name, shared_ptr<Node> node);// overloaded <
    friend bool operator>=(shared_ptr<Node> node, string &name); // overloaed >=
    friend bool operator>=(string &name, shared_ptr<Node> node); // overloaded >=
    friend bool operator==(string &name, shared_ptr<Node> node); // overlaoded ==
    friend bool operator==(shared_ptr<Node> node, string &name);// overloaded ==
};

class Tree
{
private:
    shared_ptr<Node> root;
    int destroy(shared_ptr<Node> &root);// main destory fun
    int insert(shared_ptr<Node> &root, shared_ptr<Character> user_character, string &name);// main insert fun
    int remove(shared_ptr<Node> &root, string &name); // main remove function
    int display(shared_ptr<Node> root, int &count);// main display fucntion
    shared_ptr<Character> fetch(shared_ptr<Node> root, string &name);// main fetch 

public:
    Tree(); // constructro
    ~Tree();// destructor
    int remove(string &name);// wrapper of remove
    int insert(shared_ptr<Character> user_character, string &name);// wrapper of insert 
    int display(); // wrapper of display fucntion
    shared_ptr<Character> fetch(string &name);// wrappper for fetch
};