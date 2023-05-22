/*
Amrit Thapa
CS 302
Program 1
Purpose: The purpose of this file is to define the class Car_pal which
represents the main interface of a car sharing application. It includes
functions for creating and managing user accounts, managing car listings,
 and handling the rental process. The class makes use of other classes defined
 in separate header files, including Account, Host, Renter, Cars, Electric, Utility,
  Sport, Arr, Cll, and Host_accounts. The class data members include variables to
   keep track of the size of the database, whether any cars are currently listed,
   and the ID of the user currently logged in.
*/
#ifndef CAR_PAL_H
#define CAR_PAL_H

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <memory>
using namespace std;
#include "account.h"
#include "cars.h"
#include "data_structure.h"

class Car_pal
{
public:

    Car_pal(); // constructor
    ~Car_pal(); // destructor 
    int main_menu(); // shows main menus
    unique_ptr<Account> new_account(); // makes new account 
    Host new_host(); // makes new host
    void new_renter(); // makes new renter
    Cars new_car(); // makes new car
    Electric add_electric(); // adds electric to ARR
    Utility add_utility(); // adds utility to ARR
    Sport add_sport(); // adds sports to ARR
    void check_account(Host &host); // Checks account
    void host_car(); // shorws in main menuts
    int display_car(); // displas all cars
    int host_menu(); // menuts for the host
    void remove_host(); // removes the host
    void display_renter(); // displays all the renter
    void remove_renter(); // removes the renters

private:
    Arr data_base;
    Cll receipt;
    int size;
    int has_cars;
    Host_accounts host_account;
    bool has_account;
    int id;
};
#endif
