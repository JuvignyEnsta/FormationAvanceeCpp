include ../../make.inc

execs = affectation_destructurante_exemple.exe  captures_exemples.exe \
	    fonctions_anonymes.exe lamba_auto_exemple.exe \
		notation_fonctionnelle.exe auto_anonymes_function.exe \
		expressions_constantes.exe  generic_lambda_functions.exe \
		noexcept_exemple.exe structured_return.exe expressions_constantes.S

default:
	@echo $(execs)

all: $(execs)

clean:
	@rm -fr *.exe *~ *.o *.S

affectation_destructurante_exemple.exe: affectation_destructurante_exemple.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

captures_exemples.exe: captures_exemples.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

fonctions_anonymes.exe: fonctions_anonymes.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

lamba_auto_exemple.exe: lamba_auto_exemple.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

notation_fonctionnelle.exe: notation_fonctionnelle.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

auto_anonymes_function.exe: auto_anonymes_function.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

expressions_constantes.exe: expressions_constantes.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

expressions_constantes.S : expressions_constantes.cpp
	$(CXX) $(CCOPT) -fno-asynchronous-unwind-tables -fno-exceptions -fno-rtti -fverbose-asm -S $< -o $@

generic_lambda_functions.exe: generic_lambda_functions.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

noexcept_exemple.exe: noexcept_exemple.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

structured_return.exe: structured_return.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

