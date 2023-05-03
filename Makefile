#NOME = g++
#$(NOME)

all:
	echo "Ola Mundo!"

compilar: main.cpp gestor.cpp atendente.cpp
	g++ -c main.cpp gestor.cpp atendente.cpp

linkar: main.o gestor.o atendente.o
	g++ -o meuPrograma main.o gestor.o atendente.o
	
rodar:
	./meuPrograma
	
limpar:
	rm -f meuPrograma *.o
