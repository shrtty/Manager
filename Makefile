CC 		= g++
TARGET	= Manager
SRC		= main.cpp Manager.cpp Account.cpp
OBJ 	= $(SRC:%.cpp=%.o)
CFLAGS	=
DEL		= del

%.o: %.cpp
	$(CC) -c $(CFLAGS) $<

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(OBJ)

main.cpp: Manager.h
Manager.cpp: Manager.h Account.h
Account.cpp: Account.h

.PHONY: clean
clean: $(OBJ)
	$(DEL) $^
