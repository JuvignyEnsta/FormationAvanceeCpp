include ../../make.inc

execs = deprecated_exemple.exe fallthrough_exemple.exe likely_exemple.exe \
 maybe_unused_exemple.exe nodiscard_exemple.exe notreturn_exemple.exe no_unique_adress_exemple.exe

default:
	@echo $(execs)

all: $(execs)

clean:
	@rm -fr *.exe *~ *.o

deprecated_exemple.exe: deprecated_exemple.cpp
	$(CXX) $(CCOPT) $< -o $@

fallthrough_exemple.exe: fallthrough_exemple.cpp
	$(CXX) $(CCOPT) $< -o $@

likely_exemple.exe: likely_exemple.cpp
	$(CXX) $(CCOPT) $< -o $@

maybe_unused_exemple.exe: maybe_unused_exemple.cpp
	$(CXX) $(CCOPT) $< -o $@

nodiscard_exemple.exe: nodiscard_exemple.cpp
	$(CXX) $(CCOPT) $< -o $@

notreturn_exemple.exe: notreturn_exemple.cpp
	$(CXX) $(CCOPT) $< -o $@

no_unique_adress_exemple.exe: no_unique_adress_exemple.cpp
	$(CXX) $(CCOPT) $< -o $@
