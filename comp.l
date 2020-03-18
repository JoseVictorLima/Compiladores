%{
#include <string.h>
// {DECL} {return DECL;}
// DECL "var"
// STRING \'{STG}\'
// {PRINTS} {return PRINTS;}
%}

NUM [0-9]+\.?[0-9]*
VARS [a-z]+[0-9]*
COMENT "c\/\/"
STRING \"([^\\\"]|\\.)*\"
INIT "Init"
FIM "End"
IF "if"
ELSE "else"
WHILE "loop"
PRINT "pr"
PRINTS "prs"
ENTRA "ent"
ENTRAS "ents"
DECLI "int"
DECLF "fot"
DECLS "stg"
SQRT "sqrt:"

%%
{INIT} {return INIT;}
{FIM} {return FIM;}
{IF} {return IF;}
{ELSE} {return ELSE;}
{WHILE} {return WHILE;}
{PRINT} {return PRINT;}
{ENTRA} {return ENTRA;}
{ENTRAS} {return ENTRAS;}
{COMENT} {return COMENT;}

{NUM} {
	yylval.flo = atof(yytext);
	return NUM;
	}

{STRING} {
	strcpy(yylval.str,yytext);
	return STRING;
}

{DECLI} {
	return DECLI;
}
{DECLF} {
	return DECLF;
}
{DECLS} {
	return DECLS;
}
{VARS} {
	strcpy(yylval.str,yytext);
	return VARS;
	}

{SQRT} {
	return SQRT;
}

[-+()=/*^{};] {return *yytext;
			}
			

">" {yylval.fn = 1; return CMP; }
"<" {yylval.fn = 2; return CMP; }
"<>" {yylval.fn = 3; return CMP; }
"==" {yylval.fn = 4; return CMP; }
">=" {yylval.fn = 5; return CMP; }
"<=" {yylval.fn = 6; return CMP; }

[\ \n\t]*	{;}
. {printf("(%s) Ingonrado\n",yytext);}
%%