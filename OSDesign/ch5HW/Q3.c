#include <stdio.h>
#include <sys/types.h>

int max_count = 100000;

void modBychild(void);      //function to modify the value of x by child        
void modByparent(void);        //function to modify the value of x by child      


void main(void)
{
   
    int rc = fork();
    if(rc < 0) 
    {
        fprintf(stderr, "fork failed\n");
        //exit(1);
    } 
    else if (rc == 0)
        modBychild();
    else
        modByparent();
}

void modBychild(void)
{
    printf(" hello\n");
}

void modByparent(void)
{
    //parent has to print after child, so it needs to wait
    int i = 0;

   //change max_count if delay is not enough
    for(i = 0; i < max_count; i++);
    {
        printf("goodbye\n");
    }
}

/* 
This is not a entirely reliable solution as the delay caused by the for loop depends on the processor speed. 
*/
