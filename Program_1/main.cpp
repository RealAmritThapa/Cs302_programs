/*
Amrit Thapa
CS 302
Program 1

*/
#include "car_pal.h"

int main()
{
    int choice = 0;
    Car_pal car_pal;
    while (choice != 10)
    {
        choice = car_pal.main_menu();
        switch (choice)
        {
        case 1:
            car_pal.host_car();
            break;

        case 2:
            car_pal.new_renter();
            break;

        case 3:
            car_pal.remove_host();
            break;

        case 4:
            car_pal.display_car();
            break;

        case 5:
            car_pal.display_renter();
            break;

        case 6:
            car_pal.remove_renter();
            break;

        default:
            cout << "\nProgram ending" << endl;
            break;
        }
    }
    return 0;
}
