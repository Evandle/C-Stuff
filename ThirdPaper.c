#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void) {
    char word1[100] = "Benedict";
    char temp1[100];]

    // a function that would reverse a string
    for (int i = 0, n = strlen(word1), count = n - 1; i < n; i++) 
    {
        temp1[i] = word1[count];
        count--;
        if (i == 7){
            temp1[i + 1] = '\0';
        }
    }

    //Prints the reversed string
    
    printf("%s", temp1);
    return 0;
}
