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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
     COMMA = 258,
     OPEN_SQUARE_BRACKET = 259,
     CLOSED_SQUARE_BRACKET = 260,
     OPEN_ROUND_BRACKET = 261,
     CLOSED_ROUND_BRACKET = 262,
     OPEN_BRACE = 263,
     CLOSED_BRACE = 264,
     COLON = 265,
     SEMICOLON = 266,
     PLUS = 267,
     MINUS = 268,
     MULTIPLY = 269,
     DIVIDE = 270,
     MOD = 271,
     ASSIGNMENT_OP = 272,
     BOOL = 273,
     CHAR = 274,
     INTEGER = 275,
     INT = 276,
     STRING = 277,
     STR = 278,
     RELATION_OP = 279,
     LET = 280,
     IF = 281,
     ELSE = 282,
     WHILE = 283,
     INPUT = 284,
     OUTPUT = 285,
     VEC = 286,
     RETURN = 287,
     ID = 288,
     CHARACTER = 289
   };
#endif
/* Tokens.  */
#define COMMA 258
#define OPEN_SQUARE_BRACKET 259
#define CLOSED_SQUARE_BRACKET 260
#define OPEN_ROUND_BRACKET 261
#define CLOSED_ROUND_BRACKET 262
#define OPEN_BRACE 263
#define CLOSED_BRACE 264
#define COLON 265
#define SEMICOLON 266
#define PLUS 267
#define MINUS 268
#define MULTIPLY 269
#define DIVIDE 270
#define MOD 271
#define ASSIGNMENT_OP 272
#define BOOL 273
#define CHAR 274
#define INTEGER 275
#define INT 276
#define STRING 277
#define STR 278
#define RELATION_OP 279
#define LET 280
#define IF 281
#define ELSE 282
#define WHILE 283
#define INPUT 284
#define OUTPUT 285
#define VEC 286
#define RETURN 287
#define ID 288
#define CHARACTER 289



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

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
