all: item.o listaencadeada.o main.o
	gcc item.o listaencadeada.o main.o -o listaencadeada -std=c99 -Wall
	
item.o:
	gcc -c ../TAD_Item/item.c -o item.o

listaencadeada.o:
	gcc -c listaencadeada.c -I ../TAD_Item/ -o listaencadeada.o
	 
main.o:
	gcc -c main_encadeada.c -I ../TAD_Item/ -o main.o
	 
clean:
	rm *.o listaencadeada
