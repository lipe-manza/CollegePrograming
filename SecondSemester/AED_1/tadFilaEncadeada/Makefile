all: item.o fila.o main.o
	gcc item.o fila.o main.o -o fila 

item.o:
	gcc -c ../../TAD\ Item/item.c -o item.o -std=c99 -Wall

fila.o:
	gcc -c fila.c -I ../../TAD\ Item/ -o fila.o -std=c99 -Wall
	 
main.o:
	gcc -c main.c -I ../../TAD\ Item/ -o main.o -std=c99 -Wall
	 
clean:
	rm *.o fila
