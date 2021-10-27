all: shell clean-o

shell: shell.o mymemory.o
	gcc -o shell shell.o mymemory.o

shell.o: shell.c
	gcc -c shell.c

mymemory.o: mymemory.c
	gcc -c mymemory.c

clean-o:
	rm -f *.o
	
clean:
	rm -f shell
	rm -f *.o