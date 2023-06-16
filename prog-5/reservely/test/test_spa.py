"""
Name: Amrit Thapa
cs302-001-Program4
6-14-23
purpose: the purpose of this file is to test the spa class and all teh fucntion wihtin it like 
the display fucntion 
"""
import pytest
from reservely.src.classes.reservation import Reservation
from reservely.src.classes.spa_reservation import Spa

# test the constructor of spa object


def test_spa_init():
    reserve = Reservation("The Venue", "amrit", "1")
    spa = Spa(reserve, "2023-06-10", "13:00",
              "Full Body Massage", "Karla marti")

    assert spa.venue_name == "The Venue"
    assert spa.costumer_name == "amrit"
    assert spa.id == "1"
    assert spa.appoint_data == "2023-06-10"
    assert spa.appoint_time == "13:00"
    assert spa.service_type == "Full Body Massage"
    assert spa.therapist_name == "Karla marti"

# test the display of spa object


def test_spa_display(capfd):
    reserve = Reservation("The Venue", "amrit", "1")
    spa = Spa(reserve, "2023-06-10", "13:00",
              "Full Body Massage", "Karla marti")
    spa.display()

    out, err = capfd.readouterr()
    expected_output = ("Venue: The Venue\n"
                       "Costumer: amrit\n"
                       "Id: 1\n"
                       "Appointment Date: 2023-06-10\n"
                       "Appointment Time: 13:00\n"
                       "Service Type: Full Body Massage\n"
                       "Therapist Name: Karla marti\n")

    assert out == expected_output
