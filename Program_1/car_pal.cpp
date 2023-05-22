/*
Amrit Thapa
CS 302
Program 1

Purpose: This file is a part of a car rental management program called "Car Pal".
The program allows users to create an account, host a car, rent a car,
remove a car, display available cars, and display renters. The file contains
 a Car_pal class that manages various car types like Electric, Utility, and Sport,
  as well as host and renter accounts. The class provides functions to create
  and manage accounts, add and display cars, manage the renting process, and remove cars.
*/
#include "car_pal.h"

// constructor for the car pal class
Car_pal ::Car_pal()
{
    size = 100;
    has_account = false;
    has_cars = 0;
    id = 1;
}

// destructor for the car pal class
Car_pal::~Car_pal()
{
}

// Creates a new account by prompting the user for their information
// and returning a unique pointer to the created account object
unique_ptr<Account> Car_pal ::new_account()
{
    char name[20];
    string user_name;
    string password;
    string purpose;
    int bank_value = 0;

    cout << "\n====== General Information ======" << endl;
    cout << "\nWhat is your name? => ";
    cin.get(name, 20, '\n');
    cin.ignore(size, '\n');
    cout << "What would you like to be your user name? => ";
    cin >> user_name;
    cin.ignore(size, '\n');
    cout << "Please pick a password => ";
    cin >> password;
    cin.ignore(size, '\n');
    purpose = "Host"; // might change
    cout << "What is a rough estimate of you bank value? =>$ ";
    cin >> bank_value;
    cin.ignore(size, '\n');

    unique_ptr<Account> new_account(new Account(name, user_name, password, purpose, bank_value));
    return new_account;
}

// Prompts the user to enter their account information and checks if it exists
// If it exists, sets has_account to true, otherwise prompts the user to create a new account
void Car_pal ::check_account(Host &host)
{
    string user_name;
    string password;
    cout << "\nWhat is your user name? => ";
    cin >> user_name;
    cin.ignore(100, '\n');
    cout << "what is you passwrod? => ";
    cin >> password;
    cin.ignore(100, '\n');
    if (host_account.has_account(user_name, password, host))
    {
        cout << "\nBeautiful, welcome back. Lets add some info about the car " << user_name << endl;
        has_account = true;
    }
    else
    {
        cout << "\nLooks like you do not have an account. Lets make one" << endl;
    }
}

// Displays the main menu and prompts the user to choose an option
// Returns the user's choice as an integer
int Car_pal ::main_menu()
{
    int choice = 0;
    cout << "\n====== M E N U ======" << endl;
    cout << "\nWelcome to the Car Pal" << endl;
    cout << "1: I want to host" << endl;
    cout << "2: I want to rent" << endl;
    cout << "3: Remove a car" << endl;
    cout << "4: Display cars" << endl;
    cout << "5: Display Renters" << endl;
    cout << "6: Remove Renter" << endl;
    cout << "10: Close application" << endl;
    cout << "Please chose an option =>  ";
    cin >> choice;
    cin.ignore(size, '\n');
    return choice;
}

// Displays the host menu and prompts the user to choose an option
// Returns the user's choice as an integer
int Car_pal ::host_menu()
{
    int choice = 0;
    cout << "\nDo you have an account with us? " << endl;
    cout << "1: No I want to make a hosting acocunt " << endl;
    cout << "2: Yes I do have a hosting account here " << endl;
    cout << "Please choose an option =>  ";
    cin >> choice;
    cin.ignore(size, '\n');
    return choice;
}

// Creates a new car object by prompting the user for its information
// and returning the created object
Cars Car_pal ::new_car()
{
    int car_year;
    string car_make;
    string car_color;
    string car_model;
    int car_rent_cost;
    bool car_avalibility;
    Host host;
    int car_id = id;
    int choice = 0;
    choice = host_menu();
    if (choice == 2)
    {
        check_account(host);
        if (!has_account)
        {
            host = new_host();
        }
    }
    else
    {
        host = new_host();
    }

    cout << "\n====== General Car Information ======" << endl;
    cout << "\nPlease enter the year of the car: ";
    cin >> car_year;
    cin.ignore(size, '\n');

    cout << "Please enter the make of the car: ";
    cin >> car_make;
    cin.ignore(size, '\n');

    cout << "Please enter the color of the car: ";
    cin >> car_color;
    cin.ignore(size, '\n');

    cout << "Please enter the model of the car: ";
    cin >> car_model;
    cin.ignore(size, '\n');

    cout << "Please enter the rental cost per day $: ";
    cin >> car_rent_cost;
    cin.ignore(size, '\n');

    car_avalibility = 1;

    Cars car(host, car_year, car_make, car_color, car_model, car_rent_cost, car_avalibility, car_id);
    return car;
}

// Creates a new host object by prompting the user for its information
// and returns the created object
Host Car_pal ::new_host()
{
    int hosting_years;
    string drop_zone;
    unique_ptr<Account> account = new_account();

    cout << "\n====== Host Information ======" << endl;
    cout << "\nHow many years have you been hosting? => ";
    cin >> hosting_years;
    cin.ignore(size, '\n');
    cout << "Where do you want the costumer to pick up the car? => ";
    cin >> drop_zone;
    cin.ignore(size, '\n');

    Host host(*account, hosting_years, drop_zone);
    host_account.save_host(host);
    return host;
}

// Creates a new electric car object by prompting the user for its information
// and returns the created object
Electric Car_pal ::add_electric()
{
    Cars car;
    int charge_time;
    int trave_time;
    int starting_charge;
    car = new_car();

    cout << "\n====== Car Information ======" << endl;
    cout << "\nWhat charge_time (minutes) => ";
    cin >> charge_time;
    cin.ignore(size, '\n');
    cout << "What is the max distace this car travel on full charge (mph)=> ";
    cin >> trave_time;
    cin.ignore(size, '\n');
    cout << "what is the starting charge (%) => ";
    cin >> starting_charge;
    cin.ignore(size, '\n');
    Electric electric(car, charge_time, trave_time, starting_charge);
    return electric;
}

// Creates a new utility car object by prompting the user for its information
// and returns the created object
Utility Car_pal ::add_utility()
{
    Cars car;
    int towing_capacity;
    int clearance;
    string car_condition;

    car = new_car();
    cout << "\n====== Car Information ======" << endl;
    cout << "\nWhat is the towing capacity (lbs) => ";
    cin >> towing_capacity;
    cin.ignore(size, '\n');
    cout << "What is the clearance (feet) => ";
    cin >> clearance;
    cin.ignore(size, '\n');
    cout << "What is the condition of the car => ";
    cin >> car_condition;
    cin.ignore(size, '\n');

    Utility utility(car, towing_capacity, clearance, car_condition);
    return utility;
}

// similar to fucntion above except this time its with sport car
Sport Car_pal ::add_sport()
{
    Cars car;
    int seat_numbers;
    int top_speed;
    int security_deposit;
    car = new_car();

    cout << "\n====== Car Information ======" << endl;
    cout << "Enter the number of seats: ";
    cin >> seat_numbers;
    cin.ignore(size, '\n');

    cout << "Enter the top speed(mph): ";
    cin >> top_speed;
    cin.ignore(size, '\n');

    cout << "Enter the security deposit($): ";
    cin >> security_deposit;
    cin.ignore(size, '\n');
    Sport sport(car, seat_numbers, top_speed, security_deposit);
    return sport;
}

// Prompts the user to choose a type of car to host and
// creates a new car object of that type
// If successful, adds the car to the database and
// increments the number of cars the application has
void Car_pal::host_car()
{
    int index = 0;
    cout << "\nwhat type of car would you like to host? " << endl;
    cout << "1: Electric " << endl;
    cout << "2: Utility " << endl;
    cout << "3: Sport " << endl;
    cout << "Please choose an option =>  ";
    cin >> index;
    cin.ignore(size, '\n');

    if (index == 1)
    {
        Electric *electric = new Electric;
        *electric = add_electric();
        const Cars *car = electric;
        index = index - 1;
        cout << "\n========== I N S E R T car =========\n " << endl;
        if (!data_base.insert_car(car, index))
        {
            cerr << "not successful" << endl;
        }
        else
        {
            cout << "succssful" << endl;
            ++has_cars;
        }
    }
    else if (index == 2)
    {
        Utility *utility = new Utility;
        *utility = add_utility();
        index = index - 1;
        const Cars *car = utility;
        cout << "\n========== I N S E R T car =========\n " << endl;

        if (!data_base.insert_car(car, index))
        {
            cerr << "not successful" << endl;
        }
        else
        {
            cout << "succssful" << endl;
            ++has_cars;
        }
    }
    else if (index == 3)
    {
        Sport *sport = new Sport;
        *sport = add_sport();
        const Cars *car = sport;
        index = index - 1;

        cout << "\n========== I N S E R T car =========\n " << endl;
        if (!data_base.insert_car(car, index))
        {
            cerr << "not successful" << endl;
        }
        else
        {
            cout << "succssfull" << endl;
            ++has_cars;
        }
    }
    cout << "Number of Cars: " << has_cars << endl;
    cout << "\n ================================" << endl;
    ++id;
}

// displays the selected cars in the data base
int Car_pal ::display_car()
{
    int index = 0;
    cout << "1: Electric " << endl;
    cout << "2: Utility " << endl;
    cout << "3: Sport " << endl;
    cout << "Please choose an option =>  ";
    cin >> index;
    cin.ignore(size, '\n');
    index = index - 1;

    cout << "\n========== D I S P L A Y car =========\n " << endl;
    if (!data_base.display_cars(index))
    {
        cerr << "No cars in store" << endl;
        index = 10;
    }
    return index;
}

// Prompts the user to choose a car to rent and creates a
// new renter object associated with that car
// If successful, adds the renter to the receipt
void Car_pal ::new_renter()
{
    char driver_license[size];
    string car_renting, car_owner;
    Cars car;
    int index, car_id = 0;
    if (has_cars != 0)
    {
        unique_ptr<Account> account = new_account();
        cout << "\nwhat type of car would you like to rent? " << endl;
        index = display_car();
        cout << "Enter the car id you would like to rent: ";
        cin >> car_id;
        cin.ignore(size, '\n');
        cout << "Enter your driver's license: ";
        cin.get(driver_license, 100, '\n');
        cin.ignore(size, '\n');
        data_base.fetch(car_id, car, index);
        Renter renter(*account);
        car.fetch_info(renter);
        renter.get_drive_license(driver_license);

        cout << "\n------  R E N T status -------" << endl;
        if (!receipt.insert(renter))
        {
            cerr << "Renter Not sucessfull" << endl;
        }
        else
        {
            cout << "Renter Added" << endl;
        }
    }
    else
    {
        cout << "\n------  R E N T status -------" << endl;
        cout << "Sorry there are no cars to rent atm" << endl;
    }
}

// Displays all the current renters
void Car_pal ::display_renter()
{
    cout << "\n========== D I S P L A Y renter =========\n " << endl;
    if (!receipt.display_all_renter())
    {
        cerr << "Sorry there are no renters to display " << endl;
    }
}

// Removes the renter from the revieps. but copies the removed
// renter in a object that is fasted in for future use
void Car_pal::remove_renter()
{

    cout << "\n========== R E M O V E renter =========\n " << endl;
    Renter renter;
    int result = receipt.remove(renter);
    if (!result)
    {
        cerr << "sorry remove renter not success" << endl;
    }
    else
    {
        cout << "Remove success" << endl;
    }
}

// Prompts the user to choose a car to remove from the database and removes the car
// If successful, decrements the number of cars the host has
void Car_pal ::remove_host()
{
    int car_id = 0;
    int index = 0;
    cout << "\nwhat type of car would you like to remove? " << endl;

    index = display_car();
    if (index != 10)
    {
        cout << "\n========== R E M O V E car =========\n " << endl;
        cout << "Enter the car id you would like to remove: ";
        cin >> car_id;
        cin.ignore(size, '\n');
        int result = data_base.remove_car(car_id, index);
        if (result == 0)
        {
            cerr << "No Cars in store " << endl;
        }
        if (result == 2)
        {
            cerr << "Car not found" << endl;
        }
        else
        {
            cout << "successful" << endl;
            --has_cars;
        }
        cout << "\n ================================" << endl;
    }
}
