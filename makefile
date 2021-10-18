all: work10.o
	gcc -o work10m work10.o

work09.o: work10.c
	gcc -c work10.c

run:
	./work10m

clean:
	rm *.o
	rm program
