all: data3 data6

clean:
	rm -f *.o data3 data6 d3 d6

data3: createdata3.o
	gcc -Wall -ansi -pedantic createdata3.o -o d3

createdata3.o: createdata3.c
	gcc -c -Wall -ansi -pedantic createdata3.c

data6: createdata6.o
	gcc -Wall -ansi -pedantic createdata6.o -o d6

createdata6.o: createdata6.c
	gcc -c -Wall -ansi -pedantic createdata6.c

data9: createdata9.o
	gcc -Wall 0ansi -pedantic createdata9.o -o d9
createdata9.o: createdata9.c
	gcc -c -Wall -ansi -pedantic createdata9.c