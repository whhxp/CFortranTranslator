#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include "tokenizer.h"
#include "Variable.h"

int parse(std::string code);

// 语义
struct ParseNode {
	struct ParseNode * father;
	
	std::vector<ParseNode *> child;
	FlexState fs; // 当前归约项目在代码段中的对应位置和作用(终结符/非终结符)
	struct ParseAttr * attr;

	void addchild(ParseNode * ptrn);

	ParseNode(const ParseNode &);
	ParseNode & operator= (const ParseNode &) ;
	ParseNode() : father(nullptr), attr(nullptr) {}
	virtual ~ParseNode();
};

// 属性文法
struct ParseAttr {
	ParseNode * parsenode; // observer ptr

	ParseAttr() = default;
	ParseAttr(ParseNode * parsenode) : parsenode(parsenode) {}
	ParseAttr(const ParseAttr & pa) = default;
	virtual ParseAttr * clone() = 0;

	virtual void parse() = 0; // parse according to parsenode
};

struct TypeAttr : public ParseAttr {
	std::string name;

	TypeAttr(ParseNode * parsenode) : ParseAttr(parsenode) {}
	TypeAttr(const TypeAttr & ta) {
		clone();
	}
	ParseAttr * clone() { return new TypeAttr(*this); }

	void parse();
};
struct VariableAttr : public ParseAttr {
	Variable * variable;

	VariableAttr(ParseNode * parsenode, Variable * v) : ParseAttr(parsenode), variable(v){}
	VariableAttr(const VariableAttr & va) {
		clone();
	}
	ParseAttr * clone() { return new VariableAttr(*this); }

	void parse();
};
// struct ArrayAttr FormatterAttr

extern ParseNode program_tree;
extern ParseNode * curnode;

void preorder(ParseNode * ptree);



// yacc part code
// implement in for90.y
typedef ParseNode yystype_t;
#define YYSTYPE ParseNode