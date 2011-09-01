/*
TASK: friday
LANG: C
ID: chroman1
*/

#include <stdio.h>

#define START_WEEK_DAY 1
#define START_MONTH_DAY 1
#define START_MONTH 1
#define START_YEAR 1900

int is_leap_year(int year)
{
    if (!(year % 100))
        return !(year % 400) ? 1 : 0;
    else
        return !(year % 4) ? 1 : 0;
}

int get_n_month_days(int month, int year)
{
    if (month == 9 || month == 4 || month == 6 || month == 11)
        return 30;
    else if (month == 2)
        return is_leap_year(year) ? 29 : 28;
    else
        return 31;
}

int main(void)
{
    int i, n;
    int curr_week_day = START_WEEK_DAY, curr_month = START_MONTH,
        curr_year = START_YEAR;
    int frequencies[7] = {0, 0, 0, 0, 0, 0, 0};
    FILE *fp;

    fp = fopen("friday.in", "r");
    fscanf(fp, "%d\n", &n);
    fclose(fp);
    while (curr_year < (START_YEAR + n))
        {
            for (i = 1; i <= get_n_month_days(curr_month, curr_year); i++)
                {
                    if (i == 13)
                        frequencies[curr_week_day - 1] += 1;
                    if (curr_week_day == 7)
                        curr_week_day = 1;
                    else
                        curr_week_day += 1;
                }
            if (curr_month == 12)
                {
                    curr_month = 1;
                    curr_year += 1;
                }
            else
                curr_month += 1;
        }
    fp = fopen("friday.out", "w");
    fprintf(fp, "%d %d", frequencies[5], frequencies[6]);
    for (i = 0; i < 5; i++)
        fprintf(fp, " %d", frequencies[i]);
    fprintf(fp, "\n");
    fclose(fp);
    return 0;
}
