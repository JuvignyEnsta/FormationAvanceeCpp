include ../../make.inc

execs = auto_template_parameter.exe  deduction_parameter_using_with_stl.exe \
        define_deduction_parameter.exe  generic_lambda_functions.exe        \
        if_constexpr_example.exe  variable_template.exe

default:
	@echo $(execs)

all: $(execs)

clean:
	@rm -fr *.exe *~ *.o

auto_template_parameter.exe: auto_template_parameter.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

deduction_parameter_using_with_stl.exe: deduction_parameter_using_with_stl.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

define_deduction_parameter.exe: define_deduction_parameter.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

generic_lambda_functions.exe: generic_lambda_functions.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

if_constexpr_example.exe: if_constexpr_example.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@

variable_template.exe: variable_template.cpp
	$(CXX) $(CCOPT) $(CCOPTIM) $< -o $@
