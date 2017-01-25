mon_programme: fonction.o main.o
	gcc -o quarto_game fonction.o main.o -lm
fonction.o: fonction.c
	gcc -c fonction.c -Wall -Wextra
main.o: main.c
	gcc -c main.c -Wall -Wextra
