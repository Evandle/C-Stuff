#include <stdio.h>

int main(void){
    int num1;
    printf("How many febonachi sequnse? ");
    scanf("%d",&num1);
    for (int i = 0, n = 0, x = 1, z; i < num1; i++){
        z = n;
        n = n + x;
        x = z;
        printf("%d ", n);
    }
    
    return 0;
}