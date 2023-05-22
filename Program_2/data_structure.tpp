/*
Name: Amrit Thapa
Class: Cs-302-001
Program #2

purpose:
This code defines a templated Node class and a templated Linear Linked List (LLL) class.
The Node class represents a node in the linked list and includes functions for setting/getting
the next node, displaying data, and retrieving data. The LLL class represents the linked list
and provides functions for inserting, destroying, concatenating, displaying, and retrieving data.
Templates enable flexibility in using different object types.
*/
#ifndef DATA_TPP
#define DATA_TPP
// ====================== TEMPELATE NODE =======================

//constructor for the node class
template <typename object>
Node<object>::Node() : next(nullptr) {}


// destructor 
template <typename object>
Node<object>::~Node()
{
    next = nullptr;
}

//constructor with paremter
template <typename object>
Node<object>::Node(const object &data) : next(nullptr)
{
    this->data = data;
}

// sets the next node with the passed in node
template <typename object>
void Node<object>::set_next(Node *new_next)
{
    next = new_next;
}

// returns the next node
template <typename object>
Node<object> *&Node<object>::get_next()
{
    return next;
}

// display the infor withint the node
template <typename object>
void Node<object>::display()
{
    cout << data;
}

// retrieve the infor about the data and returns it
template <typename object>
object &Node<object>::retrieve()
{
    return data;
}
// ====================== TEMPELATE LINEAR LINKED LIST =======================

// constructor 
template <typename object>
LLL<object>::LLL() : head(nullptr) {}

// inserts into the LLL
template <typename object>
void LLL<object>::insert(const object &data)
{
    Node<object> *temp = new Node<object>(data);
    if (!head)
    {
        head = temp;
        return;
    }
    temp->set_next(head);
    head = temp;
    return;
}

// destructor
template <typename object>
LLL<object>::~LLL()
{
    if (!head)
    {
        return;
    }
    destroy(head);
}

// deleting fucntion thats get calle within the destructor
template <typename object>
void LLL<object>::destroy(Node<object> *&head)
{
    if (!head)
    {
        return;
    }
    Node<object> *hold = head->get_next();
    delete head;
    head = nullptr;
    head = hold;
    destroy(head);
}

// addition operator overlaoded to insert in LLL
template <typename object>
LLL<object> &LLL<object>::operator+=(const object &data)
{
    insert(data);
    return *this;
}

// displayd the LLL wrapper
template <typename object>
void LLL<object>::display() const
{
    if (!head)
    {
        return;
    }
    display(head);
}

// travels the LLL and displays all the stuff withint 
template <typename object>
void LLL<object>::display(Node<object> *head) const
{
    if (!head)
    {
        return;
    }
    head->display();
    display(head->get_next());
}

//returns the object in the specific nodea wrapper
template <typename object>
shared_ptr<object> LLL<object>::retrieve(int num)
{
    if (!head)
    {
        static object *nullPtr = nullptr;
        return nullptr;
    }
    int start{0};
    return retrieve(head, num, start);
    // return head->retrieve();
}

// gets called in the fucntion above
template <typename object>
shared_ptr<object> LLL<object>::retrieve(Node<object> *head, int num, int start)
{
    if (!head)
    {
        static object *nullPtr = nullptr;
        return nullptr;
    }
    if (start == num)
    {
        return make_shared<object>(head->retrieve());
    }
    return retrieve(head->get_next(), num, ++start);
}
#endif