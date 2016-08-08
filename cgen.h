#pragma once
#include "parser.h"
#include <stack>

std::string gen_code(ParseNode * ptree) {
	using namespace std;
	ParseNode * p = nullptr;
	string ans;
	if (ptree->child.size() == 0) {
		// 叶子节点是终结符
		ans = " " + ptree->fs.CurrentTerm.what;
	}
	else {
		// 非叶子节点是非终结符
		for (int i = 0; i < ptree->child.size(); i++)
		{
			ans += gen_code(ptree->child[i]);
		}

	}
	return ans;
}