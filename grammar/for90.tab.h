/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_FOR90_TAB_H_INCLUDED
# define YY_YY_FOR90_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     YY_GT = 258,
     YY_GE = 259,
     YY_EQ = 260,
     YY_LE = 261,
     YY_LT = 262,
     YY_NEQ = 263,
     YY_NEQV = 264,
     YY_EQV = 265,
     YY_ANDAND = 266,
     YY_OROR = 267,
     YY_NOT = 268,
     YY_POWER = 269,
     YY_DOUBLECOLON = 270,
     YY_INTEGER = 271,
     YY_FLOAT = 272,
     YY_WORD = 273,
     YY_OPERATOR = 274,
     YY_STRING = 275,
     YY_ILLEGAL = 276,
     YY_COMPLEX = 277,
     YY_TRUE = 278,
     YY_FALSE = 279,
     YY_IF = 280,
     YY_THEN = 281,
     YY_ELSE = 282,
     YY_END = 283,
     YY_DO = 284,
     YY_CONTINUE = 285,
     YY_WHILE = 286,
     YY_WHERE = 287,
     YY_CASE = 288,
     YY_PROGRAM = 289,
     YY_FUNCTION = 290,
     YY_RECURSIVE = 291,
     YY_RESULT = 292,
     YY_SUBROUTINE = 293,
     YY_MODULE = 294,
     YY_BLOCK = 295,
     YY_IMPLICIT = 296,
     YY_NONE = 297,
     YY_USE = 298,
     YY_PARAMETER = 299,
     YY_FORMAT = 300,
     YY_ENTRY = 301
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_FOR90_TAB_H_INCLUDED  */
