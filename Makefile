CXX=gcc
CXXINCLUDE=
CXXFLAGS=-g -std=gnu++17
LDFLAGS=-g
LDLIBS=-lstdc++

all: automat

automat: kaffeautomat.cpp item.h
	$(CXX) $(LDLIBS) $(LDFLAGS) -o automat kaffeautomat.cpp

.PHONY: clean
clean:
	rm -f automat *.o
