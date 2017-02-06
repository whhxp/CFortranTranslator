#include "gen_common.h"
#include <map>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/irange.hpp>

// refer Variable.h

struct CommonBlockInfo {
	std::string common_decl;
	ParseNode variables;
};
	
std::map<std::string, CommonBlockInfo> commonblocks;

void add_common(std::string common_name, const ParseNode & paramtable) {
	std::string components = make_str_list(paramtable.child.begin(), paramtable.child.end(), [](auto x) {return (*x)->fs.CurrentTerm.what; }, "\n");
	if (common_name == "")
	{
		sprintf(codegen_buf, "typedef struct{\n%s\n}%s\n", tabber(components).c_str(), common_name.c_str());
	}
	else {
		sprintf(codegen_buf, "%s", tabber(components).c_str());
	}
	commonblocks[common_name] = CommonBlockInfo{ string(codegen_buf), paramtable};
}

std::string declare_common(std::string common_name, const ParseNode & paramtable) {
	// the unique blank COMMON block must be declared in the main program.
	auto common_info = commonblocks.find(common_name);
	if (common_info == commonblocks.end()) {
		add_common(common_name, paramtable); 
		common_info = commonblocks.find(common_name);
	}
	auto range = boost::irange(0, (int)paramtable.child.size());
	std::string decl = make_str_list(range.begin(), range.end(), [&](auto x) {
		size_t i = (size_t)(*x);
		std::string local_varname = get_variable_name(paramtable.child[i]/* NT_EXPRESSION */->child[0]);
		std::string global_varname = get_variable_name(common_info->second.variables.child[i]->child[0]);
		return local_varname + " = " + common_name + "." + global_varname;
	}, "\n");
	return decl;
}

ParseNode gen_common(const ParseNode & common_block, const ParseNode & paramtable) {
	ParseNode newnode;
	declare_common(common_block.fs.CurrentTerm.what, paramtable);
	return newnode;
}