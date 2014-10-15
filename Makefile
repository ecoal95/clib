build/lib.o: src/lib.h src/lib.c
	gcc -Wall -o build/lib.o -c src/lib.c
clean:
	rm -r build/*
