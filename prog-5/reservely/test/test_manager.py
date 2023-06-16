"""
Name: Amrit Thapa
cs302-001-Program4
6-14-23
purpose: this file is used to test the manager classs and all the functions contained wihtin it
"""
import pytest
import numpy as np
from datetime import date
from reservely.src.data_structure.reservation_manager import ReservationManager

#test if venue name gets added 
def test_add_venue_name():
    reserve = ReservationManager()
    reserve.add_venue_name("Hilton", "hotel")
    assert "Hilton" in reserve.hotel_venues
    reserve.add_venue_name("Aqua Spa", "spa")
    assert "Aqua Spa" in reserve.spa_venues
    reserve.add_venue_name("Bella Italia", "restaurant")
    assert "Bella Italia" in reserve.restaurant_venues

#checks if time slots are added
def test_add_time_slot():
    reserve = ReservationManager()
    reserve.add_time_slot()
    assert "06-01-2023" in reserve.time_slots['hotel']
    assert "12-31-2023" in reserve.time_slots['hotel']
    assert "9:00 - 10:00" in reserve.time_slots['spa']
    assert "20:00 - 21:00" in reserve.time_slots['spa']

#checks if venue exists
def test_venue_exists():
    reserve = ReservationManager()
    assert reserve.venue_exists('hotel') is True
    assert reserve.venue_exists('spa') is True
    assert reserve.venue_exists('restaurant') is True
    with pytest.raises(ValueError):
        reserve.venue_exists('amusement park')

#test if display tiem is properly fucntional 
def test_display_time(capfd):
    reserve = ReservationManager()
    reserve.add_time_slot()
    reserve.display_time('hotel')
    out, _ = capfd.readouterr()
    assert "1: 06-01-2023" in out
    assert f"{len(reserve.time_slots['hotel'])}: 12-31-2023" in out

#makes sure venue is display properly
def test_display_venue(capfd):
    reserve = ReservationManager()
    reserve.add_venue_name("Hilton", "hotel")
    reserve.add_venue_name("Aqua Spa", "spa")
    reserve.add_venue_name("Bella Italia", "restaurant")
    reserve.display_venue('hotel')
    out, _ = capfd.readouterr()
    assert "Hilton" in out

    reserve.display_venue('spa')
    out, _ = capfd.readouterr()
    assert "Aqua Spa" in out

    reserve.display_venue('restaurant')
    out, _ = capfd.readouterr()
    assert "Bella Italia" in out
