#include <stdio.h>

int isleap(int year){
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        return 1;
    } else {
        return 0;
    }
}

int daysinmonth(int year, int month) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isleap(year) ? 29 : 28;
        default:
            return 0;
    }
}

void caladd(int *month, int *day, int *year, int daysToAdd) {
    while (daysToAdd > 0){
        int daysincurrentmonth = daysinmonth(*year, *month);
        if (*day + daysToAdd <= daysincurrentmonth){
            *day += daysToAdd;
            daysToAdd = 0;
        } else {
            daysToAdd -= (daysincurrentmonth - *day + 1);
            *day = 1;
            (*month)++;
            if (*month > 12){
                *month = 1;
                (*year)++;
            }
        }
    }
}

void printDate(int day, int month, int year) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    printf("\n%s %d, %d\n", months[month - 1], day, year);
}

int main() {
    int month, day, year, daysToAdd;

    printf("Enter month: ");
    scanf("%d", &month);
    printf("Enter day: ");
    scanf("%d", &day);
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Days to go forward: ");
    scanf("%d", &daysToAdd);
    
    caladd(&month, &day, &year, daysToAdd);
    printDate(day, month, year);

}