all: main mymemory clean-o run

main: main.o
	gcc -o main main.o

main.o: main.c
	gcc -c main.c

mymemory: mymemory.o
	gcc -o mymemory mymemory.o

mymemory.o: mymemory.c
	gcc -c mymemory.c

clean-o:
	rm -f *.o
	
clean:
	rm -f main
	rm -f mymemory
	rm -f *.o

run:
	./mymemory