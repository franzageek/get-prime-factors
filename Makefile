primefact: main.c
	gcc -lprimes main.c -o primefact.out -O2

debug: main.c
	gcc -lprimes main.c -o primefact.out -ggdb -g -Wall -Werror -Wextra -pedantic -Os
