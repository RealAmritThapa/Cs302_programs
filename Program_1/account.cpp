/*
Amrit Thapa
CS 302
Program 1
purpose:
This file implements a car rental system with three classes: Account, Host, and Renter.
 Account serves as the base class for Host and Renter, containing common account
 information and methods. Host inherits from Account, adding hosting_year and
 pickup_location attributes, and methods to display host information. Renter
 also inherits from Account, including details like driver's license,
 car make, model, owner, and car ID, with methods for displaying renter
  information and managing car and driver's license details.
*/
#include "car_pal.h"

// Default constructor
Account ::Account() : name(nullptr)
{
}
// account destructor
Account ::~Account()
{
    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
    }
}

// Account constructor with the variables
Account ::Account(char *account_name, const string &user_name,
                  const string &password, const string &purpose,
                  int bank_value) : name(nullptr),
                                    user_name(user_name),
                                    password(password),
                                    purpose(purpose),
                                    bank_value(bank_value)
{
    name = new char[strlen(account_name) + 1];
    strcpy(name, account_name);
}

// Account constructor that takes an object
Account ::Account(const Account &account) : name(nullptr),
                                            user_name(account.user_name),
                                            password(account.password),
                                            purpose(account.purpose),
                                            bank_value(account.bank_value)
{
    name = new char[strlen(account.name) + 1];
    strcpy(name, account.name);
}

// Assignment operator for account
Account &Account::operator=(const Account &account)
{
    if (this == &account)
        return *this;

    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
    }

    int length = strlen(account.name) + 1;
    name = new char[length];
    strcpy(name, account.name);

    user_name = account.user_name;
    password = account.password;
    purpose = account.purpose;
    bank_value = account.bank_value;

    return *this;
}

// Display function for account
void Account ::display_account_info() const
{
    cout << "\n---- Account Info ----\n"
         << endl;
    cout << "Name: " << name << endl;
    cout << "User name: " << user_name << endl;
    cout << "Password: " << password << endl;
    cout << "Role: " << purpose << endl;
    cout << "Bank Value: "
         << "$ " << bank_value << endl;
}

bool Account ::check_account(string account_name, string account_password) const
{
    bool choice = false;
    if (account_name == user_name && account_password == password)
    {
        choice = true;
    }
    return choice;
}

// ************************************************

// ********************************************

// Default Constructor for host
Host ::Host()
{
}

// destructro for host
Host ::~Host()
{
    hosting_year = 0;
}

// constructor for host that takes an object to upcast
Host ::Host(const Account &account, int hosting_year, string pickup_location) : Account(account),
                                                                                hosting_year(hosting_year),
                                                                                pickup_location(pickup_location)
{
}

// displays the host information
void Host ::display_host_info() const
{
    cout << "\n---- Host Info ----\n"
         << endl;
    cout << "Host Name: " << name << endl;
    cout << "Hosting year: " << hosting_year << " years" << endl;
    cout << "pickup location: " << pickup_location << endl;
}

// Assignment operator for host
Host &Host::operator=(const Host &host)
{
    if (this != &host)
    {
        Account::operator=(host);
        hosting_year = host.hosting_year;
        pickup_location = host.pickup_location;
    }
    else
    {
        return *this;
    }
    return *this;
}
// *******************************************

// constructor For host
Renter ::Renter() : driver_license(nullptr) {}

// constructor for renter that takes in account
Renter ::Renter(const Account &account) : Account(account), driver_license(nullptr) {}

// destructor for renter
Renter ::~Renter()
{
    if (driver_license != nullptr)
    {
        delete[] driver_license;
        driver_license = nullptr;
    }
}

// constructor for renter that take in a renter
// used when making the renter object
Renter ::Renter(const Renter &renter) : Account(renter), driver_license(nullptr), car_make(renter.car_make), car_model(renter.car_model), car_owner(renter.car_owner), car_id(renter.car_id)
{
    driver_license = new char[strlen(renter.driver_license) + 1];
    strcpy(driver_license, renter.driver_license);
}

// constructor for renter
Renter ::Renter(char *drive_license,
                string car_make, string car_model,
                string car_owner,
                const Account &account, int car_id) : Account(account),
                                                      driver_license(nullptr),
                                                      car_make(car_make),
                                                      car_model(car_model),
                                                      car_owner(car_owner),
                                                      car_id(car_id)

{
    driver_license = new char[strlen(drive_license) + 1];
    strcpy(driver_license, drive_license);
}

// Displays all the renter info
void Renter ::display_renter_info() const
{
    // Account :: display_account_info();
    cout << "\n---- Renter Info ----\n"
         << endl;
    cout << "Renter Name: " << name << endl;
    cout << "Drive License: " << driver_license << endl;
    cout << "Make of car renting: " << car_make << endl;
    cout << "Model of car renting: " << car_model << endl;
    cout << "Id of car renting: " << car_id << endl;
    cout << "Car Owner: " << car_owner << endl;
}

// gets the infor from the car when fetching. used for when letting them rent
// a car
void Renter ::get_car_info(string user_car_make, string user_car_model, int user_car_id, string car_owner_name)
{
    car_make = user_car_make;
    car_model = user_car_model;
    car_id = user_car_id;
    car_owner = car_owner_name;
}

// Gets the license from the user to insert in the renter
void Renter ::get_drive_license(char *user_driver_license)
{
    driver_license = new char[strlen(user_driver_license) + 1];
    strcpy(driver_license, user_driver_license);
}

// Renter assignment operator
Renter &Renter ::operator=(const Renter &renter)
{
    if (this == &renter)
    {
        return *this;
    }
    Account ::operator=(renter);
    if (driver_license != nullptr)
    {
        delete[] driver_license;
        driver_license = nullptr;
    }
    driver_license = new char[strlen(renter.driver_license) + 1];
    strcpy(driver_license, renter.driver_license);
    car_make = renter.car_make;
    car_model = renter.car_model;
    car_owner = renter.car_owner;
    car_id = renter.car_id;
    return *this;
}