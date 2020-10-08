// Chapter 5 Question 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
int main()
{
    pid_t pid;
    int x = 100;    //variable has been initialized
    pid = fork();   //fork has been called. A copy of variable x is given away to the child too.
    if(pid < 0)
    {   //This block will be executed if child is not created.
        printf("Child process creation failed.");
    }
    else if(pid == 0)   /*This block will be executed by the child process, when the child has been created.*/
    {
        printf("You are in child process. The value of x:= %i\n",x);/*This will print the value of the child process variable x as 100*/
        x += 10
        ;   /*This will increment the value of the child process variable x by 10, which will make it 110 for child.*/
        printf("Your child process updated the x value, and now x:= %i\n",x);/*The will print the value of the child process variable x as 110*/
    }   
    else   /*This block will be executed by the parent process, when the child has been created.*/
    {
        printf("You are in parent process. The value of x:= %i\n",x);/*This will print the value of the parent process variable x as 100*/
        x += 20;   /*This will increment the value of the parent process variable x by 20, which will make it 120 for parent. Nothing to think about the child process x value has been updated or not.*/
        printf("Your parent process updated the x value, and now x:= %i\n",x);/*The will print the value of the parent process variable x as 120*/
    }   
}

/*
The child process will also initially have the variable x with the same value of 100. The modifications done by parent process will be 
limited to parent, same for the child.
*/