#include "Function.h"
#include "tokenizer.h"
#include "parser.h"

std::map < std::string, FunctionInfo > functions;


FunctionInfo * get_function(std::string module_name, std::string function_name) {
	std::string fullname = module_name + "::" + function_name;
	if (functions.find(fullname) != functions.end()) {
		return &functions[fullname];
	}
	else {
		return nullptr;
	}
}

bool add_function(std::string module_name, std::string function_name, const FunctionInfo & finfo) {
	std::string fullname = module_name + "::" + function_name;
	if (functions.find(fullname) != functions.end()) {
		return false;
	}
	else {
		functions[fullname] = finfo;
		return true;
	}
}