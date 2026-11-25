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
#include <string.h>
#include <ctype.h>
/******************************************************************************
* Macros and Constants
******************************************************************************/
#define MAXWORDS 100
#define MAXLEN 30
/******************************************************************************
* Typedefs and Structures
******************************************************************************/

/******************************************************************************
* Global Variables
******************************************************************************/

/******************************************************************************
* Function Prototypes
******************************************************************************/
void addWord(char s[]);
/******************************************************************************
* Main Function
******************************************************************************/
struct Word {
    char word[MAXLEN];
    int count;
};
struct Word list[MAXWORDS];
int total = 0;
int main()
{
    char word[MAXLEN];
    int c;
    int i = 0;

    printf("Enter text (Ctrl+Z then Enter to stop):\n");
    while ((c = getchar()) != EOF) {

        if (isalpha(c)) {

            if (i < MAXLEN - 1)
                word[i++] = tolower(c);
        }
        else {

            if (i > 0) {
                word[i] = '\0';
                addWord(word);
                i = 0;
            }
        }
    }
    if (i > 0) {
        word[i] = '\0';
        addWord(word);
    }
    for (int i = 0; i < total - 1; i++) {

        for (int j = 0; j < total - i - 1; j++) {

            if (list[j].count < list[j + 1].count) {

                struct Word temp;

                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    printf("\nFrequency\tWord\n");
    printf("-------------------------\n");

    for (int i = 0; i < total; i++) {
        printf("%d\t\t%s\n",
               list[i].count,
               list[i].word);
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
void addWord(char s[])
{
    for (int i = 0; i < total; i++) {

        if (strcmp(list[i].word, s) == 0) {
            list[i].count++;
            return;
        }
    }
    strcpy(list[total].word, s);
    list[total].count = 1;
    total++;
}
/******************************************************************************
* End of File
******************************************************************************/
