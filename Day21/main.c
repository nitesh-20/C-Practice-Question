// Date Is Correct or Not
#include <stdio.h>
int main() {
    int day, month, year;

    printf("Enter day, month, and year: ");
    scanf("%d %d %d", &day, &month, &year);

    // Check if year, month, and day are within valid ranges
    if (year >= 1 && month >= 1 && month <= 12) {
        // Check number of days in each month
        int max_days = 31;

        // Adjust max days for months with 30 days
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            max_days = 30;
        } else if (month == 2) {
            // Check for leap year in February
            if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)) {
                max_days = 29;
            } else {
                max_days = 28;
            }
        }

        // Validate the day based on max days of the month
        if (day >= 1 && day <= max_days) {
            printf("The date %d/%d/%d is valid.\n", day, month, year);
        } else {
            printf("The date %d/%d/%d is invalid.\n", day, month, year);
        }
    } else {
        printf("The date %d/%d/%d is invalid.\n", day, month, year);
    }

    return 0;
}
