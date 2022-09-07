include ../../make.inc

execs = basic_variadic_template2.exe  fold_expression.exe other_variadic_templates_examples.exe simple_variadic_structure.exe \
        basic_variadic_template.exe   homogeneisation_parametres.exe  parite_variadic_template.exe variadic_structures.exe\
        exemple_variadic_en_c.exe

default:
	@echo $(execs)

all: $(execs)

clean:
	@rm -fr *.exe *~ *.o

basic_variadic_template2.exe: basic_variadic_template2.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

fold_expression.exe: fold_expression.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

other_variadic_templates_examples.exe: other_variadic_templates_examples.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

simple_variadic_structure.exe: simple_variadic_structure.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

basic_variadic_template.exe: basic_variadic_template.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

homogeneisation_parametres.exe: homogeneisation_parametres.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

parite_variadic_template.exe: parite_variadic_template.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

variadic_structures.exe: variadic_structures.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

exemple_variadic_en_c.exe: exemple_variadic_en_c.c
	$(CC) $(CCOPTIM) -pedantic -Wall $< -o $@
