include ../make.inc
execs = $(patsubst %.cpp,%.exe, $(wildcard *.cpp))

.SUFFIXES:	.cpp

default:
	echo ${execs}

all::	$(execs)

clean:
	@rm -f *.exe *~ *.o

%.exe : %.cpp
	$(CXX) $(CCOPT) $< -o $@ $(LIBS)
