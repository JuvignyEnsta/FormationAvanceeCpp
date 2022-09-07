include ../../make.inc

execs = basic_concepts_examples.exe  concepts_examples_2.exe  concepts_examples.exe

default:
	@echo $(execs)

all: $(execs)

clean:
	@rm -fr *.exe *~ *.o

basic_concepts_examples.exe: basic_concepts_examples.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

concepts_examples_2.exe: concepts_examples_2.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

concepts_examples.exe: concepts_examples.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@
