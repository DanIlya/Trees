C=g++
CFLAGS=-c -std=c++11
LDFLAGS=

SOURCES= AVLtree.cpp ../SimpleTree/SimpleTree.cpp ../SimpleTree/Container.cpp  main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: test

test: $(OBJECTS)
	$(C) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(C) $(CFLAGS) $<

clean:
	rm -f *.o test *~
	
