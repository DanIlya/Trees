C=g++
CFLAGS=-c -std=c++11 -g
LDFLAGS=-lboost_unit_test_framework

SOURCES= AVLtree.cpp ../SimpleTree/SimpleTree.cpp ../SimpleTree/Container.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: app tests

app: $(OBJECTS) main.o
	$(C) $(LDFLAGS) $(OBJECTS) main.o -o $@

tests: $(OBJECTS) tests.o
	$(C) $(OBJECTS) tests.o $(LDFLAGS) -o $@

.cpp.o:
	$(C) $(CFLAGS) $<

clean:
	rm -f *.o tests app
	
