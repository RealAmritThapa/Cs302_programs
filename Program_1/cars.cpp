/*
Amrit Thapa
CS 302
Program 1
purpose: This code defines a class hierarchy for cars, including the Cars, Electric, Utility,
and Sport classes, with the latter three inheriting from Cars. The Cars class itself
 is a subclass of the Host class. Each class has constructors, destructors, and
 methods for displaying relevant information. The Electric, Utility, and Sport
  classes include additional attributes and methods specific to their respective types of cars.
*/
#include "car_pal.h"

// Default constructor
Cars ::Cars(){};

// Destructor
Cars ::~Cars()
{
    year = 0;
    cost_to_rent = 0;
    id = 0;
}

// constructor with paramenters
Cars ::Cars(const Host &host, int year, string make, string color,
            string model, int cost_to_rent, bool avalibility, int id) : Host(host),
                                                                        year(year),
                                                                        make(make),
                                                                        color(color),
                                                                        model(model),
                                                                        cost_to_rent(cost_to_rent),
                                                                        avalibility(avalibility), id(id)
{
}

// displays alll the information about the car
void Cars ::display_car_info() const
{

    cout << "+++++++ I D +++++++" << endl;
    cout << "Car ID =>>> " << id << endl;
    cout << "+++++++++++++++++++++++++++++" << endl;
    cout << "\n---- General Car Info ----\n"
         << endl;
    cout << "Year: " << year << " years" << endl;
    cout << "Make: " << make << endl;
    cout << "Color: " << color << endl;
    cout << "Model: " << model << endl;
    cout << "Cost to rent: "
         << "$ " << cost_to_rent << endl;
}

// Verifies the car is the right car
bool Cars::check_car(string user_make, string user_model) const
{
    bool choice = false;
    if (user_make == make && user_model == model)
    {
        choice = true;
    }
    return choice;
}

// checks if the car is abaliable or not
int Cars ::is_avaliable()
{
    if (avalibility)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// Matched the id for when renters want to rent
bool Cars::match_car_id(int user_id) const
{
    bool choice = false;
    if (user_id == id)
    {
        choice = true;
    }
    return choice;
}

// fetchs info to insert in the renter
void Cars ::fetch_info(Renter &renter)
{
    renter.get_car_info(make, model, id, name);
}

// assignment operator
Cars &Cars ::operator=(const Cars &car)
{
    if (this != &car)
    {
        Host::operator=(car);
        year = car.year;
        make = car.make;
        color = car.color;
        model = car.model;
        cost_to_rent = car.cost_to_rent;
        avalibility = car.avalibility;
        id = car.id;
    }
    else
    {
        return *this;
    }
    return *this;
}
// ***************************************

// Constructor
Electric ::Electric(){};

// Destructor
Electric ::~Electric()
{
    charge_time = 0;
    trave_range = 0;
    starting_charge = 0;
};

// construcrot with paramenteres
Electric ::Electric(const Cars &electric, int charge_time, int trave_range,
                    int starting_charge) : Cars(electric),
                                           charge_time(charge_time),
                                           trave_range(trave_range),
                                           starting_charge(starting_charge)
{
}
// Displays all the informaiton for the vechials 
void Electric ::display_electric_info() const
{
    cout << "\n---- Electric Info ----\n"
         << endl;

    cout << "Charge time: " << charge_time << " minutes" << endl;
    cout << "Travel range: " << trave_range << " miles" << endl;
    cout << "Starting charge: " << starting_charge << " %" << endl;
}


// **************************************

// constructor
Utility ::Utility() {}

//destructor
Utility ::~Utility()
{
    towing_capacity = 0;
    clearance = 0;
}

// constructor with parameters
Utility ::Utility(const Cars &car, int user_towing_capacity, int user_clearance, string user_car_condition) : Cars(car), towing_capacity(user_towing_capacity), clearance(user_clearance), car_condition(user_car_condition) {}

// displays all the information for utility
void Utility ::display_utility_info() const
{
    cout << "\n---- Utility Info ----\n"
         << endl;
    cout << "Towing capacity: " << towing_capacity << " lbs" << endl;
    cout << "Clearance: " << clearance << " feet" << endl;
    cout << "Car condition: " << car_condition << endl;
}
// **************************************

// Constructor
Sport ::Sport(){};

// destructor
Sport ::~Sport()
{
    seat_numbers = 0;
    top_speed = 0;
    security_deposit = 0;
};

// constructor with parameters
Sport ::Sport(const Cars &car, int user_seat_number,
              int user_top_speed, int user_security_deposit) : Cars(car),
                                                               seat_numbers(user_seat_number),
                                                               top_speed(user_top_speed),
                                                               security_deposit(user_security_deposit)
{
}

// displays all the information about sports cars
void Sport::display_sport_info() const
{
    cout << "\n---- Sport Info ----\n"
         << endl;
    cout << "Seat numbers: " << seat_numbers << endl;
    cout << "Top speed: " << top_speed << " mph" << endl;
    cout << "Required Security deposit: "
         << "$ " << security_deposit << endl;
}