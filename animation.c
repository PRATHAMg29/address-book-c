#include <stdio.h>
#include <unistd.h>   // usleep

void loading_animation(const char *message)  //function for animation.
{
    printf("%s ", message);  //to print the required message.
    fflush(stdout);  //to clear output buffer.

    for (int i = 1; i <= 100; i++)   //loop upto 100 to show progress.
    {
        printf("\r%s %3d%%", message, i);  //updation on the same line.
        fflush(stdout); 
        usleep(10000);   // 10ms → total ~1 seconds
    }

    printf("\n");
}