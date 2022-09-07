include ../../make.inc

execs = nullptr_example.exe  rvalue_exemple.exe  sharedptr_exemple.exe

default:
	@echo $(execs)

all: $(execs)

clean:
	@rm -fr *.exe *~ *.o

nullptr_example.exe: nullptr_example.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

rvalue_exemple.exe : rvalue_exemple.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

sharedptr_exemple.exe: sharedptr_exemple.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

