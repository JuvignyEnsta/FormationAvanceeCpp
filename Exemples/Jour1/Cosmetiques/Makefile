include ../../make.inc

execs = binaire_separateur_chiffres.exe exemple_string.exe if_exemple.exe listinitialisation_exemple.exe using_examples.exe \
		enum_examples.exe for_exemple.exe initialisation_exemples.exe static_assert_example.exe

default:
	@echo $(execs)

all: $(execs)

clean:
	@rm -fr *.exe *~ *.o

binaire_separateur_chiffres.exe : binaire_separateur_chiffres.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

exemple_string.exe: exemple_string.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

if_exemple.exe: if_exemple.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

listinitialisation_exemple.exe : listinitialisation_exemple.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

using_examples.exe : using_examples.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

enum_examples.exe: enum_examples.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

for_exemple.exe: for_exemple.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

initialisation_exemples.exe: initialisation_exemples.cpp
	$(CXX) $(CCOPT)$(CCOPTIM) $< -o $@

static_assert_example.exe: static_assert_example.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

fallthrough_exemple.exe: fallthrough_exemple.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

likely_exemple.exe: likely_exemple.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

maybe_unused_exemple.exe: maybe_unused_exemple.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

nodiscard_exemple.exe: nodiscard_exemple.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

notreturn_exemple.exe: notreturn_exemple.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

no_unique_adress_exemple.exe: no_unique_adress_exemple.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@
