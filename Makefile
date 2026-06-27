scanner: src/main.c src/scan.c
	gcc -Iinclude -o scanner -g src/main.c src/scan.c

clean:
	rm -f scanner *.o