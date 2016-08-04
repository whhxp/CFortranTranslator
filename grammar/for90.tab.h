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
     YY_REQ_MORE = 258,
     YY_GT = 259,
     YY_GE = 260,
     YY_EQ = 261,
     YY_LE = 262,
     YY_LT = 263,
     YY_NEQ = 264,
     YY_NEQV = 265,
     YY_EQV = 266,
     YY_ANDAND = 267,
     YY_OROR = 268,
     YY_NOT = 269,
     YY_POWER = 270,
     YY_DOUBLECOLON = 271,
     YY_NEG = 272,
     YY_INTEGER = 273,
     YY_FLOAT = 274,
     YY_WORD = 275,
     YY_OPERATOR = 276,
     YY_STRING = 277,
     YY_ILLEGAL = 278,
     YY_COMPLEX = 279,
     YY_TRUE = 280,
     YY_FALSE = 281,
     YY_IF = 282,
     YY_THEN = 283,
     YY_ELSE = 284,
     YY_ELSEIF = 285,
     YY_ENDIF = 286,
     YY_DO = 287,
     YY_ENDDO = 288,
     YY_CONTINUE = 289,
     YY_WHILE = 290,
     YY_ENDWHILE = 291,
     YY_WHERE = 292,
     YY_ENDWHERE = 293,
     YY_CASE = 294,
     YY_ENDCASE = 295,
     YY_PROGRAM = 296,
     YY_ENDPROGRAM = 297,
     YY_FUNCTION = 298,
     YY_ENDFUNCTION = 299,
     YY_RECURSIVE = 300,
     YY_RESULT = 301,
     YY_SUBROUTINE = 302,
     YY_ENDSUBROUTINE = 303,
     YY_MODULE = 304,
     YY_ENDMODULE = 305,
     YY_BLOCK = 306,
     YY_ENDBLOCK = 307,
     YY_IMPLICIT = 308,
     YY_NONE = 309,
     YY_USE = 310,
     YY_PARAMETER = 311,
     YY_FORMAT = 312,
     YY_ENTRY = 313,
     YY_INTEGER_T = 314,
     YY_FLOAT_T = 315,
     YY_STRING_T = 316,
     YY_COMPLEX_T = 317,
     YY_BOOL_T = 318,
     YY_WRITE = 319,
     YY_READ = 320,
     YY_PRINT = 321,
     YY_OPEN = 322,
     YY_CLOSE = 323
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
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
