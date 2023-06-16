"""
Name: Amrit Thapa
cs302-001-Program4
6-14-23
purpose: this file is reposnible for testing the hotel class and all its fuctions
"""
from reservely.src.classes.hotel_reservation import Hotel
from reservely.src.classes.reservation import Reservation
from datetime import datetime, date
import pytest

#test all teh outputs for hotel class
def test_hotel_initialization():
    reservation = Reservation(
        "Hilton", "Amrit", 1)
    hotel = Hotel(reservation, 101, date(
        2023, 6, 1), date(2023, 6, 10), "Single")

    assert hotel.venue_name == "Hilton"
    assert hotel.costumer_name == "Amrit"
    assert hotel.id == 1
    assert hotel.room_number == 101
    assert hotel.check_in == date(2023, 6, 1)
    assert hotel.check_out == date(2023, 6, 10)
    assert hotel.room_type == "Single"

#makes sure all is display poperly
def test_hotel_display(capfd):
    reservation = Reservation(
        "Hilton", "Amrit", 1)
    hotel = Hotel(reservation, 101, date(
        2023, 6, 1), date(2023, 6, 10), "Single")

    hotel.display()
    out, _ = capfd.readouterr()
    assert "Hilton" in out
    assert "Amrit" in out
    assert "1" in out
    # assert "Room Number: 101" in out
    # assert "Check-in Date: 2023-06-01" in out
    # assert "Check-out Date: 2023-06-10" in out
    # assert "Room Type: Single" in out
