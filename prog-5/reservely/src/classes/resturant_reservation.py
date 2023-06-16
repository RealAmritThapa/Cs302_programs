"""
Name: Amrit Thapa
cs302-001-Program4
6-14-23
purpose: this file is responsible for the restuarant class 
and its deals withh all things about resturant like 
changing tables, changeing guest numbers
"""
from .reservation import Reservation


class Restaurant(Reservation):
    # constructor with paramaters 
    def __init__(self, reservation_obj=None, table_num=0, reservation_time=None, num_of_guests=0):
        super().__init__(reservation_obj.venue_name,
                         reservation_obj.costumer_name, reservation_obj.id)
        self.table_num = table_num
        self.reservation_time = reservation_time
        self.num_of_guests = num_of_guests

    #display all the info baout the restaturant object
    def display(self):
        super().display()
        print(f"Table Number: {self.table_num}")
        print(f"Reservation Time: {self.reservation_time}")
        print(f"Number of guests: {self.num_of_guests}")

    # changest the table number chosen by the user
    def change_table(self, new_table_num):
        self.table_num = new_table_num

    #chanest the guest number
    def change_guests(self, new_num_guests):
        self.num_of_guests = new_num_guests

    #oveloaded the = operator to set the table num 
    def __eq__(self, new_table_num):
        self.table_num = new_table_num
        return self