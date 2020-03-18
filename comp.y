%{
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
 

Ast * newValorValS(char s[255], char node) { /*Função que recupera o nome/referência de uma variável, neste caso o número*/
	
	STRS *a = (STRS*) malloc(sizeof(STRS));
	if(!a) {
		printf("out of space");
		exit(0);
	}
	a->nodetype = node;
	strcpy(a->valor,s);
	return (Ast*)a;
	
}

Ast * newvari(char nome[50],int tipoVar) {		/*Função de que cria uma nova variável*/
	INTERS * intCheck = buscaI(i1,nome);
	FLOATERS * floatCheck = buscaF(f1,nome);
	STRS * stringCheck = buscaS(k1,nome);
	if(intCheck!=NULL || floatCheck!=NULL || stringCheck!=NULL){
		printf("Variavel já declarada: %s\n",nome);
		exit(0);
	}
	if(tipoVar==1){
		FLOATERS * floatCheck = buscaF(f1,nome);
		STRS * stringCheck = buscaS(k1,nome);
		if(stringCheck!=NULL || floatCheck!=NULL){
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


Ast * emptyAst(int nodetype){ /*Função para criar um nó*/

	Ast *a = (Ast*) malloc(sizeof(Ast));
	if(!a) {
		printf("out of space");
		exit(0);
	}
	a->nodetype = nodetype;
	return a;
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



char * eval2(Ast *a) { /*Função que executa operações a partir de um nó*/
		STRS *aux1;
		char *v2;
			// printf("%s \n",((STRS *)a)->name);
			switch(a->nodetype) {
			
			case 'N':
				aux1 = buscaS(k1,((STRS *)a)->name);
				if(aux1!=NULL){
					// char new[255];
					// int last = sizeof(aux1->valor)/sizeof(char);
					// int aux = 0;
					// for(int i = 0;i<last;i++){
					// 	if(aux1->valor[i]!=34){
					// 		new[aux] = aux1->valor[i];
					// 		aux++;
					// 	}
					// }
					// printf ("%s \n",aux1->valor);
					v2 = aux1->valor;
				}
				break;

			case 'Q':
				aux1 = buscaS(k1,((STRS *)a)->valor);
				return aux1->valor;
				break;
			
			case 'S':
				if(((STRS *)a)->valor!=NULL){
					printf ("%s \n",((STRS *)a)->valor);
				}
				// aux1 = buscaS(k1,((STRS *)a)->valor);
				// if(aux1!=NULL){
				// 	printf("aqui");
					// char new[255];
					// int last = sizeof(aux1->valor)/sizeof(char);
					// int aux = 0;
					// for(int i = 0;i<last;i++){
					// 	if(aux1->valor[i]!=34){
					// 		new[aux] = aux1->valor[i];
					// 		aux++;
					// 	}
					// }
				// 	printf ("%s \n",aux1->valor);
				// }
				break;

			default: printf("internal error: bad node %c\n", a->nodetype);
					break;
		}
		
	return v2;
	}

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
		case '0': break;
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
				} 
				else {
					aux3 = buscaS(k1,((STRS *)a)->name);
					if(aux3!=NULL){
						// v = 0;
						tipoPrint = 3;
				// 		strcpy(auxChar,aux3->valor);
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
					} else{
						printf ("Variável não declarada \n");
					}
				}
			} 
			// aux1->valor = v;
				
			// printf("%fl",v);
			break;
		
		case 'I':						/*CASO IF*/
			if (eval(((Flow *)a)->cond) != 0) {	/*executa a condição / teste*/
				if (((Flow *)a)->tl){		/*Se existir árvore*/
					v = eval(((Flow *)a)->tl); /*Verdade*/
				}
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
					else if(tipoPrint==3) { 
						// printf("%s \n",((STRS *)a)->name);
						printf("%s \n",eval2(a->l));
						}
					else{ 
						printf ("Variável não declarada\n");
					}
					// else if(a->tipoVar == 2) ("%.2f\n",v); 
					// else if(a->tipoVar == 3) ("%.2f\n",v); 
					break;

		case 'S':
					eval2(a);
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

%}

%union{
	float flo;
	int fn;
	int inter;
	char str[50];
	char stg[255];
	Ast *a;
	}

%token <flo>NUM
%token <str>VARS
%token <stg>STRING
%token INIT FIM IF ELSE WHILE PRINT DECL ENTRA ENTRAS SQRT COMENT
%token <fn> CMP
%token DECLI
%token DECLF
%token DECLS
%right '='
%left '+' '-'
%left '*' '/'
%left CMP

%type <a> exp list stmt prog
// exp1

%nonassoc IFX NEG

%%

val: INIT prog FIM
	;

prog: stmt 		{eval($1);}  /*Inicia e execução da árvore de derivação*/
	| prog stmt {eval($2);}	 /*Inicia e execução da árvore de derivação*/
	;
	
/*Funções para análise sintática e criação dos nós na AST*/	
/*Verifique q nenhuma operação é realizada na ação semântica, apenas são criados nós na árvore de derivação com suas respectivas operações*/
	
stmt: COMENT stmt {
		$$ = emptyAst('0');
		}
	| IF '(' exp ')' '{' list '}' %prec IFX { $$ = newflow('I', $3, $6, NULL);}
	| IF '(' exp ')' '{' list '}' ELSE '{' list '}' {$$ = newflow('I', $3, $6, $10);}
	| WHILE '(' exp ')' '{' list '}' {$$ = newflow('W', $3, $6, NULL);}
	| VARS '=' exp {$$ = newasgn($1,$3);}
	| VARS '=' STRING {
		char new[255];
		int last = sizeof($3)/sizeof(char);
		int aux = 0;
		STRS * stringCheck = buscaS(k1,$1);
		if(stringCheck!=NULL){
			for(int i = 0;i<last;i++){
				if($3[i]!=34){
					new[aux] = $3[i];
					aux++;
				}
			}
			strcpy(stringCheck->valor,new);
			// printf("aqui \n");
		} else {
			if(stringCheck == NULL){
				printf ("Variável não declarada : %s\n",$3);
			}
		}
		$$ = emptyAst('0');
	}
	| PRINT '(' STRING ')' {
		char new[255];
		int last = sizeof($3)/sizeof(char);
		int aux = 0;
		for(int i = 0;i<last;i++){
			if($3[i]!=34){
				new[aux] = $3[i];
				aux++;
			}
		}
		
		$$ = newValorValS(new,'S');
	}	
	| PRINT '(' exp ')' { $$ = newast('P',$3,NULL);}
	| ENTRAS '('VARS')'	{
		char s[255];
		STRS * stringCheck = buscaS(k1,$3);
		if(stringCheck!=NULL){
			printf ("Entrada : ");
			scanf ("%s",s);
			strcpy(stringCheck->valor,s);
			$$ = newasgn($3,newnum(1));
		} else {
			if(stringCheck == NULL){
				printf ("Variável não declarada : %s\n",$3);
			}
		}
	}
	| ENTRA '(' VARS ')' { 
		float v;
		INTERS * intCheck = buscaI(i1,$3);
		if(intCheck!=NULL){
			printf ("Entrada : ");
			scanf ("%f",&v);
			$$ = newasgn($3,newnum(v));
		}
		else {
			FLOATERS * floatCheck = buscaF(f1,$3);
			if(floatCheck!=NULL){
				printf ("Entrada : ");
				scanf ("%f",&v);
				$$ = newasgn($3,newnum(v));
			} else {
				if(intCheck == NULL && floatCheck ==NULL){
				printf ("Variável não declarada : %s\n",$3);
				}
			}
		}
		
		
	};
	| DECLI VARS	{ $$ = newvari($2,1);}
	| DECLF VARS	{ $$ = newvari($2,2);}
	| DECLS VARS	{ $$ = newvari($2,3);}
	;

list:	  stmt{$$ = $1;}
		| list stmt { $$ = newast('L', $1, $2);	}
		;
	
exp: 
	 exp '+' exp {$$ = newast('+',$1,$3);}		/*Expressões matemáticas*/
	|exp '-' exp {$$ = newast('-',$1,$3);}
	|exp '*' exp {$$ = newast('*',$1,$3);}
	|exp '/' exp {$$ = newast('/',$1,$3);}
	|exp '^' exp {$$ = newast('^',$1,$3);}
	|SQRT exp {$$ = newast('R',newnum(1),$2);}
	|exp CMP exp {$$ = newcmp($2,$1,$3);}		/*Testes condicionais*/
	|'(' exp ')' {$$ = $2;}
	|'-' exp %prec NEG {$$ = newast('M',$2,NULL);}
	|NUM {$$ = newnum($1);}						/*token de um número*/
	|VARS {$$ = newValorVal($1);}				/*token de uma variável*/

	;
// exp1: 
// 	VARS {$$ = newValorValS($1);}				
// 	;
%%

#include "lex.yy.c"

int main(){
	yyin=fopen("entrada.vc","r");
	yyparse();
	yylex();
	fclose(yyin);
return 0;
}

