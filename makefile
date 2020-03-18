all : comp.l comp.y
	clear
	flex -i comp.l
	bison comp.y
	gcc comp.tab.c -o analisador -lfl -lm
	./analisador
