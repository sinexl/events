SRC = $(shell find -type f -name "*.cpp")
HPP = $(shell find -type f -name "*.hpp")

CFLAGS = -Wall -Wextra -g
INCLUDE = -I./src/

example: $(SRC) $(HPP)
	g++ $(CFLAGS) $(INCLUDE) -o example example.cpp
