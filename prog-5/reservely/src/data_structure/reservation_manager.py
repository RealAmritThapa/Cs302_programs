"""
Name: Amrit Thapa
cs302-001-Program4
6-14-23
porpose:The ReservationManager class acts as a centralized system for managing 
reservations across various venues. It handles venue-specific operations, such as 
adding venue names, loading existing names from a file, and creating reservation objects 
for hotels, spas, and restaurants. By utilizing a 2-3 tree data structure, it ensures efficient 
storage and retrieval of reservations. With time slot management and unique reservation IDs, the 
class provides comprehensive functionality for organizing reservations and facilitating venue-related tasks. 
"""
import numpy as np
from datetime import date, timedelta
import csv
# from reservely.src.classes.hotel_reservation import Hotel
# from reservely.src.classes.resturant_reservation import Restaurant
# from reservely.src.classes.spa_reservation import Spa
from ..classes.reservation import Reservation
from ..classes.hotel_reservation import Hotel
from ..classes.resturant_reservation import Restaurant
from ..classes.spa_reservation import Spa


class ReservationManager:
    # Initializes the ReservationManager object with empty time slots for different venues and initializes empty lists for venue names and reservation ID.
    def __init__(self):
        self.time_slots = {
            'hotel': np.array([]),
            'spa': np.array([]),
            'restaurant': np.array([1, 2, 3, 4, 5])
        }
        self.hotel_venues = []
        self.spa_venues = []
        self.restaurant_venues = []
        self.reservation_id = 1

    # Returns the size of the time slots for each venue type as a list
    def return_size(self):
        my_list = [len(self.time_slots["hotel"]), len(
            self.time_slots["spa"]), len(self.time_slots["restaurant"])]
        return my_list

    # Loads venue names from a file and populates the corresponding venue lists
    def load_file(self):
        with open('reservely/src/data_structure/venues.csv', 'r') as venue_file:
            reader = csv.reader(venue_file)
            next(reader)
            for row in reader:
                if row[0] == 'hotel':
                    self.hotel_venues.append(row[1])
                if row[0] == 'spa':
                    self.spa_venues.append(row[1])
                if row[0] == 'restaurant':
                    self.restaurant_venues.append(row[1])

    # adds data to time slots array
    def add_time_slot(self):
        start_date = date(2023, 6, 1)
        end_date = date(2023, 12, 31)
        delta = timedelta(days=1)
        while start_date <= end_date:
            self.time_slots['hotel'] = np.append(
                self.time_slots['hotel'], start_date.strftime("%m-%d-%Y"))
            start_date += delta
        self.time_slots['spa'] = np.append(
            self.time_slots['spa'], [f"{hour}:00 - {hour + 1}:00" for hour in range(9, 21)])

    # adds venue name to the list
    def add_venue_name(self, venue_name, venue_type):
        if venue_type == 'hotel':
            self.hotel_venues.append(venue_name)
        elif venue_type == 'spa':
            self.spa_venues.append(venue_name)
        elif venue_type == 'restaurant':
            self.restaurant_venues.append(venue_name)

    # loops throught the dictionary and check if venue exits
    def venue_exists(self, venue_type):
        if venue_type in self.time_slots:
            return True
        raise ValueError(
            "The venue type does not exist or is not available in the given time slot. Try again")

    # loops though the selected venue type and displays the contents
    def display_time(self, venue_type):
        time_slot = self.time_slots[venue_type]
        i = 1
        for slot in time_slot:
            print(f"{i}: {slot}")
            i = i + 1

    # dipslay all the venues that are avaliable to reserve
    def display_venue(self, venue_type):
        i = 1
        if venue_type == 'hotel':
            for venue in self.hotel_venues:
                print(f"{i}: {venue}")
                i = i + 1
        if venue_type == 'spa':
            for venue in self.spa_venues:
                print(f"{i}: {venue}")
                i = i + 1
        elif venue_type == 'restaurant':
            for venue in self.restaurant_venues:
                print(f"{i}: {venue}")
                i = i + 1

    # takes info and puts it into a hotel object and returns to be used in main.py
    def get_hotel(self, venue_index, costumer_name, check_in_index, check_out_index, room_number):
        venue_name = self.hotel_venues[venue_index-1]
        reserve = Reservation(
            venue_name, costumer_name, self.reservation_id)
        check_in = self.time_slots['hotel'][check_in_index-1]
        check_out = self.time_slots['hotel'][check_out_index-1]
        hotel = Hotel(reserve, room_number, check_in, check_out)
        self.reservation_id += 1
        return hotel

    # takes info and puts it into a restuarant object and returns to be used in main.py
    def get_restaurant(self, venue_index, costumer_name, table_number, number_guests, time):
        venue_name = self.restaurant_venues[venue_index-1]
        table_number = self.time_slots["restaurant"][table_number - 1]
        reserve = Reservation(
            venue_name, costumer_name, self.reservation_id)
        restaurant = Restaurant(reserve, table_number, time, number_guests)
        self.reservation_id += 1
        return restaurant

    # takes info and puts it into a spa object and returns to be used in main.py
    def get_spa(self, venue_index, costumer_name, time, check_in, service_type, therapist_name):
        venue_name = self.spa_venues[venue_index-1]
        reserve = Reservation(
            venue_name, costumer_name, self.reservation_id)
        time = self.time_slots["spa"][time - 1]
        check_in = self.time_slots['hotel'][check_in-1]
        spa = Spa(reserve, check_in, time, service_type, therapist_name)
        self.reservation_id += 1
        return spa

    # checks for duplicates of venue name
    def duplicates(self, venue_type, venue_name):
        if venue_type == "hotel":
            if venue_name in getattr(self, venue_type + "_venues"):
                raise ValueError("Name already exists. Please try again. ")

# menu do display the types


def reservation_menu():
    print("1: Hotel")
    print("2: Spa")
    print("3: Restaurant")

# gets venue names from the user and saves it to correct spots


def get_venue_name(manager):
    response = 1
    while response == 1:
        print("What type of venue would you like to add?\n")
        reservation_menu()
        while True:
            venue_type = input("Type in the name of the type:  ").lower()
            try:
                manager.venue_exists(venue_type)
                choice = 1
                while choice == 1:
                    while True:
                        try:
                            temp_name = input(
                                "Name of the venue name: ").lower()
                            manager.duplicates(venue_type, temp_name)
                            venue_name = temp_name
                            break
                        except ValueError as e:
                            print(e)

                    manager.add_venue_name(venue_name, venue_type)
                    print("Perfect! Venue name insert success")
                    while True:
                        try:
                            choice = int(
                                input("Type 1 if you like to continue adding venue names or type any other number to stop adding: "))
                            break
                        except ValueError:
                            print("Invalid Input. Try again")
                break
            except ValueError as e:
                print(str(e))
        while True:
            try:
                response = int(input(
                    "Type 1 if you would like to add more or any other number to stop adding: "))
                break
            except ValueError:
                print("Invalid Input. Try Again")

# display all the venue names chosen by the user


def display_venue_name(manager):
    print("Here is what we have")
    reservation_menu()
    venue_type = input("Type in the name of what you would like to see: ")
    manager.display_venue(venue_type)

# displays time slots of type chosen by the user


def display_time_slots(manager):
    reservation_menu()
    venue_type = input("Type in the type of your")

# loads all teh data with presaved type and time slots


def start_managing():
    manager = ReservationManager()
    manager.load_file()
    manager.add_time_slot()
    return manager


class TreeNode:
    # node constructor
    def __init__(self, leaf=False):
        self.leaf = leaf
        self.keys = []
        self.child = []


class TwoThreeTree:
    # constructreo for tree class
    def __init__(self):
        self.root = TreeNode(True)

    # wrapper function for insert
    def insert(self, reservation):
        key = reservation
        venue_name = reservation.get_venue_name()
        if len(self.root.keys) == 2:
            temporary_node = TreeNode()
            temporary_node.child.append(self.root)
            self.root = temporary_node
            self.split_child(temporary_node, 0)
            self._insert(temporary_node, key, venue_name)
        else:
            self._insert(self.root, key, venue_name)

    # insert that takes venue name and key which is the object
    def _insert(self, node, key, venue_name):
        i = len(node.keys) - 1
        if node.leaf:
            node.keys.append(key)
            while i >= 0 and venue_name < node.keys[i].get_venue_name():
                node.keys[i+1] = node.keys[i]
                i -= 1
            node.keys[i+1] = key
        else:
            while i >= 0 and venue_name < node.keys[i].get_venue_name():
                i -= 1
            i += 1
            if len(node.child[i].keys) == 2:
                self.split_child(node, i)
                if venue_name > node.keys[i].get_venue_name():
                    i += 1
            self._insert(node.child[i], key, venue_name)

    # splits a child node of the parant node in 2-3 trees
    def split_child(self, parent_node, index):
        target_node = parent_node.child[index]
        new_node = TreeNode(target_node.leaf)
        parent_node.child.insert(index+1, new_node)
        parent_node.keys.insert(index, target_node.keys[1])
        new_node.keys.append(target_node.keys[2])
        target_node.keys = target_node.keys[:1]

        if not target_node.leaf:
            new_node.child.append(target_node.child[2])
            target_node.child = target_node.child[:2]

    # displays all th data in the objects of the nodes
    def display(self, node=None, index=1):
        if node is None:
            node = self.root

        for key in node.keys:
            if index == 1:
                key.display()
            else:
                print(key.get_venue_name())
        if not node.leaf:
            for child in node.child:
                self.display(child, index)

    # return the objects give the venue name
    def retrieve(self, venue_name, node=None):
        if node is None:
            node = self.root

        for key in node.keys:
            if key == venue_name:
                return key

        if not node.leaf:
            for child in node.child:
                result = self.retrieve(venue_name, child)
                if result is not None:
                    return result

        return None
