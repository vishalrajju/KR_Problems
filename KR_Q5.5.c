/******************************************************************************
* File Name    : KR_Q5.4.c
* Description  : 
* Tool-Chain   : GCC
*
* Modification History:
* Created by   : VISHAL RAJJU R   V1.0    18/11/2026
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
void my_strncpy(char *s, char *t, int n);
void my_strncat(char *s, char *t, int n);
int my_strncmp(char *s, char *t, int n);
/******************************************************************************
* Main Function
******************************************************************************/
int main()
{
    char s[100];
    char t[100];
    int n;
    int result;
    printf("Enter fs: ");
    fgets(s, sizeof(s), stdin);
    printf("Enter ss: ");
    fgets(t, sizeof(t), stdin);
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '\n')
        {
            s[i] = '\0';
            break;
        }
        i++;
    }
    i = 0;
    while (t[i] != '\0')
    {
        if (t[i] == '\n')
        {
            t[i] = '\0';
            break;
        }
        i++;
    }

    printf("Enter n: ");
    scanf("%d", &n);
    my_strncpy(s, t, n);
    printf("\nAfter strncpy: %s\n", s);
    my_strncat(s, t, n);
    printf("After strncat: %s\n", s);
    result = my_strncmp(s, t, n);
    if (result == 0)
        printf("Strings are equal for first %d characters\n", n);
    else if (result > 0)
        printf("First string is greater\n");
    else
        printf("Second string is greater\n");
     return 0;
}

/******************************************************************************
* Function Definitions
******************************************************************************/
/******************************************************************************
* Name        : my_strncpy(),my_strncat()
* Description : Brief description of what the function does
* Arguments   : <type><name> – description
* Returns     : <type> – description
******************************************************************************/
void my_strncpy(char *s, char *t, int n)
{
    while (n > 0 && *t != '\0')
    {
        *s = *t;
        s++;
        t++;
        n--;
    }
    while (n > 0)
    {
        *s = '\0';
        s++;
        n--;
    }
}
void my_strncat(char *s, char *t, int n)
{
    while (*s != '\0')
    {
        s++;
    }
    while (n > 0 && *t != '\0')
    {
        *s = *t;
        s++;
        t++;
        n--;
    }

    *s = '\0';
}
int my_strncmp(char *s, char *t, int n)
{
    while (n > 0 && *s == *t && *s != '\0')
    {
        s++;
        t++;
        n--;
    }

    if (n == 0)
        return 0;

    return *s - *t;
}
/******************************************************************************
* End of File
******************************************************************************/
