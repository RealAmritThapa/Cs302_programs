"""
Name: Amrit Thapa
cs302-001-Program4
6-14-23
purpose: the pupose of this file is to hold the basic infor about hotel like room number 
checkkin and what not
"""

from .reservation import Reservation


class Hotel(Reservation):
    # constructor with paramaters
    def __init__(self, reservation=None, room_number=0, check_in=None, check_out=None, room_type=None):
        super().__init__(reservation.venue_name, reservation.costumer_name, reservation.id)
        self.room_number = room_number
        self.check_in = check_in
        self.check_out = check_out
        self.room_type = room_type

    #displays all data about Hotel
    def display(self):
        super().display()
        print(f"Room Number: {self.room_number}")
        print(f"Check-in Date: {self.check_in}")
        print(f"Check-out Date: {self.check_out}")
        print(f"Room Type: {self.room_type}")
