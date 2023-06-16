"""
Name: Amrit Thapa
cs302-001-Program4
6-14-23
purpose: The code provides functionality for managing reservations across different venues, including hotels, spas, and restaurants. It allows users to add venue names, make reservations, display reservations, and retrieve reservations by venue name. The program utilizes a 2-3 tree data structure for efficient storage and retrieval of reservations.
"""
from .data_structure.reservation_manager import *
from .classes.hotel_reservation import *
from .classes.resturant_reservation import *
from .classes.spa_reservation import *

# return the resturant objects to be store in the 2-3 tree


def get_restaurant_info(manager):
    my_list = manager.return_size()
    costumer_name = input("What is your name: ")
    manager.display_venue("restaurant")
    venue_index = int(input("Enter the number of your choice"))
    manager.display_time("restaurant")
    table_number = int(input("Choose your number: "))
    while table_number > my_list[2]:
        table_number = int(input("sorry that too big. Try to enter again => "))
    guest_number = int(input("how many people: "))
    time = input("what is the time of reservation: ")
    restaurant = manager.get_restaurant(
        venue_index, costumer_name, table_number, guest_number, time)
    return restaurant


# return the hotel objects to be store in the 2-3 tree
def get_hotel_info(manager):
    my_list = manager.return_size()
    costumer_name = input("What is your name: ")
    manager.display_venue("hotel")
    venue_index = int(input("Enter the number of your choice: "))
    manager.display_time("hotel")
    check_in = int(input("Enter the number of your check in data: "))
    while check_in > my_list[0]:
        check_in = int(input("sorry that too big. Try to enter again => "))
    check_out = int(input("Enter the number of your check out data: "))
    while check_out > my_list[0]:
        check_out = int(input("sorry that too big. Try to enter again => "))
    room_number = int(input("what is your room number: "))
    return manager.get_hotel(venue_index, costumer_name, check_in, check_out, room_number)


# return the spa objects to be store in the 2-3 tree
def get_spa_info(manager):
    my_list = manager.return_size()
    costumer_name = input("What is your name: ")
    manager.display_venue("spa")
    venue_index = int(input("Enter the number of your choice: "))
    manager.display_time("spa")
    time = int(input("Enter the number of your time: "))
    manager.display_time("hotel")
    check_in = int(input("Enter the number of your date: "))
    while check_in > my_list[0]:
        check_in = int(input("sorry that too big. Try to enter again => "))
    service_type = input("What is your service type: ")
    therapist_name = input("what is the name of your therapist: ")
    return manager.get_spa(venue_index, costumer_name, time, check_in, service_type, therapist_name)


def main_menu():
    response = 0
    print("\nMENU")
    print("1: Add venue name ")
    print("2: Reserve a hotel")
    print("3: Reserve a spa")
    print("4: Reserve a Restaurant")
    print("5: Display All")
    print("6: Retrieve")
    print("7: Quit")
    while True:
        try:
            choice = int(input("Type in your input: "))
            response = choice
            break
        except ValueError:
            print("Invalid Input. Try again ")
    return response


def main():
    manager = start_managing()
    tree = TwoThreeTree()
    choice = 0
    while choice != 7:
        choice = main_menu()
        if (choice == 1):
            get_venue_name(manager)
        elif choice == 2:
            hotel = get_hotel_info(manager)
            tree.insert(hotel)
        elif choice == 3:
            spa = get_spa_info(manager)
            tree.insert(spa)
        elif choice == 4:
            restaurant = get_restaurant_info(manager)
            tree.insert(restaurant)
        elif choice == 5:
            tree.display()
        elif choice == 6:
            print("here are all you reserevation by name")
            tree.display(None, 2)
            venue_name = input("Type in the name of the venue =>  ")
            venue = tree.retrieve(venue_name)
            print("here is you retrieved info")
            venue.display()
            if venue:
                print("Retrieve success")


if __name__ == "__main__":
    main()
