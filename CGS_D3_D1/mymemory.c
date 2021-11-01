/* mymemory.c
 * 
 * provides interface to memory management
 * 
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "mymemory.h"


// our memory
Byte        mymemory [MAXMEM] ;
Segment_t * segmenttable = NULL;

void initialize ()
{
   printf ( "initialize> start\n");
   // set memory to 0
	 for (int i = 0; i < sizeof mymemory / sizeof *mymemory; i++) {
		 mymemory[i] = '\0';
	 }

   // create segment table
   // contains one segment description that declares the whole memory
   // as one free segment
   //
   // create a single segment descriptor
	 Segment_t * segDescriptor = malloc ( sizeof ( Segment_t ) );
   segDescriptor->allocated = FALSE;
	 segDescriptor->start = mymemory;
	 segDescriptor->size = sizeof mymemory;
	 segDescriptor->next = NULL;
	
   // initialise the segment
	 segmenttable = segDescriptor;

   printf ( "initialize> end\n");
}

int isPrintable ( int c )
{
   if ( c >= 0x20 && c <= 0x7e ) return c ;

   return 0 ;
}

void printmemory ()
{
	// a buffer will be used for printing 10 elements per line
	Byte buffer[10];

	// loop through the memory array
	for (int i = 0; i < sizeof mymemory / sizeof *mymemory; i++) {
		
		// when we fill up the buffer
		if(i != 0 & i % 10 == 0) printMemoryLine(i-10, buffer);
		
		// add byte to buffer 
		buffer[i % 10] = mymemory[i];
	}
  // print the last 1-10 bytes remaining in the buffer
  printMemoryLine(sizeof mymemory - sizeof mymemory % 10, buffer);  
}

void printsegmentdescriptor ( Segment_t * descriptor )
{
      printf ( "\tallocated = %s\n" , (descriptor->allocated == FALSE ? "FALSE" : "TRUE" ) ) ;
      printf ( "\tstart     = %p\n" , descriptor->start ) ;
      printf ( "\tsize      = %lu\n", descriptor->size  ) ;
}

void printsegmenttable()
{
	// set the current segment descriptor to the first one in segment table
	Segment_t currSegDesc = *segmenttable;
	int i = 0; 

	// loop while there is next descriptor
	printf("====== BEGIN SEGMENT TABLE ======\n");
	while (1) {
		printf("Segment %d\n", i);
		printsegmentdescriptor(&currSegDesc);
		
		// break the loop if there is no next segment
		if(!currSegDesc.next) break;
		
		// progress to the next segment
		i++;
		currSegDesc = *currSegDesc.next;
	}
	printf("====== END SEGMENT TABLE ======\n");
}

void printMemoryLine(int lineNum, Byte buffer[]) {
  	// print out line number
    printf("[%4d] ", lineNum);
		
    // print out hex
    for(int j = 0; j < 10; j++) {
      printf("%02x ", buffer[j]);
    }

    printf("| ");
    
    // print out chars
    for(int j = 0; j < 10; j++) {
      if(isPrintable(buffer[j]))
        printf("%c", buffer[j]);
      else
        printf(".");
    }
    
    printf("\n");
}