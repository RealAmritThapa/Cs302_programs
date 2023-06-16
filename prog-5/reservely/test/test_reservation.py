"""
Name: Amrit Thapa
cs302-001-Program4
6-14-23
purpose: this file is for reservation class and to test all the fucntion contsined 
wihtin it 
"""
from reservely.src.classes.reservation import Reservation
import pytest

#test the initialzion of reservation
def test_reservation_init():
    reserve = Reservation("The Venue", "Amrit", 1)

    assert reserve.venue_name == "The Venue"
    assert reserve.costumer_name == "Amrit"
    assert reserve.id == 1

#test displahy
def test_reservation_display(capfd):
    reserve = Reservation("The Venue", "Amrit", "1")
    reserve.display()

    out, err = capfd.readouterr()
    expected_output = "Venue: The Venue\nCostumer: Amrit\nId: 1\n"

    assert out == expected_output

#test if left or right function properly
def test_left_or_right():
    reserve = Reservation("M", "Amrit", 1)

    assert reserve.left_or_right("L") == True
    assert reserve.left_or_right("N") == False
