/******************************************************************************
* File Name    : KR_Q1.1.c
* Description  : Experiment by leaving the semicolons and brackets
* Tool-Chain   : GCC
*
* Modification History:
* Created by   : VISHAL RAJJU R   V1.0    17/11/2026
* Description  : V1.0 – Initial version
******************************************************************************/

/******************************************************************************
* Includes
******************************************************************************/
#include <stdio.h>

/******************************************************************************
* Macros and Constants
******************************************************************************/

/******************************************************************************
* Typedefs and Structures
******************************************************************************/

/******************************************************************************
* Global Variables
******************************************************************************/

/******************************************************************************
* Function Prototypes
******************************************************************************/
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
/******************************************************************************
* Main Function
******************************************************************************/
int main()
{
    int result, month, day;
    result = day_of_year(2029, 5, 32);
    printf("Day of year = %d\n", result);
    month_day(2024, 150, &month, &day);
    printf("Month = %d\nDay = %d\n", month, day);
    return 0;
}
/******************************************************************************
* Function Definitions
******************************************************************************/
/******************************************************************************
* Name        : Day_of_year(),Month_day()
* Description : Day_of_year() - date to day number , Month_day() - day number to date
* Arguments   : <type><name> – description
* Returns     : <type> – description
******************************************************************************/
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 30, 31, 30, 31, 31}
};
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (month < 1 || month > 12)
        return -1;

    if (day < 1 || day > daytab[leap][month])
        return -1;

    for (i = 1; i < month; i++)
        day += daytab[leap][i];

    return day;
}
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (yearday < 1 || yearday > (leap ? 366 : 365)) {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}
/******************************************************************************
* End of File
******************************************************************************/
