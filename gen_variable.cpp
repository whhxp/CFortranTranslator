/*
*   Calvin Neo
*   Copyright (C) 2016  Calvin Neo <calvinneo@calvinneo.com>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License along
*   with this program; if not, write to the Free Software Foundation, Inc.,
*   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "gen_common.h"
#include <map>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/irange.hpp>

//5.5.2 COMMON statement
//The COMMON statement specifies blocks of physical storage, called common blocks, that may be accessed by
//any of the scoping units in an executable program.Thus, the COMMON statement provides a global data facility
//based on storage association(14.6.3).The common blocks specified by the COMMON statement may be named
//and are called named common blocks, or may be unnamed and are called blank common.

ParseNode gen_common(const ParseNode & commonname_node, const ParseNode & paramtable) {
	// the unique blank COMMON block must be declared in the main program.
	ParseNode kvparamtable = promote_argtable_to_paramtable(paramtable);
	string common_name = commonname_node.fs.CurrentTerm.what;
	auto common_info = get_context().commonblocks.find(common_name);
	if (common_info == get_context().commonblocks.end()) {
		// add common block to context
		get_context().commonblocks[common_name] = CommonBlockInfo{ common_name, std::vector<VariableInfo>() };
		common_info = get_context().commonblocks.find(common_name);
	}
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_COMMONBLOCK, "" });
	newnode.addlist(commonname_node, kvparamtable);
	return newnode;
}

void regen_common(FunctionInfo * finfo, ParseNode & common_block) {
	ParseNode & commonname_node = common_block.get(0);
	ParseNode & kvparamtable = common_block.get(1);
	string common_name = commonname_node.fs.CurrentTerm.what;
	auto common_info = get_context().commonblocks.find(common_name);
	if (common_info == get_context().commonblocks.end())
	{
		print_error("Error Common Block");
	}
	bool new_common = (common_info->second.variables.size() == 0);
	for (int i = 0; i < (int)kvparamtable.child.size(); i++)
	{
		ParseNode & entity_variable = kvparamtable.get(i);
		std::string local_varname = get_variable_name(entity_variable);
		VariableInfo * local_vinfo = get_variable(get_context().current_module, finfo->local_name, local_varname);
		if (local_vinfo == nullptr)
		{
			// if this common variable has no prev explicit declaration
			local_vinfo = add_variable(get_context().current_module, finfo->local_name, local_varname, VariableInfo(local_varname));
			ParseNode implicit_type = gen_type(Term{ TokenMeta::Implicit_Def, "" });
			ParseNode vardef_node = gen_vardef_from_implicit(implicit_type, local_varname);
			ParseNode & variable_entity = kvparamtable.get(i);
			VariableDesc desc;
			regen_vardef(local_vinfo, vardef_node, implicit_type, desc, variable_entity);
			local_vinfo->commonblock_name = common_name;
			local_vinfo->commonblock_index = i;
			local_vinfo->implicit_defined = true;
		}
		else {
			// 出现错误，因为regen_vardef在regen_suite里面调用，此时gen_common已经结束了
		}
		if (new_common)
		{
			VariableInfo global_vinfo(*local_vinfo);
			common_info->second.variables.push_back(global_vinfo);
		}
		local_vinfo->desc.constant = false;
		local_vinfo->desc.reference = true;
	}
	// code are actually generated in gen_stmt_suite
	// if the variable is not declared by statement other than `COMMON`, it will be generated by forall_variable_in_function
}

ParseNode gen_common_definition(std::string common_name) {
	auto common_info = get_context().commonblocks.find(common_name);
	if (common_info == get_context().commonblocks.end()) {
		print_error("Common block without definition");
	}
	int i = 0;
	string struct_str = make_str_list(common_info->second.variables.begin(), common_info->second.variables.end(), [&](const VariableInfo & x) {
		std::string common_varname = "_" + to_string(++i);
		sprintf(codegen_buf, "%s %s;", x.type.c_str(), common_varname.c_str());
		return string(codegen_buf);
	}, "\n");
	if (common_name == "")
	{
		sprintf(codegen_buf, "struct{\n%s\n}G;\n", tabber(struct_str).c_str());
	}
	else {
		sprintf(codegen_buf, "struct{\n%s\n}%s;\n", tabber(struct_str).c_str(), common_name.c_str());
	}
	return gen_token(Term{ TokenMeta::NT_COMMONBLOCKDEFINE, string(codegen_buf) });
}


void check_implicit_variable(const ParseNode &) {
	
}