/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM_D = 258,
    NUM_I = 259,
    NUM_F = 260,
    CAR = 261,
    CAD = 262,
    IF = 263,
    FLOAT = 264,
    DOUBLE = 265,
    CHAR = 266,
    BOOL = 267,
    INT = 268,
    ELSE = 269,
    _TRUE = 270,
    _FALSE = 271,
    MAS = 272,
    RES = 273,
    MUL = 274,
    MOD = 275,
    DIV = 276,
    IGU_IGU = 277,
    DIF = 278,
    MAY_IGU = 279,
    MEN_IGU = 280,
    MEN = 281,
    MAY = 282,
    IGU = 283,
    ID = 284,
    WHILE = 285,
    MAS_IGU = 286,
    RES_IGU = 287,
    MUL_IGU = 288,
    DIV_IGU = 289,
    MOD_IGU = 290,
    PYC = 291,
    COM = 292,
    LLA = 293,
    LLC = 294,
    PAA = 295,
    PAC = 296,
    FOR = 297,
    SWITCH = 298,
    CASE = 299,
    BREAK = 300,
    VOID = 301,
    PRINT = 302,
    SCAN = 303,
    STRUCT = 304,
    RETURN = 305,
    DO = 306,
    COA = 307,
    COC = 308,
    DEFAULT = 309,
    OR = 310,
    AND = 311,
    NOT = 312,
    MAS_MAS = 313,
    RES_RES = 314,
    DPT = 315,
    PT = 316
  };
#endif
/* Tokens.  */
#define NUM_D 258
#define NUM_I 259
#define NUM_F 260
#define CAR 261
#define CAD 262
#define IF 263
#define FLOAT 264
#define DOUBLE 265
#define CHAR 266
#define BOOL 267
#define INT 268
#define ELSE 269
#define _TRUE 270
#define _FALSE 271
#define MAS 272
#define RES 273
#define MUL 274
#define MOD 275
#define DIV 276
#define IGU_IGU 277
#define DIF 278
#define MAY_IGU 279
#define MEN_IGU 280
#define MEN 281
#define MAY 282
#define IGU 283
#define ID 284
#define WHILE 285
#define MAS_IGU 286
#define RES_IGU 287
#define MUL_IGU 288
#define DIV_IGU 289
#define MOD_IGU 290
#define PYC 291
#define COM 292
#define LLA 293
#define LLC 294
#define PAA 295
#define PAC 296
#define FOR 297
#define SWITCH 298
#define CASE 299
#define BREAK 300
#define VOID 301
#define PRINT 302
#define SCAN 303
#define STRUCT 304
#define RETURN 305
#define DO 306
#define COA 307
#define COC 308
#define DEFAULT 309
#define OR 310
#define AND 311
#define NOT 312
#define MAS_MAS 313
#define RES_RES 314
#define DPT 315
#define PT 316

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 14 "parser.y" /* yacc.c:1909  */

	struct{
	int pos;
	int line;
    int ival;
    float fval ;
    double dval ;
    char cval;
    char * sval ;
	}y;

#line 188 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
