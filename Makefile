CXX=gcc
CXXINCLUDE=
CXXFLAGS=-g -std=gnu++17
LDFLAGS=-g
LDLIBS=-lstdc++

all: automat

SRCS=kaffeautomat.cpp item.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

automat: $(OBJS)
	$(CXX) $(LDLIBS) $(LDFLAGS) -o automat $(OBJS)

# kaffeautomat.o: kaffeautomat.cpp
# 	$(CXX) $(CXXINCLUDE) $(CXXFLAGS) -o kaffeautomat.o kaffeautomat.cpp

# item.o: item.cpp item.hpp
#	$(CXX) $(CXXINCLUDE) $(CXXFLAGS) -o item.o item.cpp

%.o : %.cpp
	$(CXX) -c $(CXXINCLUDE) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f automat *.o
