#pragma once
#include "parser.h"
#include <stack>

std::string gen_code(ParseNode * ptree) {
	using namespace std;
	ParseNode * p = nullptr;
	string ans;
	if (ptree->child.size() == 0) {
		// Ҷ�ӽڵ����ս��
		ans = " " + ptree->fs.CurrentTerm.what;
	}
	else {
		// ��Ҷ�ӽڵ��Ƿ��ս��
		for (int i = 0; i < ptree->child.size(); i++)
		{
			ans += gen_code(ptree->child[i]);
		}

	}
	return ans;
}