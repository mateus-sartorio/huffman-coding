all: limpasaida clean compacta descompacta criasaida

compila: *.c
	gcc -c $^

descompacta:
	gcc bitmap.c arvore.c Descompacta.c Dmain.c -o Descompacta

compacta:
	gcc bitmap.c arvore.c Compacta.c Cmain.c -o Compacta

criasaida:
	mkdir Saida

limpasaida:
	rm -rf ./Saida

executa:
	valgrind ./Compacta lorem.txt

%.o: %.c 
	gcc -c $<

clean:
	rm -rf *.o *.comp
	rm -rf Compacta Descompacta