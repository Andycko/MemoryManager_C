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

int main() {
	printf("segmenttable -> %p\n", segmenttable);
	initialize();
	printsegmenttable();
	return 1;
}

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

void * mymalloc ( size_t size )
{
   printf ( "mymalloc> start\n");

   // implement the mymalloc functionality
}

void myfree ( void * ptr )
{
   printf ( "myfree> start\n");

}

void mydefrag ( void ** ptrlist)
{
   printf ( "mydefrag> start\n");

}


// helper functions for management segmentation table
Segment_t * findFree ( Segment_t * list, size_t size )
{
	printf ( "findFree> start\n");
}

void insertAfter ( Segment_t * oldSegment, Segment_t * newSegment )
{
}

Segment_t * findSegment ( Segment_t * list, void * ptr )
{
}

int isPrintable ( int c )
{
   if ( c >= 0x20 && c <= 0x7e ) return c ;

   return 0 ;
}

void printmemory ()
{
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
		printf("		allocated = %s\n", (currSegDesc.allocated) ? "TRUE" : "FALSE");
		printf("		start     = %p\n", currSegDesc.start);
		printf("		size      = %ld\n", currSegDesc.size);
		
		// break the loop if there is no next segment
		if(!currSegDesc.next) break;
		
		// progress to the next segment
		i++;
		currSegDesc = *currSegDesc.next;
	}
	printf("====== END SEGMENT TABLE ======\n");
}

void printsegmentdescriptor ( Segment_t * descriptor )
{
      printf ( "\tallocated = %s\n" , (descriptor->allocated == FALSE ? "FALSE" : "TRUE" ) ) ;
      printf ( "\tstart     = %p\n" , descriptor->start ) ;
      printf ( "\tsize      = %lu\n", descriptor->size  ) ;
}
