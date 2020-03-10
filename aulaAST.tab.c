/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "aulaAST.y" /* yacc.c:337  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>	
int tipoPrint = 0;
char auxChar[255];
//Trigonometria
//Arquivo Certo
//estrutura de uma variável

typedef struct vars{ 
	char name[50];
	double valor;
	struct vars * prox;
}VARI;
	
//insere uma nova variável na lista de variáveis
VARI *ins(VARI*l,char n[]){
	VARI*new =(VARI*)malloc(sizeof(VARI));
	strcpy(new->name,n);
	new->prox = l;
	return new;
}

//busca uma variável na lista de variáveis
VARI *srch(VARI*l,char n[]){
	VARI*aux = l;
	while(aux != NULL){
		if(strcmp(n,aux->name)==0)
			return aux;
		aux = aux->prox;
	}
	return aux;
}

typedef struct strs{
	int nodetype;
	// int tipoS;
	char name[50];
	char valor[255];
	struct strs * prox;
}STRS;

typedef struct inters{
	int nodetype;
	// int tipoI;
	char name[50];
	int valor;
	struct inters * prox;
}INTERS;

typedef struct floaters{
	int nodetype;
	// int tipoF;
	char name[50];
	double valor;
	struct floaters * prox;
}FLOATERS;

//insere uma nova str na lista de variáveis
STRS * insereS(STRS*k,char n[]){
	STRS*new =(STRS*)malloc(sizeof(STRS));
	strcpy(new->name,n);
	new->prox = k;
	return new;
}

//insere um novo int na lista de inteiros
INTERS * insereI(INTERS*i,char n[]){
	INTERS*new =(INTERS*)malloc(sizeof(INTERS));
	strcpy(new->name,n);
	new->prox = i;
	return new;
}

//insere um novo float na lista de floats
FLOATERS * insereF(FLOATERS*f,char n[]){
	FLOATERS*new =(FLOATERS*)malloc(sizeof(FLOATERS));
	strcpy(new->name,n);
	new->prox = f;
	return new;
}

//busca uma str na lista de variáveis
STRS * buscaS(STRS*k,char n[]){
	STRS*aux = k;
	while(aux != NULL){
		if(strcmp(n,aux->name)==0)
			return aux;
		aux = aux->prox;
	}
	return aux;
}

//busca um int na lista de inteiros
INTERS * buscaI(INTERS*l,char n[]){
	INTERS*aux = l;
	while(aux != NULL){
		if(strcmp(n,aux->name)==0)
			return aux;
		aux = aux->prox;
	}
	return aux;
}

//busca um float na lista de floats
FLOATERS * buscaF(FLOATERS*f,char n[]){
	FLOATERS*aux = f;
	while(aux != NULL){
		if(strcmp(n,aux->name)==0)
			return aux;
		aux = aux->prox;
	}
	return aux;
}

VARI *l1;
INTERS *aux;
INTERS*i1 =NULL;
INTERS*auxl;
FLOATERS*f1 =NULL;
FLOATERS*auxf;
STRS*k1 = NULL;
STRS*auxk;
	
		
/*O node type serve para indicar o tipo de nó que está na árvore. Isso serve para a função eval() entender o que realizar naquele nó*/
typedef struct ast { /*Estrutura de um nó*/
	int nodetype;
	struct ast *l; /*Esquerda*/
	struct ast *r; /*Direita*/
}Ast; 

typedef struct numval { /*Estrutura de um número*/
	int nodetype;
	double number;
}Numval;

typedef struct varval { /*Estrutura de um nome de variável, nesse exemplo uma variável é um número no vetor var[26]*/
	int nodetype;
	char var[50];
}Varval;

typedef struct flow { /*Estrutura de um desvio (if/else/while)*/
	int nodetype;
	Ast *cond;		/*condição*/
	Ast *tl;		/*then, ou seja, verdade*/
	Ast *el;		/*else*/
}Flow;

typedef struct symasgn { /*Estrutura para um nó de atribuição. Para atrubior o valor de v em s*/
	int nodetype;
	char s[50];
	Ast *v;
}Symasgn;

Ast * newast(int nodetype, Ast *l, Ast *r){ /*Função para criar um nó*/

	Ast *a = (Ast*) malloc(sizeof(Ast));
	if(!a) {
		printf("out of space");
		exit(0);
	}
	a->nodetype = nodetype;
	a->l = l;
	a->r = r;
	return a;
}
 

// Ast * newValorValS(char s[255]) { /*Função que recupera o nome/referência de uma variável, neste caso o número*/
	
// 	STRS *a = (STRS*) malloc(sizeof(STRS));
// 	if(!a) {
// 		printf("out of space");
// 		exit(0);
// 	}
// 	a->nodetype = 'Q';
// 	strcpy(a->valor,s);
// 	return (Ast*)a;
	
// }

Ast * newvari(char nome[50],int tipoVar) {		/*Função de que cria uma nova variável*/
	INTERS * intCheck = buscaI(i1,nome);
	FLOATERS * floatCheck = buscaF(f1,nome);
	STRS * stingCheck = buscaS(k1,nome);
	if(intCheck!=NULL || floatCheck!=NULL || stingCheck!=NULL){
		printf("Variavel já declarada: %s\n",nome);
		exit(0);
	}
	if(tipoVar==1){
		FLOATERS * floatCheck = buscaF(f1,nome);
		STRS * stingCheck = buscaS(k1,nome);
		if(stingCheck!=NULL || floatCheck!=NULL){
			printf("Variavel já declarada: %s\n",nome);
			exit(0);
		}

		INTERS *a = (INTERS*) malloc(sizeof(INTERS));
		if(!a) {
			printf("out of space");
			exit(0);
		}
		// a->tipoVar = 1;
		a->nodetype = 'A';
		strcpy(a->name,nome);
		return (Ast*)a;
	}
	else if(tipoVar==2){
		FLOATERS *a = (FLOATERS*) malloc(sizeof(FLOATERS));
		if(!a) {
			printf("out of space");
			exit(0);
		}
		a->nodetype = 'B';
		strcpy(a->name,nome);
		return (Ast*)a;
	}
	else if(tipoVar==3){
		STRS *a = (STRS*) malloc(sizeof(STRS));
		if(!a) {
			printf("out of space");
			exit(0);
		}
		a->nodetype = 'C';
		strcpy(a->name,nome);
		return (Ast*)a;
	}
}

Ast * newnum(double d) {			/*Função de que cria um novo número*/
	Numval *a = (Numval*) malloc(sizeof(Numval));
	if(!a) {
		printf("out of space");
		exit(0);
	}
	a->nodetype = 'K';
	a->number = d;
	return (Ast*)a;
}	
	
Ast * newflow(int nodetype, Ast *cond, Ast *tl, Ast *el){ /*Função que cria um nó de if/else/while*/
	Flow *a = (Flow*)malloc(sizeof(Flow));
	if(!a) {
		printf("out of space");
	exit(0);
	}
	a->nodetype = nodetype;
	a->cond = cond;
	a->tl = tl;
	a->el = el;
	return (Ast *)a;
}

Ast * newcmp(int cmptype, Ast *l, Ast *r){ /*Função que cria um nó para testes*/
	Ast *a = (Ast*)malloc(sizeof(Ast));
	if(!a) {
		printf("out of space");
	exit(0);
	}
	a->nodetype = '0' + cmptype; /*Para pegar o tipe de teste, definido no arquivo.l e utilizar na função eval()*/
	a->l = l;
	a->r = r;
	return a;
}

Ast * newasgn(char s[50], Ast *v) { /*Função para um nó de atribuição*/
	Symasgn *a = (Symasgn*)malloc(sizeof(Symasgn));
	if(!a) {
		printf("out of space");
	exit(0);
	}
	a->nodetype = '=';
	strcpy(a->s,s);
	//a->s = s; /*Símbolo/variável*/
	a->v = v; /*Valor*/
	return (Ast *)a;
}


Ast * newValorVal(char s[50]) { /*Função que recupera o nome/referência de uma variável, neste caso o número*/
	
	Varval *a = (Varval*) malloc(sizeof(Varval));
	if(!a) {
		printf("out of space");
		exit(0);
	}
	a->nodetype = 'N';
	strcpy(a->var,s);
	return (Ast*)a;
	
}



// char * eval2(Ast *a) { /*Função que executa operações a partir de um nó*/
	// 	STRS *aux1;
	// 	char *v2;
		
	// 		switch(a->nodetype) {
			
	// 		case 'Q':
	// 			aux1 = buscaS(k1,((STRS *)a)->valor);
	// 			return aux1->valor;
	// 			break;

	// 		default: printf("internal error: bad node %c\n", a->nodetype);
	// 				break;
	// 	}
		
	// return v2;
	// }

double eval(Ast *a) { /*Função que executa operações a partir de um nó*/
	double v;
	float oi;
	int v1;
	char * v2;
	VARI * aux;
	INTERS * aux1;
	FLOATERS * aux2;
	STRS * aux3;
	if(!a) {
		printf("internal error, null eval");
		return 0.0;
	}
	switch(a->nodetype) {
		case 'K': v = ((Numval *)a)->number; break; 	/*Recupera um número*/
		// case 'A': v = ((INTERS *)a)->valor; break; 	/*Recupera um número*/
		// case 'B': v = ((FLOATERS *)a)->valor; break; 	/*Recupera um número*/
		// case 'C': v = ((STRS *)a)->valor; break; 	/*Recupera um número*/
		case 'N': //Case N recupera os valores 
			aux1 = buscaI(i1,((INTERS *)a)->name);
			if(aux1!=NULL){
				v = aux1->valor;
				tipoPrint = 1;
			}
			else {
				aux2 = buscaF(f1,((FLOATERS *)a)->name);
				if(aux2!=NULL){
					v = aux2->valor;
					tipoPrint = 2;
				} else {
					aux3 = buscaS(k1,((STRS *)a)->name);
					if(aux3!=NULL){
						tipoPrint = 3;
						strcpy(auxChar,aux3->valor);
					}
				}
			} 
			break;
		case '+': v = eval(a->l) + eval(a->r); break;	/*Operações "árv esq   +   árv dir"*/
		case '-': v = eval(a->l) - eval(a->r); break;	/*Operações*/
		case '*': v = eval(a->l) * eval(a->r); break;	/*Operações*/
		case '/': v = eval(a->l) / eval(a->r); break; /*Operações*/
		case '^': v = pow(eval(a->l),eval(a->r)); break; /*Operações*/
		case 'R': v = sqrt(eval(a->r)); break;  /*Operações*/
		case 'M': v = -eval(a->l); break;				/*Operações, número negativo*/
	
		case '1': v = (eval(a->l) > eval(a->r))? 1 : 0; break;	/*Operações lógicas. "árv esq   >   árv dir"  Se verdade 1, falso 0*/
		case '2': v = (eval(a->l) < eval(a->r))? 1 : 0; break;
		case '3': v = (eval(a->l) != eval(a->r))? 1 : 0; break;
		case '4': v = (eval(a->l) == eval(a->r))? 1 : 0; break;
		case '5': v = (eval(a->l) >= eval(a->r))? 1 : 0; break;
		case '6': v = (eval(a->l) <= eval(a->r))? 1 : 0; break;
		
		case '=':
			v = eval(((Symasgn *)a)->v); /*Recupera o valor*/
			aux1 = buscaI(i1,((Symasgn *)a)->s);
			if(aux1!=NULL){
				aux1->valor = v;
			}
			else{ 
				aux2 = buscaF(f1,((Symasgn *)a)->s);
				if(aux2!=NULL){
					aux2->valor = v;
				} else{
					aux3 = buscaS(k1,((Symasgn *)a)->s);
					if(aux3!=NULL){
						strcpy(auxChar,aux3->valor);
					}
				}
			} 
			// aux1->valor = v;
				
			// printf("%fl",v);
			break;
		
		case 'I':						/*CASO IF*/
			;
			oi = eval(((Flow *)a)->cond);
			printf("%f",oi);
			if (eval(((Flow *)a)->cond) != 0) {	/*executa a condição / teste*/
				if (((Flow *)a)->tl)		/*Se existir árvore*/
					v = eval(((Flow *)a)->tl); /*Verdade*/
				else
					v = 0.0;
			} else {
				if( ((Flow *)a)->el) {
					v = eval(((Flow *)a)->el); /*Falso*/
				} else
					v = 0.0;
				}
			break;
			
		case 'W':
			//printf ("WHILE\n");
			v = 0.0;
			if( ((Flow *)a)->tl) {
				while( eval(((Flow *)a)->cond) != 0){
					//printf ("VERDADE\n");
					v = eval(((Flow *)a)->tl);
					}
			}
		break;
			
		case 'L': eval(a->l); v = eval(a->r); break; /*Lista de operções em um bloco IF/ELSE/WHILE. Assim o analisador não se perde entre os blocos*/
		
		// case 'Y':	
		// 		v2 = eval2(a->l);		/*Recupera um valor STR*/
		// 		printf ("%s\n",v2); break;  /*Função que imprime um valor (string)*/
		// 		printf ("imprimiu\n");
		// 		break;

		case 'P': 

					v = eval(a->l);		/*Recupera um valor*/
					if(tipoPrint==1) {printf ("%.0f\n",v); }  /*Função que imprime um valor*/
					else if(tipoPrint==2) {printf ("%.2f\n",v); }
					else if(tipoPrint==3) { printf("%s\n",auxChar);}
					else{ 
						printf ("Variável não declarada\n");
					}
					// else if(a->tipoVar == 2) ("%.2f\n",v); 
					// else if(a->tipoVar == 3) ("%.2f\n",v); 
					break;

		case 'S':
					// aux1 = buscaI(i1,((Symasgn *)a)->s);
					// if(aux1!=NULL){
					// 	printf("Funcionou")
					// }
					break;

		case 'A': 	i1 = insereI(i1,((INTERS*)a)->name); 
					break;
		case 'B': 	f1 = insereF(f1,((FLOATERS*)a)->name); 
					break;
		case 'C': 	k1 = insereS(k1,((STRS*)a)->name);
					break;
			
		default: printf("internal error: bad node %c\n", a->nodetype);
				
	}
	return v;
}

int yylex();
void yyerror (char *s){
	printf("%s\n", s);
}


#line 536 "aulaAST.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


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
    NUM = 258,
    VARS = 259,
    STRING = 260,
    INIT = 261,
    FIM = 262,
    IF = 263,
    ELSE = 264,
    WHILE = 265,
    PRINT = 266,
    DECL = 267,
    ENTRA = 268,
    ENTRAS = 269,
    SQRT = 270,
    CMP = 271,
    DECLI = 272,
    DECLF = 273,
    DECLS = 274,
    IFX = 275,
    NEG = 276
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 467 "aulaAST.y" /* yacc.c:352  */

	float flo;
	int fn;
	int inter;
	char str[50];
	char stg[255];
	Ast *a;
	

#line 608 "aulaAST.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   203

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  6
/* YYNRULES -- Number of rules.  */
#define YYNRULES  29
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  73

#define YYUNDEFTOK  2
#define YYMAXUTOK   276

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      27,    28,    23,    21,     2,    22,     2,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    20,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    31,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,    30,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   496,   496,   499,   500,   506,   507,   508,   509,   510,
     532,   545,   546,   560,   584,   585,   586,   589,   590,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "VARS", "STRING", "INIT", "FIM",
  "IF", "ELSE", "WHILE", "PRINT", "DECL", "ENTRA", "ENTRAS", "SQRT", "CMP",
  "DECLI", "DECLF", "DECLS", "'='", "'+'", "'-'", "'*'", "'/'", "IFX",
  "NEG", "'('", "')'", "'{'", "'}'", "'^'", "$accept", "val", "prog",
  "stmt", "list", "exp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      61,    43,    45,    42,    47,   275,   276,    40,    41,   123,
     125,    94
};
# endif

#define YYPACT_NINF -54

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-54)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,   129,     7,   -10,   -19,    -9,    -6,    -5,    -4,    20,
      21,    22,   117,   -54,   -54,    52,    96,    96,    93,    30,
      31,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,    96,
      96,    96,   172,   128,   139,     8,   150,    10,    13,   172,
      14,   161,    96,    96,    96,    96,    96,    96,    15,    23,
     -54,   -54,   -54,   -54,   -54,    14,   -11,   -11,   -12,   -12,
     172,   129,   129,   -54,    29,    58,    40,   -54,   -54,    24,
     129,    76,   -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     1,     0,     0,     0,     0,     0,
       0,    14,    15,    16,     2,     4,    28,    29,     9,     0,
       0,     0,     8,     0,     0,     0,     0,     0,     0,    24,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,    13,    12,    26,    25,    19,    20,    21,    22,
      23,     0,     0,    17,     0,     0,     5,    18,     7,     0,
       0,     0,     6
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -54,   -54,   -54,    -1,   -53,   -15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    12,    63,    64,    32
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      13,    33,    34,    36,    42,    42,     1,    14,    16,    65,
      15,    25,    45,    46,    39,    40,    41,    71,    17,    47,
      47,    18,    19,    20,    21,    22,    23,    55,    56,    57,
      58,    59,    60,     3,    37,    38,    50,     4,    52,     5,
       6,    53,     7,     8,    61,    47,     9,    10,    11,    69,
       0,     0,    62,    70,     0,    26,    27,    28,     0,    66,
       0,     0,     3,    67,    67,     0,     4,    29,     5,     6,
      67,     7,     8,     0,    30,     9,    10,    11,     0,    31,
       3,     0,     0,     0,     4,     0,     5,     6,    68,     7,
       8,     0,     0,     9,    10,    11,    26,    27,    35,    26,
      27,     0,     0,     0,     0,     0,    72,     0,    29,     0,
       0,    29,     0,     0,     0,    30,     0,     0,    30,     0,
      31,     3,     0,    31,    24,     4,     0,     5,     6,     0,
       7,     8,     0,     3,     9,    10,    11,     4,     0,     5,
       6,     0,     7,     8,    42,     0,     9,    10,    11,    43,
      44,    45,    46,     0,     0,    42,    48,     0,     0,    47,
      43,    44,    45,    46,     0,     0,    42,    49,     0,     0,
      47,    43,    44,    45,    46,     0,     0,    42,    51,     0,
       0,    47,    43,    44,    45,    46,     0,     0,    42,    54,
       0,     0,    47,    43,    44,    45,    46,     0,     0,     0,
       0,     0,     0,    47
};

static const yytype_int8 yycheck[] =
{
       1,    16,    17,    18,    16,    16,     6,     0,    27,    62,
      20,    12,    23,    24,    29,    30,    31,    70,    27,    31,
      31,    27,    27,    27,     4,     4,     4,    42,    43,    44,
      45,    46,    47,     4,     4,     4,    28,     8,    28,    10,
      11,    28,    13,    14,    29,    31,    17,    18,    19,     9,
      -1,    -1,    29,    29,    -1,     3,     4,     5,    -1,    30,
      -1,    -1,     4,    64,    65,    -1,     8,    15,    10,    11,
      71,    13,    14,    -1,    22,    17,    18,    19,    -1,    27,
       4,    -1,    -1,    -1,     8,    -1,    10,    11,    30,    13,
      14,    -1,    -1,    17,    18,    19,     3,     4,     5,     3,
       4,    -1,    -1,    -1,    -1,    -1,    30,    -1,    15,    -1,
      -1,    15,    -1,    -1,    -1,    22,    -1,    -1,    22,    -1,
      27,     4,    -1,    27,     7,     8,    -1,    10,    11,    -1,
      13,    14,    -1,     4,    17,    18,    19,     8,    -1,    10,
      11,    -1,    13,    14,    16,    -1,    17,    18,    19,    21,
      22,    23,    24,    -1,    -1,    16,    28,    -1,    -1,    31,
      21,    22,    23,    24,    -1,    -1,    16,    28,    -1,    -1,
      31,    21,    22,    23,    24,    -1,    -1,    16,    28,    -1,
      -1,    31,    21,    22,    23,    24,    -1,    -1,    16,    28,
      -1,    -1,    31,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    33,     4,     8,    10,    11,    13,    14,    17,
      18,    19,    34,    35,     0,    20,    27,    27,    27,    27,
      27,     4,     4,     4,     7,    35,     3,     4,     5,    15,
      22,    27,    37,    37,    37,     5,    37,     4,     4,    37,
      37,    37,    16,    21,    22,    23,    24,    31,    28,    28,
      28,    28,    28,    28,    28,    37,    37,    37,    37,    37,
      37,    29,    29,    35,    36,    36,    30,    35,    30,     9,
      29,    36,    30
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    36,    36,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     2,     7,    11,     7,     3,     3,
       4,     4,     4,     4,     2,     2,     2,     1,     2,     3,
       3,     3,     3,     3,     2,     3,     3,     2,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 499 "aulaAST.y" /* yacc.c:1652  */
    {eval((yyvsp[0].a));}
#line 1763 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 500 "aulaAST.y" /* yacc.c:1652  */
    {eval((yyvsp[0].a));}
#line 1769 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 506 "aulaAST.y" /* yacc.c:1652  */
    { (yyval.a) = newflow('I', (yyvsp[-1].a), (yyvsp[-4].a), NULL);}
#line 1775 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 507 "aulaAST.y" /* yacc.c:1652  */
    {(yyval.a) = newflow('I', (yyvsp[-8].a), (yyvsp[-5].a), (yyvsp[-1].a));}
#line 1781 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 508 "aulaAST.y" /* yacc.c:1652  */
    {(yyval.a) = newflow('W', (yyvsp[-4].a), (yyvsp[-1].a), NULL);}
#line 1787 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 509 "aulaAST.y" /* yacc.c:1652  */
    {(yyval.a) = newasgn((yyvsp[-2].str),(yyvsp[0].a));}
#line 1793 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 510 "aulaAST.y" /* yacc.c:1652  */
    {
		char new[255];
		int last = sizeof((yyvsp[0].stg))/sizeof(char);
		int aux = 0;
		STRS * stingCheck = buscaS(k1,(yyvsp[-2].str));
		if(stingCheck!=NULL){
			for(int i = 0;i<last;i++){
				if((yyvsp[0].stg)[i]!=34){
					new[aux] = (yyvsp[0].stg)[i];
					aux++;
				}
			}
			strcpy(stingCheck->valor,new);
			
		} else {
			if(stingCheck == NULL){
				printf ("Variável não declarada : %s\n",(yyvsp[0].stg));
			}
		}
		(yyval.a) = newasgn((yyvsp[0].stg),newnum(1));
	}
#line 1819 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 532 "aulaAST.y" /* yacc.c:1652  */
    {
		char new[255];
		int last = sizeof((yyvsp[-1].stg))/sizeof(char);
		int aux = 0;
		for(int i = 0;i<last;i++){
			if((yyvsp[-1].stg)[i]!=34){
				new[aux] = (yyvsp[-1].stg)[i];
				aux++;
			}
		}
		printf ("%s \n",new);
		(yyval.a) = newasgn((yyvsp[-1].stg),newnum(1));
	}
#line 1837 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 545 "aulaAST.y" /* yacc.c:1652  */
    { (yyval.a) = newast('P',(yyvsp[-1].a),NULL);}
#line 1843 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 546 "aulaAST.y" /* yacc.c:1652  */
    {
		char s[255];
		STRS * stingCheck = buscaS(k1,(yyvsp[-1].str));
		if(stingCheck!=NULL){
			printf ("Entrada : ");
			scanf ("%s",s);
			strcpy(stingCheck->valor,s);
			(yyval.a) = newasgn((yyvsp[-1].str),newnum(1));
		} else {
			if(stingCheck == NULL){
				printf ("Variável não declarada : %s\n",(yyvsp[-1].str));
			}
		}
	}
#line 1862 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 560 "aulaAST.y" /* yacc.c:1652  */
    { 
		float v;
		INTERS * intCheck = buscaI(i1,(yyvsp[-1].str));
		if(intCheck!=NULL){
			printf ("Entrada : ");
			scanf ("%f",&v);
			(yyval.a) = newasgn((yyvsp[-1].str),newnum(v));
		}
		else {
			FLOATERS * floatCheck = buscaF(f1,(yyvsp[-1].str));
			if(floatCheck!=NULL){
				printf ("Entrada : ");
				scanf ("%f",&v);
				(yyval.a) = newasgn((yyvsp[-1].str),newnum(v));
			} else {
				if(intCheck == NULL && floatCheck ==NULL){
				printf ("Variável não declarada : %s\n",(yyvsp[-1].str));
				}
			}
		}
		
		
	}
#line 1890 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 584 "aulaAST.y" /* yacc.c:1652  */
    { (yyval.a) = newvari((yyvsp[0].str),1);}
#line 1896 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 585 "aulaAST.y" /* yacc.c:1652  */
    { (yyval.a) = newvari((yyvsp[0].str),2);}
#line 1902 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 586 "aulaAST.y" /* yacc.c:1652  */
    { (yyval.a) = newvari((yyvsp[0].str),3);}
#line 1908 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 589 "aulaAST.y" /* yacc.c:1652  */
    {(yyval.a) = (yyvsp[0].a);}
#line 1914 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 590 "aulaAST.y" /* yacc.c:1652  */
    { (yyval.a) = newast('L', (yyvsp[-1].a), (yyvsp[0].a));	}
#line 1920 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 594 "aulaAST.y" /* yacc.c:1652  */
    {(yyval.a) = newast('+',(yyvsp[-2].a),(yyvsp[0].a));}
#line 1926 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 595 "aulaAST.y" /* yacc.c:1652  */
    {(yyval.a) = newast('-',(yyvsp[-2].a),(yyvsp[0].a));}
#line 1932 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 596 "aulaAST.y" /* yacc.c:1652  */
    {(yyval.a) = newast('*',(yyvsp[-2].a),(yyvsp[0].a));}
#line 1938 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 597 "aulaAST.y" /* yacc.c:1652  */
    {(yyval.a) = newast('/',(yyvsp[-2].a),(yyvsp[0].a));}
#line 1944 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 598 "aulaAST.y" /* yacc.c:1652  */
    {(yyval.a) = newast('^',(yyvsp[-2].a),(yyvsp[0].a));}
#line 1950 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 599 "aulaAST.y" /* yacc.c:1652  */
    {(yyval.a) = newast('R',newnum(1),(yyvsp[0].a));}
#line 1956 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 600 "aulaAST.y" /* yacc.c:1652  */
    {(yyval.a) = newcmp((yyvsp[-1].fn),(yyvsp[-2].a),(yyvsp[0].a));}
#line 1962 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 601 "aulaAST.y" /* yacc.c:1652  */
    {(yyval.a) = (yyvsp[-1].a);}
#line 1968 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 602 "aulaAST.y" /* yacc.c:1652  */
    {(yyval.a) = newast('M',(yyvsp[0].a),NULL);}
#line 1974 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 603 "aulaAST.y" /* yacc.c:1652  */
    {(yyval.a) = newnum((yyvsp[0].flo));}
#line 1980 "aulaAST.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 604 "aulaAST.y" /* yacc.c:1652  */
    {(yyval.a) = newValorVal((yyvsp[0].str));}
#line 1986 "aulaAST.tab.c" /* yacc.c:1652  */
    break;


#line 1990 "aulaAST.tab.c" /* yacc.c:1652  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 610 "aulaAST.y" /* yacc.c:1918  */


#include "lex.yy.c"

int main(){
	
	yyin=fopen("entrada.txt","r");
	yyparse();
	yylex();
	fclose(yyin);
return 0;
}

