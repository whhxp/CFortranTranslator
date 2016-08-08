%{
#include <stdio.h>
#include <string>
#include <iostream>
#include "../tokenizer.h"
#include "../parser.h"
// 前置声明, 不然编译不过
void yyerror(const char* s); 
extern int yylex();
extern void set_buff(const std::string & code);
extern void release_buff();
#define YYDEBUG 1
#define YYERROR_VERBOSE

%}

%debug

%token YY_REQ_MORE YY_CRLF
%token YY_GT YY_GE YY_EQ YY_LE YY_LT YY_NEQ YY_NEQV YY_EQV YY_ANDAND YY_OROR YY_NOT YY_POWER YY_DOUBLECOLON YY_NEG
%token YY_INTEGER YY_FLOAT YY_WORD YY_OPERATOR YY_STRING YY_ILLEGAL YY_COMPLEX YY_TRUE YY_FALSE
%token YY_END YY_IF YY_THEN YY_ELSE YY_ELSEIF YY_ENDIF YY_DO YY_ENDDO YY_CONTINUE YY_BREAK YY_WHILE YY_ENDWHILE YY_WHERE YY_ENDWHERE YY_CASE YY_ENDCASE
%token YY_PROGRAM YY_ENDPROGRAM YY_FUNCTION YY_ENDFUNCTION YY_RECURSIVE YY_RESULT YY_SUBROUTINE YY_ENDSUBROUTINE YY_MODULE YY_ENDMODULE YY_BLOCK YY_ENDBLOCK
%token YY_IMPLICIT YY_NONE YY_USE YY_PARAMETER YY_FORMAT YY_ENTRY YY_DIMENSION
%token YY_INTEGER_T YY_FLOAT_T YY_STRING_T YY_COMPLEX_T YY_BOOL_T
%token YY_WRITE YY_READ YY_PRINT YY_OPEN YY_CLOSE


%left '='
%left YY_OROR
%left YY_ANDAND
%left YY_EQ YY_NEQ
%left YY_GT YY_GE YY_LE YY_LT
%left '+' '-' 
%left '*' '/' 
%left YY_POWER
%right YY_NEG YY_NOT

%start program

%%
	crlf : YY_CRLF
		| 

    dummy_function : YY_RECURSIVE
	
	literal : YY_FLOAT
			{
				/* 该条目下的右部全部为单个终结符号(语法树的叶子节点), 因此$1全部来自lex程序 */
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Float, $1.fs.CurrentTerm.what }; // float number
				$$ = *newnode;
			}
		| YY_INTEGER
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Int, $1.fs.CurrentTerm.what }; // int number
				$$ = *newnode;
			}
		| YY_STRING
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::String, $1.fs.CurrentTerm.what }; // string
				$$ = *newnode;
			}
		| YY_TRUE
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Bool, $1.fs.CurrentTerm.what }; // bool true
				$$ = *newnode;
			}
		| YY_FALSE
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Bool, $1.fs.CurrentTerm.what }; // bool false
				$$ = *newnode;
			}
        | YY_COMPLEX
            {printf("complex " );}

		| error '\n'

	variable : YY_WORD
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::UnknownVariant, $1.fs.CurrentTerm.what }; // variant
				$$ = *newnode;
			}

	exp : '(' exp ')' crlf
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "(" };
				newnode->addchild(new ParseNode($2)); 
				$$ = *newnode;
			}
		| exp '+' exp crlf
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "+" };
				newnode->addchild(new ParseNode($1)); // left operand exp
				newnode->addchild(new ParseNode($2)); // +
				newnode->addchild(new ParseNode($3)); // tight operand exp
				$$ = *newnode;
			}
		| exp '-' exp crlf
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "-" };
				newnode->addchild(new ParseNode($1)); // left operand exp
				newnode->addchild(new ParseNode($2)); // -
				newnode->addchild(new ParseNode($3)); // right operand exp
				$$ = *newnode;
			}
		| exp '*' exp crlf
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "*" };
				newnode->addchild(new ParseNode($1)); // left operand exp
				newnode->addchild(new ParseNode($2)); // *
				newnode->addchild(new ParseNode($3)); // right operand exp
				$$ = *newnode;
			}
		| exp '/' exp crlf
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "/" };
				newnode->addchild(new ParseNode($1)); // left operand exp
				newnode->addchild(new ParseNode($2)); // /
				newnode->addchild(new ParseNode($3)); // right operand exp
				$$ = *newnode;
			}
		| exp YY_POWER exp crlf
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "**" };
				newnode->addchild(new ParseNode($1)); // left operand exp
				newnode->addchild(new ParseNode($2)); // **
				newnode->addchild(new ParseNode($3)); // right operand exp
				$$ = *newnode;
			}
        | '-' exp %prec YY_NEG crlf
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "-" };
				newnode->addchild(new ParseNode($1)); // (-)
				newnode->addchild(new ParseNode($2)); // only right operand exp
				$$ = *newnode;
			}
		| literal crlf
            { 
				// 
				$$ = $1;
			}
		| variable
			{
				// 
				$$ = $1;
			}

	stmt : exp
        | compound_stmt
        | output_stmt

    output_stmt : write

    write : '(' YY_INTEGER ',' YY_STRING ')' argtable
        | '(' '*' ',' YY_STRING ')' argtable
        | '(' '*' ',' '*' ')' argtable
        | '*' ',' argtable

    type_spec : YY_INTEGER_T
        | YY_FLOAT_T
        | YY_STRING_T 
        | YY_COMPLEX_T
        | YY_BOOL_T

	slice : exp ':' exp
			{
				/* arr[from: to] */
			}
		| exp ':' exp ':' exp
			{
			}

    var_def : type_spec YY_DOUBLECOLON paramtable
			{
				/*  */
			}
		| type_spec ',' YY_DIMENSION '(' slice ')' YY_DOUBLECOLON paramtable
			{
				/* array decl */
			}

    paramtable : YY_WORD
			{
				/* paramtable is used in function decl */
			}
        | YY_WORD '=' exp
        | YY_WORD ',' argtable        
        | YY_WORD '=' exp
        | YY_WORD '=' exp ',' argtable

    argtable : exp
			{
				/* argtable is used in function call */
			}
        | exp ',' argtable

    compound_stmt : if_stmt | do_stmt

	if_stmt : YY_IF exp YY_THEN crlf suite YY_END YY_IF crlf
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "if" };
				newnode->addchild(new ParseNode($1)); // if
				newnode->addchild(new ParseNode($2)); // exp
				newnode->addchild(new ParseNode($5)); // suite
				$$ = *newnode;
			}
		| YY_IF exp YY_THEN crlf suite YY_ELSE crlf suite YY_END YY_IF crlf
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "if-else" };
				newnode->addchild(new ParseNode($1)); // if
				newnode->addchild(new ParseNode($2)); // exp
				newnode->addchild(new ParseNode($5)); // suite
				newnode->addchild(new ParseNode($6)); // else
				newnode->addchild(new ParseNode($8)); // else-stmt
				$$ = *newnode;
			}
		| YY_IF exp YY_THEN crlf suite elseif_stmt YY_END YY_IF crlf
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "if-elseif" };
				newnode->addchild(new ParseNode($1)); // if
				newnode->addchild(new ParseNode($2)); // exp
				newnode->addchild(new ParseNode($5)); // suite
				newnode->addchild(new ParseNode($6)); // recursive elseif-stmt
				$$ = *newnode;
			}
		| YY_IF exp YY_THEN crlf suite elseif_stmt YY_ELSE crlf suite YY_END YY_IF
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "if-elseif-else" };
				newnode->addchild(new ParseNode($1)); // if
				newnode->addchild(new ParseNode($2)); // exp
				newnode->addchild(new ParseNode($5)); // suite
				newnode->addchild(new ParseNode($6)); // recursive elseif-stmt
				newnode->addchild(new ParseNode($9)); // else-stmt
				$$ = *newnode;
			}
	elseif_stmt : YY_ELSEIF exp YY_THEN crlf suite
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "elseif" };
				newnode->addchild(new ParseNode($1)); // elseif
				newnode->addchild(new ParseNode($2)); // exp
				newnode->addchild(new ParseNode($5)); // suite
				$$ = *newnode;
			}

		| YY_ELSEIF exp YY_THEN crlf suite elseif_stmt
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "elseif-else-if" };
				newnode->addchild(new ParseNode($1)); // elseif
				newnode->addchild(new ParseNode($2)); // exp
				newnode->addchild(new ParseNode($5)); // suite
				newnode->addchild(new ParseNode($6)); // another elseif-stmt
				$$ = *newnode;
			}
	do_stmt : YY_DO crlf suite YY_END YY_DO crlf
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "do" };
				newnode->addchild(new ParseNode($1)); // do
				newnode->addchild(new ParseNode($3)); // suite
				$$ = *newnode;
			}
		| YY_DO YY_WORD '=' exp ',' exp suite YY_END YY_DO
		| YY_DO YY_WORD '=' exp ',' exp ',' exp suite YY_END YY_DO

    suite : stmt
        | stmt suite

    program : YY_PROGRAM YY_WORD suite YY_END YY_PROGRAM YY_WORD
			{ 
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode($3));
				program_tree = *newnode;
			}
        | YY_PROGRAM suite YY_END YY_PROGRAM
			{
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode($2));
				program_tree = *newnode;
			}

%%
//extern "C" int yylex();

void yyerror(const char* s)
{
	fprintf(stderr, "%s\n", s);
}
int parse(std::string code) {
#ifdef USE_YACC
	set_buff(code);
	yyparse();
	release_buff();
#endif
	return 0;
}
