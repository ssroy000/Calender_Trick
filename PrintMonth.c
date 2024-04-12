#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

//Check leap year
int getNumberOfDays(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } 
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } 
	else {
        return 31;
    }
}

void printCalendar(int month, int year) {
    printf("   ----- %d/%d -----\n", month, year);
    printf("   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int day = 1;
    int totalDays = getNumberOfDays(month, year);

    // Find the day of the week for the first day of the month
    struct tm timeStruct = {0, 0, 0, 1, month - 1, year - 1900};
    mktime(&timeStruct);
    int startDayOfWeek = timeStruct.tm_wday;

    // Print leading spaces
    for (int i = 0; i < startDayOfWeek; i++) {
        printf("     ");
    }

    // Print the days of the month
    while (day <= totalDays) {
        printf("%5d", day);
        if ((startDayOfWeek + day) % 7 == 0) {
            printf("\n");
        }
        day++;
    }

    // Print a new line if necessary
    if ((startDayOfWeek + totalDays) % 7 != 0) {
        printf("\n");
    }
}

int main() {
    int month, year;

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    printCalendar(month, year);

    return 0;
}
