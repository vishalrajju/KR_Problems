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

int main(void)
{
    int result, month, day;
    result = day_of_year(2029, 5, 30);
    printf("Day of year = %d\n", result);
    month_day(2024, 150, &month, &day);
    printf("Month = %d\n", month);
    printf("Day = %d\n", day);
    return 0;
}

/******************************************************************************
* Function Definitions
******************************************************************************/
/******************************************************************************
* Name        : FunctionName
* Description : Brief description of what the function does
* Arguments   : <type><name> – description
* Returns     : <type> – description
******************************************************************************/
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
int day_of_year(int year, int month, int day)
{
    int i, leap;
    char *p;

    leap = (year % 4 == 0 && year % 100 != 0)
           || year % 400 == 0;
    if (month < 1 || month > 12)
        return -1;

    p = *(daytab + leap) + 1;

    if (day < 1 || day > *(p + month - 1))
        return -1;

    for (i = 1; i < month; i++)
        day += *p++;

    return day;
}
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap;
    char *p;

    leap = (year % 4 == 0 && year % 100 != 0)
           || year % 400 == 0;

    if (yearday < 1 || yearday > (leap ? 366 : 365)) {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    p = *(daytab + leap) + 1;

    for (*pmonth = 1; yearday > *p;
         (*pmonth)++)
        yearday -= *p++;
    *pday = yearday;
}

/******************************************************************************
* End of File
******************************************************************************/
