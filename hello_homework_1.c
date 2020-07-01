# include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("hello, world\n"); //to say hello,world

    string name = get_string("What is your name?\n");

    printf("hello, %s\n", name); // to say hello to the users
}