#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void) {
   char *argv[3] = {"Command-line", ".", NULL};

   int pid = fork();

   if ( pid == 0 ) {
       exec( "ls", argv );
   }

   /* Put the parent to sleep for 2 seconds--let the child finished executing */
   wait( 2 );

   printf( "Finished executing the parent process\n" " - the child won't get here--you will only see this once\n" );

   return 0;
}

/*
there are so many different variants because there are different needs for calling exec()
*/

