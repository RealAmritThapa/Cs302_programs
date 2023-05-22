// #include "duomatch.h"
/*
Name: Amrit Thapa
Class: Cs-302-001
Program #2
purpose: 

This code defines templated Node and Linear Linked List (LLL) classes for 
managing linked lists. The Node class represents a node with functions for 
setting/getting the next node, displaying data, and retrieving data. The LLL 
class provides functions for insertion, display, retrieval, and concatenation. 
*/
#ifndef DATA_H
#define DATA_H
// ====================== TEMPELATE NODE =======================
template <typename object>

class Node
{
private:
    object data;
    Node *next;

public:
    Node(); // constructor
    ~Node(); // destructor 
    Node(const object &data); // constructro with paramaters
    void set_next(Node *new_next); // sets the next pointer
    Node *&get_next(); // gets the next pointer
    void display(); // displays the info in the node
    object &retrieve(); // returns the object
};

// ====================== TEMPELATE LINEAR LINKED LIST =======================
template <typename object>
class LLL
{
private:
    Node<object> *head;
    void  display(Node<object> * head)const;
    void  destroy(Node<object> *&head);
    shared_ptr<object>retrieve(Node<object> *head,int num, int start);

public:
    LLL(); //constructor
    ~LLL(); // destructor 
    void insert(const object &data); // inserts into LLL
    void display() const; // displays the LLL
    shared_ptr<object> retrieve(int num); // retrieves the watned object
    LLL<object> & operator+=(const object & data); // insert overloaded
};
#include "data_structure.tpp"
#endif