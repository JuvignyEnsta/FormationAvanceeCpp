include ../../make.inc

execs = classe_moderne_exemple.exe operateurs_litteraux.exe \
        spaceship_exemple.exe

default:
	@echo $(execs)

all: $(execs)

clean:
	@rm -fr *.exe *~ *.o

classe_moderne_exemple.exe: classe_moderne_exemple.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

operateurs_litteraux.exe: operateurs_litteraux.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

spaceship_exemple.exe: spaceship_exemple.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

