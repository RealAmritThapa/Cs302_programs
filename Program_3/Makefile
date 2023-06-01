CC = g++
CFLAGS = -g -Wall
SOURCES = character.cpp DataStructure.cpp ElementalClash.cpp main.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
TARGET=ElementalClash

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^

character.o: character.cpp ElementalClash.h
DataStructure.o: DataStructure.cpp ElementalClash.h
ElementalClash.o: ElementalClash.cpp ElementalClash.h
main.o: main.cpp ElementalClash.h

clean:
	rm -f $(OBJECTS) $(TARGET)
