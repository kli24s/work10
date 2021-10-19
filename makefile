all: work10p2.o populationlinkedlist.o
	gcc -o work10p2m work10p2.o populationlinkedlist.o

work10p2.o: work10p2.c populationlinkedlist.h
	gcc -c work10p2.c

populationlinkedlist.o: populationlinkedlist.c populationlinkedlist.h
	gcc -c populationlinkedlist.c

run:
	./work10p2m

clean:
	rm *.o
	rm work10p2m
