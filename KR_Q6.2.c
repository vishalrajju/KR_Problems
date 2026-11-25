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
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
/******************************************************************************
* Macros and Constants
******************************************************************************/
#define MAXWORDS 5000
#define MAXLEN 100
/******************************************************************************
* Typedefs and Structures
******************************************************************************/

/******************************************************************************
* Global Variables
******************************************************************************/

/******************************************************************************
* Function Prototypes
******************************************************************************/
int compare(const void *a, const void *b);
void readwords(void);
void skipquote(int quote);
/******************************************************************************
* Main Function
******************************************************************************/
char words[MAXWORDS][MAXLEN];
int count = 0;
int main(int argc, char *argv[])
{
    int n = 6;
    int i, j, unique = 0;
    if (argc > 2)
    {
        printf("Usage: ./program [number]\n");
        return 1;
    }

    if (argc == 2)
        n = atoi(argv[1]);

    if (n <= 0 || n >= MAXLEN)
    {
        printf("Invalid number\n");
        return 1;
    }

    readwords();
    qsort(words, count, sizeof(words[0]), compare);
    for (i = 0; i < count; i++)
    {
        if (i == 0 || strcmp(words[i], words[i - 1]) != 0)
        {
            strcpy(words[unique++], words[i]);
        }
    }
    for (i = 0; i < unique; )
    {
        if (strlen(words[i]) < n)
        {
            i++;
            continue;
        }

        j = i + 1;
        while (j < unique &&
               strlen(words[j]) >= n &&
               strncmp(words[i], words[j], n) == 0)
        {
            j++;
        }
        if (j - i > 1)
        {
            for (int k = i; k < j; k++)
                printf("%s ", words[k]);

            printf("\n");
        }
        i = j;
    }
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

int compare(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}
void skipquote(int quote)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\\')
            getchar();
        else if (c == quote)
            break;
    }
}
void readwords(void)
{
    int c, d, i;

    while ((c = getchar()) != EOF)
    {
        if (c == '"' || c == '\'')
        {
            skipquote(c);
        }
        else if (c == '/')
        {
            d = getchar();

            if (d == '/')
            {
                while ((c = getchar()) != EOF && c != '\n')
                    ;
            }
            else if (d == '*')
            {
                int prev = 0;

                while ((c = getchar()) != EOF)
                {
                    if (prev == '*' && c == '/')
                        break;

                    prev = c;
                }
            }
            else if (d != EOF)
            {
                ungetc(d, stdin);
            }
        }
        else if (isalpha(c) || c == '_')
        {
            char word[MAXLEN];
            i = 0;

            do
            {
                if (i < MAXLEN - 1)
                    word[i++] = c;

                c = getchar();

            } while (isalnum(c) || c == '_');

            word[i] = '\0';

            if (c != EOF)
                ungetc(c, stdin);

            if (count < MAXWORDS)
                strcpy(words[count++], word);
        }
    }
}
/******************************************************************************
* End of File
******************************************************************************/
