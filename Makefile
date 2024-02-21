CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

OBJS = llrec.o llrec-test.o

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

llrec.o: llrec.h llrec.cpp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec.cpp
llrec-test.o: llrec.h llrec-test.cpp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec-test.cpp	


clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 