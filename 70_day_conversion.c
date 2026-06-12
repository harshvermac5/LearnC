#include <stdio.h>
#include <stdbool.h>

/* Days-per-month table: index 0 = non-leap, 1 = leap.
 * Index 0 in each row is unused (keeps month numbers 1..12). */
static const int day_tab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* Return true if year is a leap year (Gregorian rules). */
/* A year is leap year if it is divisible by 4, except for year divisible by 100, unless they are also divisible by 400 */
static inline bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/* Convert (year, month, day) to day-of-year (1..366).
 * Returns -1 on invalid month/day. */
int day_of_year(int year, int month, int day) {
    if (month < 1 || month > 12) return -1;
    bool leap = is_leap_year(year);
    if (day < 1 || day > day_tab[leap ? 1 : 0][month]) return -1;

    int doy = 0;
    for (int m = 1; m < month; ++m) {
        doy += day_tab[leap ? 1 : 0][m];
    }
    doy += day;
    return doy;
}

/* Convert (year, yearday) to (month, day) via output pointers.
 * yearday is 1-based. Returns 0 on success, -1 on invalid input. */
int month_day(int year, int yearday, int *pmonth, int *pday) {
    if (pmonth == NULL || pday == NULL) return -1;
    bool leap = is_leap_year(year);
    int max_day = leap ? 366 : 365;
    if (yearday < 1 || yearday > max_day) return -1;

    int m = 1;
    while (yearday > day_tab[leap ? 1 : 0][m]) {
        yearday -= day_tab[leap ? 1 : 0][m];
        ++m;
    }
    *pmonth = m;
    *pday = yearday;
    return 0;
}

int main(void) {
    int y = 2024;
    int m = 3, d = 1;

    int doy = day_of_year(y, m, d);
    if (doy < 0) {
        fprintf(stderr, "Invalid date %d-%02d-%02d\n", y, m, d);
        return 1;
    }
    printf("%d-%02d-%02d is day %d of the year\n", y, m, d, doy);

    int month, day;
    if (month_day(y, doy, &month, &day) != 0) {
        fprintf(stderr, "Invalid yearday %d for year %d\n", doy, y);
        return 1;
    }
    printf("Day %d of %d is %02d-%02d\n", doy, y, month, day);

    printf("Invalid month test: %d\n", day_of_year(2021, 13, 1)); /* -1 */
    printf("Invalid yearday test: %d\n", month_day(2021, 366, &month, &day)); /* -1 on non-leap */

    return 0;
}

