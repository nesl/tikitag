#include "tikitags.h"
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigfun(int sig)
{
	printf("Quit program\n");
	tiki_close();
	exit(-1);
}


int main()
{
    int numtags=0;

    (void) signal(SIGINT, sigfun);
    
    printf("**Init and Config\n");
    
    tiki_init();
    tiki_config(5000,0); 	
     
    printf("\n**Program**\n\n");
    
    while (1)
    {
    numtags=tiki_seek();
    switch(numtags){
	    case 0:
		    printf("TIMEOUT: No tags found\n");
		    break;
	    case 1:
		    printf("%d tags found on reader %d\n", numtags, tiki_getReaderID());
		    printf("ID 1: %u\n", tiki_getID1());
		    break;
	    case 2:
		    printf("%d tags found on reader %d\n", numtags, tiki_getReaderID());
		    printf("ID 1: %u\n", tiki_getID1());
		    printf("ID 2: %u\n", tiki_getID2());
		    break;
	    default:
		    printf("ERROR: Unknown number of tags found %d\n", numtags);

    }
    }

    
    tiki_close();
    return 0;
    }
