// Chapter 5 Question 2
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void)
{
    int fd; 
    fd = open("output.txt", O_CREAT|O_TRUNC|O_WRONLY, 0666); // open a file for writing

    // Create a new process by fork
    if(!fork()) 
    {
        // child
        write(fd, "Child is writing\n", 17);        
        _exit(0);
    } 
    else 
    {
        // parent
        wait(NULL); 
        write(fd, "Parent is writing\n", 18);
        close(fd); // close the file
    }
}

/*
Yes, When a fork call happens the fd value in both processes is the same. The Fd value is 
nothing but a reference in both programs for the file description(a type of struct) So Whatever they 
try to do using fd, happens on the same File description. In above code, Parent wait for child to 
complete, so child writes, and then parent writes on the same file. Parent closes 
the descriptor, which means fileDescriptor entry is removed from fileDescription table.
*/