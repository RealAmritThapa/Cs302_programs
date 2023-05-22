/*
Amrit Thapa
CS 302
Program 1

purpose: These classes represent different types of cars with various
functionalities. They can be used to create instances of cars, check their availability,
display their information, and fetch car information for renters. They also provide specific
information for each type of car, such as electric charging time, towing capacity for utility
 cars, and seat numbers for sports cars.
*/
#include "car_pal.h"

class Cars : public Host
{
public:
    Cars();                                                                                                                // constructor
    ~Cars();                                                                                                               // destructor
    Cars(const Host &host, int year, string make, string color, string model, int cost_to_rent, bool avalibility, int id); // construcror
    virtual void display_car_info() const;                                                                                 // displays all car info
    bool check_car(string user_make, string user_mdoel) const;                                                             // checks if its a matching car
    bool match_car_id(int user_id) const;                                                                                  // checks if it matches id as well
    int is_avaliable();                                                                                                    // cheks if its avaliable
    void fetch_info(Renter &renter);                                                                                       // copines some of it sinfor to renter
    Cars &operator=(const Cars &car);                                                                                      // assignment operator

private:
    int year;
    string make;
    string color;
    string model;
    int cost_to_rent;
    bool avalibility;
    int id;
};

class Electric : public Cars
{
public:
    Electric();                                                                            // constructor
    ~Electric();                                                                           // destructor
    Electric(const Cars &electric, int charge_time, int trave_range, int starting_charge); // constructor
    virtual void display_electric_info() const;                                            // displays all infor about electric car

private:
    int charge_time;
    int trave_range;
    int starting_charge;
};

class Utility : public Cars
{
public:
    Utility();                                                                                         // constructor
    ~Utility();                                                                                        // destructror
    Utility(const Cars &car, int user_towing_capacity, int user_clearance, string user_car_condition); // construcrot
    void display_utility_info() const;                                                                 // displays all the utility information

private:
    int towing_capacity;
    int clearance;
    string car_condition;
};

class Sport : public Cars
{
public:
    Sport();                                                                                     // constructror
    ~Sport();                                                                                    // destructor
    Sport(const Cars &car, int user_seat_number, int user_top_speed, int user_security_deposit); // constructo
    void display_sport_info() const;                                                             // displays all infro about sport cars

private:
    int seat_numbers;
    int top_speed;
    int security_deposit;
};
