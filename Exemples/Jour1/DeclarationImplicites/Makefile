include ../../make.inc

execs = auto_exemple.exe decltype_exemple.exe

default:
	@echo $(execs)

all: $(execs)

clean:
	@rm -fr *.exe *~ *.o

auto_exemple.exe: auto_exemple.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

decltype_exemple.exe: decltype_exemple.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

