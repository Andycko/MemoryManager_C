#include <stdio.h>
#include <string.h>
#include "mymemory.h"

int main(void) {
	printf ( "shell> start\n");

	initialize();

	char * ptr1 = (char *) mymalloc ( 11 );
	strcpy(ptr1, "this test1");
	printf( "shell> content of allocated memory: %s\n", ptr1 );

	char * ptr2 = (char *) mymalloc ( 57 );
	strcpy(ptr2, "This test is the number that comes after 1 and before 3.");
	printf( "shell> content of allocated memory: %s\n", ptr2 );

	char * ptr3 = (char *) mymalloc ( 11 );
	strcpy(ptr3, "this test3");
	printf( "shell> content of allocated memory: %s\n", ptr3 );

	char * ptr4 = (char *) mymalloc ( 57 );
	strcpy(ptr4, "This test is the number that comes after 3 and before 5.");
	printf( "shell> content of allocated memory: %s\n", ptr4 );

	printmemory();
	printsegmenttable();

	myfree( ptr1 );

	printmemory();
	printsegmenttable();

	mydefrag();

	printmemory();
	printsegmenttable();

	printf ( "shell> end\n");
	return 0;
}