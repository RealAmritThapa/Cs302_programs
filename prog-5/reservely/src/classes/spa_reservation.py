"""
Name: Amrit Thapa
cs302-001-Program4
6-14-23
purpose: this file handles the responsbility of the spa class 
"""
from .reservation import Reservation


class Spa(Reservation):

    # constrcutor with paramaters
    def __init__(self, reservation_obj=None, appoint_date=None, appoint_time=None, service_type=None, therapist_name=None):
        super().__init__(reservation_obj.venue_name,
                         reservation_obj.costumer_name, reservation_obj.id)
        self.appoint_data = appoint_date
        self.appoint_time = appoint_time
        self.service_type = service_type
        self.therapist_name = therapist_name

    #displays all the info about the spa object
    def display(self):
        super().display()
        print(f"Appointment Date: {self.appoint_data}")
        print(f"Appointment Time: {self.appoint_time}")
        print(f"Service Type: {self.service_type}")
        print(f"Therapist Name: {self.therapist_name}")
