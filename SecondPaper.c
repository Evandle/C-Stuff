#include <stdio.h>
#include <string.h>

int main(void) {
    char input[100];
    fgets(input, sizeof(input) - 1, stdin);
    input[strcspn(input, "\n")] = '\0';
    printf("%s", input);
}