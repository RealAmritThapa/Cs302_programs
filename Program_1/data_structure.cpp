/*
Amrit Thapa
CS 302
Program 1
purpose: This code defines a set of classes and their methods to
 manage car and user data in a rental application. The Car_node
  and Renter_node classes are used as elements in the data structures Arr
   and Cll respectively. Arr is an array of car nodes, while Cll is a
   circular linked list of renter nodes. The Host_accounts class manages
    host user accounts in a vector called user_database. The code provides
     methods for inserting, displaying, fetching, and removing cars or renter
      information, as well as managing host accounts, checking account credentials, and saving host data.
*/
#include "car_pal.h"
// Default constructor
Car_node ::Car_node() : next(nullptr){};

// destructor
Car_node::~Car_node()
{
    delete this->car;
    this->car = nullptr;
    next = nullptr;
}

// constructor with paramenters 
Car_node ::Car_node(const Cars *&car) : next(nullptr)
{
    this->car = car;
}

// sets next pointer
void Car_node ::set_next(Car_node *new_next)
{
    next = new_next;
}

// gets the car pointer to the car object 
const Cars *Car_node ::get_car()
{
    return car;
}

// gets the next pointer
Car_node *&Car_node ::get_next()
{
    return next;
}

// Matches car frow when deleteing
bool Car_node ::match_car(string user_name, string password, string user_make, string user_model)
{
    bool choice = false;
    if (car->check_account(user_make, password))
    {
        if (car->check_car(user_make, user_model))
        {
            choice = true;
        }
    }
    return choice;
}
// ****************************

// constructor
Arr ::Arr()
{
    size = 3;
    head = new Car_node *[size];
    for (int i = 0; i < size; i++)
    {
        head[i] = nullptr;
    }
}

// destructor
Arr ::~Arr()
{
    if (!head)
    {
        return;
    }
    int index = 0;
    arr_trav(index);
    delete[] head;
    head = nullptr;
}

// travels the array 
void Arr ::arr_trav(int &index)
{
    if (index == size)
    {
        return;
    }
    destroy(head[index]);
    arr_trav(++index);
}

// deletes alll the nodes in LLL
void Arr ::destroy(Car_node *&head)
{
    if (!head)
    {
        return;
    }
    Car_node *hold = head->get_next();
    delete head;
    head = nullptr;
    head = hold;
    destroy(head);
}

//inserts car into ALL
int Arr ::insert_car(const Cars *&car, int index)
{
    int success = 0;
    Car_node *temp = new Car_node(car);
    if (!head[index])
    {
        head[index] = temp;
        success = 1;
    }
    else
    {
        temp->set_next(head[index]);
        head[index] = temp;
        success = 1;
    }
    return success;
}

// displayys wrapper
int Arr::display_cars(int index)
{

    if (!head[index])
    {
        return 0;
    }
    int count = 1;
    return display_cars(head[index], index, count);
}

// displays cars in a given index with a count
int Arr ::display_cars(Car_node *head, int index, int count)
{
    if (!head)
    {
        return 1;
    }
    if (index == 0)
    {
        const Cars *car = head->get_car();
        const Electric *electric = dynamic_cast<const Electric *>(car);
        if (electric != nullptr)
        {
            cout << "\n**************************************" << endl;
            cout << count << ":" << endl;

            electric->display_car_info();
            electric->display_electric_info();
            electric->display_host_info();
            cout << "\n**************************************" << endl;
            //++count;
        }
    }
    if (index == 1)
    {
        const Cars *car = head->get_car();
        const Utility *utility = dynamic_cast<const Utility *>(car);
        if (utility != nullptr)
        {
            cout << "\n**************************************" << endl;
            cout << count << ":" << endl;

            utility->display_car_info();
            utility->display_utility_info();
            utility->display_host_info();
            cout << "\n**************************************" << endl;
            // ++count;
        }
    }
    if (index == 2)
    {

        const Cars *car = head->get_car();
        const Sport *sport = dynamic_cast<const Sport *>(car);
        if (sport != nullptr)
        {
            cout << "\n**************************************" << endl;
            cout << count << ":" << endl;

            sport->display_car_info();
            sport->display_sport_info();
            sport->display_host_info();
            cout << "\n**************************************" << endl;
            //++count;
        }
    }

    return display_cars(head->get_next(), index, ++count);
};

// Removes a car wtih the matching id 
int Arr ::remove_car(int id, int index)
{
    if (!head[index])
    {
        return 0;
    }
    return remove_car(head[index], id);
}

// This goes in the remove car
int Arr ::remove_car(Car_node *&head, int id)
{
    if (!head)
    {
        return 2;
    }
    if (head->get_car()->match_car_id(id))
    {
        Car_node *hold = head->get_next();
        delete head;
        head = hold;
        return 1;
    }
    return remove_car(head->get_next(), id);
}

// fetches the car and id for renter. this is a wrapper
void Arr ::fetch(int id, Cars &car, int index)
{
    if (!head[index])
    {
        return;
    }
    fetch(id, car, head[index]);
}

// goes inside the function abovce
void Arr ::fetch(int id, Cars &car, Car_node *head)
{
    if (!head)
    {
        return;
    }
    if (head->get_car()->match_car_id(id))
    {
        const Cars *save_car = head->get_car();
        car = *save_car;
        // car.display_account_info();
    }
    fetch(id, car, head->get_next());
}
// *****************************

// constructor
Host_accounts::Host_accounts() {}

// destructor
Host_accounts ::~Host_accounts() {}

// saves host object into a vectro
int Host_accounts ::save_host(const Host &host_account)
{
    user_database.push_back(host_account);

    return 1;
}
// displyas alll the hosts informaiton 
int Host_accounts::display_all_users()
{
    user_database[0].display_account_info();
    return 1;
}

//checks if they have an account taking in name and password
bool Host_accounts ::has_account(string account_name, string account_password, Host &host)
{
    int length = user_database.size();
    bool has_account = false;
    for (int i = 0; i < length; ++i)
    {
        if (user_database[i].check_account(account_name, account_password))
        {
            Host saved_host(user_database[i]);
            host = saved_host;
            has_account = true;
        }
    }
    return has_account;
}
// *******************************************

// Constructor
Renter_node ::Renter_node() : next(nullptr)
{
}

// construcotrj
Renter_node ::Renter_node(const Renter &renter) : Renter(renter), next(nullptr) {}

Renter_node *&Renter_node::get_next()
{
    return next;
}

// destructor
Renter_node ::~Renter_node()
{
    next = nullptr;
}

// sets the next node
void Renter_node ::set_next(Renter_node *new_next)
{
    next = new_next;
}

// gets the rentor for coping in fetch
Renter *Renter_node ::get_renter()
{
    return this;
}
// *******************************************

// constructor
Cll ::Cll() : rear(nullptr) {}

// inserts renter in the CLL
int Cll ::insert(const Renter &renter)
{
    Renter_node *temp = new Renter_node(renter);
    int result = 0;
    if (!rear)
    {
        rear = temp;
        temp->set_next(rear);
        result = 1;
    }
    else
    {
        Renter_node *hold = rear->get_next();
        rear = temp;
        temp->set_next(hold);
        result = 1;
    }
    return result;
}

// displays all the renters. this is a wrapper
int Cll ::display_all_renter()
{
    if (!rear)
    {
        return 0;
    }
    return display_all_renter(rear->get_next());
}

// this goes inside the wrapper abve
int Cll ::display_all_renter(Renter_node *rear)
{
    if (this->rear == rear)
    {
        rear->display_renter_info();
        return 1;
    }

    rear->display_renter_info();
    return display_all_renter(rear->get_next());
}

// fetches info for renter before removeing 
void Cll ::fetch(Renter &renter)
{
    Renter_node *node = rear->get_next();
    renter = *node->get_renter();
    // renter = *rear->get_next();
}

// removes the renter in the order they renter
int Cll ::remove(Renter &renter)
{
    int result = 0;
    if (!rear)
    {
        return result;
    }
    if (rear->get_next() == rear)
    {
        fetch(renter);
        delete rear;
        rear = nullptr;
        result = 1;
    }
    else
    {
        Renter_node *hold = rear->get_next()->get_next();
        fetch(renter);
        delete rear->get_next();
        rear->set_next(hold);
        result = 1;
    }

    return result;
}

// destructior 
Cll ::~Cll()
{
    if (!rear)
    {
        return;
    }
    destroy(rear->get_next());
}

// destroys the CLL
void Cll::destroy(Renter_node *&rear)
{
    Renter_node *hold = rear->get_next();
    if (rear == this->rear)
    {
        delete rear;
        rear = nullptr;
        return;
    }
    delete rear;
    rear = nullptr;
    destroy(hold);
}
