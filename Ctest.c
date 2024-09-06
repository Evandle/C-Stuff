#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "student.h"

int main(void) {
    // Initialize the student object
    student student;

    // Read the student's name from the input
    if (fgets(student.name, 100, stdin) != NULL) {
        // Remove the newline character at the end of the string
        student.name[strcspn(student.name, "\n")] = '\0';
        // Print the student's name
        printf("%s is cool", student.name);
    }
    fgets(student.school, sizeof(student.school), stdin);
    student.school[strcspn(student.school, "\n")] = '\0';
    printf(", and he/she is studying at %s.\n", student.school);
    return 0;
}
// added for safe keeping
ssh -p 2220 bandit0@bandit.labs.overthewire.org bandit0
if you wanna learn hacking
pass is bandit0