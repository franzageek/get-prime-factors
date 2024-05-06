primefact: *.c
	gcc *.c -o primefact.out

debug: *.c
	gcc -g *.c -o primefact.out
