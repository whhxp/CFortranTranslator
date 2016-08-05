#pragma once
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "tokenizer.h"

int parse(std::string code);

// ����
struct ParseNode {
	struct ParseNode * father;
	
	std::vector<ParseNode *> child;
	FlexState fs;

	ParseNode(const ParseNode &);
	ParseNode & operator= (const ParseNode &) ;
	ParseNode() = default;
	~ParseNode();
};

extern ParseNode program_tree;
extern ParseNode * curnode;

void preoder(ParseNode * ptree);

// yacc part code
// implement in for90.y
typedef ParseNode yystype_t;
#define YYSTYPE ParseNode