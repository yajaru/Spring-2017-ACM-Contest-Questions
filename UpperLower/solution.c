#define BUF_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

    char buffer[BUF_SIZE];
    size_t contentSize = 1; // includes NULL
    /* Preallocate space.  We could just allocate one char here,
    but that wouldn't be efficient. */
    char *content = malloc(sizeof(char) * BUF_SIZE);
    if(content == NULL)
    {
        perror("Failed to allocate content");
        exit(1);
    }
    content[0] = '\0'; // make null-terminated
    while(fgets(buffer, BUF_SIZE, stdin))
    {
        char *old = content;
        contentSize += strlen(buffer);
        content = realloc(content, contentSize);
        if(content == NULL)
        {
            perror("Failed to reallocate content");
            free(old);
            exit(2);
        }
        strcat(content, buffer);
    }

    if(ferror(stdin))
    {
        free(content);
        perror("Error reading from stdin.");
        exit(3);
    }

    int upper_front = 0, lower_front = 0,
        upper_back = contentSize, lower_back = contentSize;
    while(1) {
        if(!(upper_front < upper_back) && !(lower_front < lower_back)) { // If both index values have crossed, we are done
            break;
        }
        if(upper_front < upper_back) {
            if(isupper(content[upper_front]) && isupper(content[upper_back])) {
                content[upper_front] ^= content[upper_back];
                content[upper_back] ^= content[upper_front];
                content[upper_front] ^= content[upper_back];
                upper_front += 1;
                upper_back -= 1;
            }
            upper_front += !isupper(content[upper_front]) ? 1 : 0;
            upper_back -= !isupper(content[upper_back]) ? 1 : 0;
        }
        if(lower_front < lower_back) {
            if(islower(content[lower_front]) && islower(content[lower_back])) {
                content[lower_front] ^= content[lower_back];
                content[lower_back] ^= content[lower_front];
                content[lower_front] ^= content[lower_back];
                lower_front += 1;
                lower_back -= 1;
            }
            lower_front += !islower(content[lower_front]) ? 1 : 0;
            lower_back -= !islower(content[lower_back]) ? 1 : 0;
        }

    }
    printf("%s", content);
    fflush(stdout);
}
