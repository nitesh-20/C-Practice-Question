//Print A Calendar Taking Input From User Using Loop
 #include <stdio.h>

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}

int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

int getStartingDay(int year, int month) {
    int day = 1;
    int totalDays = 0;

    for (int i = 1900; i < year; i++) {
        totalDays += isLeapYear(i) ? 366 : 365;
    }

    for (int i = 1; i < month; i++) {
        totalDays += getDaysInMonth(i, year);
    }

    return (totalDays + day) % 7;
}

void printCalendar(int month, int year) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int daysInMonth = getDaysInMonth(month, year);
    int startingDay = getStartingDay(year, month);

    printf("\n  %s %d\n", months[month - 1], year);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    for (int i = 0; i < startingDay; i++) {
        printf("     ");
    }

    for (int day = 1; day <= daysInMonth; day++) {
        printf("%5d", day);
        if ((startingDay + day) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    int month, year;

    printf("Enter the month (1-12): ");
    scanf("%d", &month);
    printf("Enter the year: ");
    scanf("%d", &year);

    if (month < 1 || month > 12 || year < 1900) {
        printf("Invalid input. Please enter a valid month (1-12) and year (>=1900).\n");
        return 1;
    }

    printCalendar(month, year);

    return 0;
}
