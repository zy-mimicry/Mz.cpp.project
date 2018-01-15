#TODO: compile demo
TARGET := Demo
CC := g++
CFLAG := -Wall
SRC := main.cpp
SRC += grade.cpp
SRC += median.cpp
SRC += Student_info.cpp

INC := -I.

$(TARGET): $(SRC)
	$(CC) $(CFLAG) $(INC) -o $@ $^

.PYTHON: clean
clean:
	-rm -rf $(TARGET)
