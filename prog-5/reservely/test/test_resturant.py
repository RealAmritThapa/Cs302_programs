"""
Name: Amrit Thapa
cs302-001-Program4
6-14-23
purpose: this file is responsible for restuarant file and to test all teh function wihtin it
"""
from reservely.src.classes.resturant_reservation import Restaurant
from reservely.src.classes.reservation import Reservation
import pytest
from datetime import datetime

# tests the constructor of the restuatnt obj


def test_restaurant_init():
    reserv = Reservation("The Venue", "Amrit", 1)
    restaurant = Restaurant(reserv, 10, datetime(2023, 1, 1), 4)

    assert restaurant.venue_name == "The Venue"
    assert restaurant.costumer_name == "Amrit"
    assert restaurant.id == 1
    assert restaurant.table_num == 10
    assert restaurant.reservation_time == datetime(2023, 1, 1)
    assert restaurant.num_of_guests == 4

# Test the display fucntion of restautane


def test_restaurant_display(capfd):
    reserv = Reservation("The Venue", "Amrit", "1")
    restaurant = Restaurant(reserv, 10, datetime(2023, 1, 1), "4")
    restaurant.display()

    out, err = capfd.readouterr()
    expected_output = ("Venue: The Venue\n"
                       "Costumer: Amrit\n"
                       "Id: 1\n"
                       "Table Number: 10\n"
                       "Reservation Time: 2023-01-01 00:00:00\n"
                       "Number of guests: 4\n")

    assert out == expected_output

# test if change table work


def test_change_table():
    reserv = Reservation("The Venue", "Amrit", 1)
    restaurant = Restaurant(reserv, 10, datetime(2023, 1, 1), 4)

    restaurant.change_table(20)
    assert restaurant.table_num == 20

# test if guest change works


def test_change_guests():
    reserv = Reservation("The Venue", "Amrit", 1)
    restaurant = Restaurant(reserv, 10, datetime(2023, 1, 1), 4)

    restaurant.change_guests(6)
    assert restaurant.num_of_guests == 6
