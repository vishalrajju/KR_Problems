/******************************************************************************
* File Name    : KR_Q6.3.c
* Description  : 
* Tool-Chain   : GCC
*
* Modification History:
* Created by   : VISHAL RAJJU R   V1.0    20/11/2026
* Description  : V1.0 – Initial version
******************************************************************************/

/******************************************************************************
* Includes
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/******************************************************************************
* Macros and Constants
******************************************************************************/
#define MAXWORDS 100
#define MAXLEN 30
#define MAXLINES 100
/******************************************************************************
* Typedefs and Structures
******************************************************************************/
struct Word {
    char word[MAXLEN];
    int lines[MAXLINES];
    int count;
};
/******************************************************************************
* Global Variables
******************************************************************************/
struct Word list[MAXWORDS];
int total = 0;
/******************************************************************************
* Function Prototypes
******************************************************************************/
int isNoise(char s[]);
void addWord(char s[], int line);
/******************************************************************************
* Main Function
******************************************************************************/
int main()
{
    char word[MAXLEN];
    int c;
    int i = 0;
    int line = 1;

    printf("Enter text (Ctrl+D to stop):\n");

    while ((c = getchar()) != EOF) {

        if (isalpha(c)) {
            if (i < MAXLEN - 1) {
                word[i++] = tolower(c);
            }
        }
        else {
            if (i > 0) {
                word[i] = '\0';
                addWord(word, line);
                i = 0;
            }

            if (c == '\n')
                line++;
        }
    }
    if (i > 0) {
        word[i] = '\0';
        addWord(word, line);
    }
    printf("\nWord\t\tLine Numbers\n");
    printf("--------------------------------\n");

    for (int i = 0; i < total; i++) {
        printf("%-15s", list[i].word);

        for (int j = 0; j < list[i].count; j++) {
            printf("%d ", list[i].lines[j]);
        }

        printf("\n");
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
int isNoise(char s[])
{
    char *noise[] = {
        "the", "and", "is", "a", "an",
        "of", "to", "in", "on", "for"
    };

    int n = 10;

    for (int i = 0; i < n; i++) {
        if (strcmp(s, noise[i]) == 0)
            return 1;
    }

    return 0;
}
void addWord(char s[], int line)
{
    if (isNoise(s))
        return;

    for (int i = 0; i < total; i++) {
        if (strcmp(list[i].word, s) == 0) {

            if (list[i].lines[list[i].count - 1] != line) {
                list[i].lines[list[i].count] = line;
                list[i].count++;
            }

            return;
        }
    }
    strcpy(list[total].word, s);
    list[total].lines[0] = line;
    list[total].count = 1;
    total++;
}
/******************************************************************************
* End of File
******************************************************************************/
