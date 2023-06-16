"""
Name: Amrit Thapa
cs302-001-Program4
6-14-23
purpose: this is the base class and its reposnible for handiely all the important things like venue name comparasions
"""


class Reservation:
    # Constructor function that initializes a Reservation object
    def __init__(self, venue_name=None, costumer_name=None, id=0):
        self.venue_name = venue_name
        self.costumer_name = costumer_name
        self.id = id

    # prints the details of the reservation
    def display(self):
        print(f"Venue: {self.venue_name}")
        print(f"Costumer: {self.costumer_name}")
        print(f"Id: {self.id}")

    # Determines if the given user_venue_name comes before or after the current reservation's venue name
    def left_or_right(self, user_venue_name):
        if (user_venue_name < self.venue_name):
            return True
        else:
            return False

    # Returns the venue Name
    def get_venue_name(self):
        return self.venue_name

    # Compares the venue names of two reservations and returns True if the current reservation's venue name is less than the other reservation's venue name.
    def __lt__(self, other):
        if isinstance(other, Reservation):
            return self.venue_name < other.venue_name
        raise TypeError("Unsupported operand type: {} < {}".format(
            type(self).__name__, type(other).__name__))

    # checks if passed in name is equal to the objects venue name
    def __eq__(self, venue_name):
        if self.venue_name == venue_name:
            return True
        return False
