#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    time_t t;
    /* Intializes random number generator */
    srand((unsigned) time(&t));

    const int length = atoi(argv[1]);

    for(int i = 0; i < length - 1; ++i) {
        printf("%c", (int)(rand() % (127) + 1));
    }
    fflush(stdout);
}
