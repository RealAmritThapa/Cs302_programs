/*
Amrit Thapa
CS 302
Program 1
purpose: This file defines several classes for managing cars,
 renters, and hosts. Arr allows for insertion, deletion, and fetching of
 cars, while Cll does the same for renters. Host_accounts provides account
 management for hosts. Car_node and Renter_node are node classes used in the Arr and Cll implementations.
*/
#include "car_pal.h"

class Car_node : public Cars
{
public:
    Car_node();
    ~Car_node();
    Car_node(const Cars *&car);
    void set_next(Car_node *new_next);
    bool match_car(string user_name, string password, string user_make, string user_model);
    Car_node *&get_next();
    const Cars *get_car();

private:
    const Cars *car;
    Car_node *next;
};

class Arr
{
public:
    Arr();
    ~Arr();
    int insert_car(const Cars *&car, int index);
    int display_cars(int index);
    int remove_car(int id, int index);
    void fetch(int id, Cars &car, int index);

private:
    int display_cars(Car_node *next, int index, int count);

    void arr_trav(int &index);
    void destroy(Car_node *&head);
    void fetch(int id, Cars &car, Car_node *head);
    int remove_car(Car_node *&head, int id);
    int size;
    Car_node **head;
};

class Host_accounts
{
public:
    Host_accounts();
    ~Host_accounts();
    int display_all_users();
    int save_host(const Host &account);
    bool has_account(string acocunt_name, string account_password, Host &host);

private:
    vector<Host> user_database;
};

class Renter_node : public Renter
{
public:
    Renter_node();
    ~Renter_node();
    Renter_node(const Renter &renter);
    Renter_node *&get_next();
    void set_next(Renter_node *new_next);
    // void display_info();
    Renter *get_renter();

private:
    Renter_node *next;
};

class Cll
{
public:
    Cll();
    ~Cll();
    int insert(const Renter &renter);
    int display_all_renter();
    void fetch(Renter &renter);
    int remove(Renter &renter);

private:
    Renter_node *rear;
    void destroy(Renter_node *&rear);
    int display_all_renter(Renter_node *rear);
};