#makefile V1

          

all:  main.c listas.c comboios.h
	gcc -g -Wall -pedantic -std=c99 main.c listas.c comboios.h -o train

comboios.o: comboios.h
	gcc -g -Wall -pedantic -std=c99 -c comboios.h


listas.o: comboios.h listas.c
	gcc -g -Wall -pedantic -std=c99 -c listas.c

main.o: main.c comboios.h listas.c
	gcc -g -Wall -pedantic -std=c99 -c main.c

train: main.o listas.o comboios.o
	gcc -g -Wall -pedantic -ansi main.o graficos.o comandos.o -o train