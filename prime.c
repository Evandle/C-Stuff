#include <stdio.h>
#include <math.h>

int main(void){
    int n = -1;

    // input and filter
    
    while (n < 0){
        printf("Give me a positive number: ");
        scanf("%d",&n);
    }
    printf("The Prime numbers of your numbers are.\n");
    for (int i = 1; i < n + 1; i++){
        if (i % 2 != 0 || i == 2){
            if (i % i - 1 != 0 && i % i + 1 != 0) {
                if (i != 1){
                    if (i % 3 != 0 || i == 3){
                        if (i % 5 != 0 || i == 5){
                            printf("%d, ", i);
                        }
                    }
                }
            }
        }
    }

    return 0;

}