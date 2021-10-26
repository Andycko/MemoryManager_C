all: main clean-o

main: main.o mymemory.o
	gcc -o main main.o mymemory.o

main.o: main.c
	gcc -c main.c

mymemory.o: mymemory.c
	gcc -c mymemory.c

clean-o:
	rm -f *.o
	
clean:
	rm -f main
	rm -f mymemory
	rm -f *.o