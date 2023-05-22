/*
Amrit Thapa
CS 302
Program 1
Purpose:
The provided code defines three classes that represent a car rental system.
 The Account class is a base class for hosts and renters, while Host adds
 information about hosting and Renter adds information about a rented car.
  The classes have constructors, destructors, and member functions to display
  information and verify account credentials. Some functions indirectly return
  values through modified parameters passed by reference, and the check_account()
  function in the Account class returns a bool value
*/
#include "car_pal.h"

class Account
{
public:
    // default constructor
    Account();
    // destructor
    virtual ~Account();
    // parameterized constructor
    Account(char *name, const string &user_name, const string &password, const string &purpose, int bank_account);
    // copy constructor
    Account(const Account &account);
    // assignment operator
    Account &operator=(const Account &account);
    // display account information
    void display_account_info() const;
    // Checks if account name and password match current account that 
    // will be called in the vector
    bool check_account(string account_name, string account_password) const;

protected:
    char *name;

private:
    string user_name; // used for verifaction
    string password; // used for verifactition
    string purpose;
    int bank_value;
};

class Host : public Account
{
public:
    // default constructor
    Host();
    //destructor
    ~Host();
    // parameterrized constructor
    Host(const Account &account, int hosting_year, string pickup_location);
    //display host information
    void display_host_info() const;
    // assignment operator
    Host &operator=(const Host &host);

private:
    int hosting_year;
    string pickup_location;
};

class Renter : public Account
{
public:
    //default constructor
    Renter();
    Renter(const Account &account);
    // destructor
    ~Renter();
    // assignment operator
    Renter &operator=(const Renter &renter);
    // copy constructor
    Renter(const Renter &renter);
    // gets license
    void get_drive_license(char *driver_license);
    // parametrized constructor
    Renter(char *drive_license, string car_make, string car_model, string car_owner, const Account &account, int car_id);
    // used when fetching info from the database
    void get_car_info(string car_make, string car_model, int car_id, string car_owner_info);
    // displays renter information
    void display_renter_info() const;

private:
    char *driver_license;
    string car_make;
    string car_model;
    string car_owner;
    int car_id;
};
