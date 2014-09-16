GTEST = ../gtest-1.7.0
GTESTLIB = libgtest.a

OPT ?= -g -O0
CXXFLAGS += -I$(GTEST) -I$(GTEST)/include $(OPT)
CC = g++

SOURCES = $(wildcard *.cc)
OBJECTS = $(patsubst %.cc,%.o,$(SOURCES))

TESTBIN = leetcode

all: test

test: $(OBJECTS) $(GTESTLIB)
	$(CC) $(OBJECTS) $(GTESTLIB) -lpthread -o $(TESTBIN)
	./$(TESTBIN)

$(GTESTLIB):
	$(CC) $(CXXFLAGS) -c $(GTEST)/src/gtest-all.cc
	$(CC) $(CXXFLAGS) -c $(GTEST)/src/gtest_main.cc
	ar -rv $(GTESTLIB) gtest-all.o gtest_main.o

clean:
	rm -rf *.o $(OBJECTS) $(GTESTLIB) $(TESTBIN)
