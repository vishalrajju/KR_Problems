
/******************************************************************************
* File Name    : KR_Q6.6.c
* Description  : Simple define processor
* Tool-Chain   : GCC
*
* Modification History:
* Created by   : VISHAL RAJJU R   V1.0    20/11/2026
* Description  : Initial version
******************************************************************************/

/******************************************************************************
* Includes
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/******************************************************************************
* Macros
******************************************************************************/
#define MAX 100
#define LEN 30

/******************************************************************************
* Structure
******************************************************************************/
struct Word {
    char name[LEN];
    char def[LEN];
};

/******************************************************************************
* Global Variables
******************************************************************************/
struct Word table[MAX];
int count = 0;

/******************************************************************************
* Function Prototypes
******************************************************************************/
int lookup(char name[]);
void install(char name[], char def[]);
void process(char s[]);

/******************************************************************************
* Main Function
******************************************************************************/
int main()
{
    char line[200];
    printf("Enter input:\n");
    printf("Enter END:\n");
    while (fgets(line, sizeof(line), stdin) != NULL) {
        if (strcmp(line, "END\n") == 0)
            break;
        process(line);
    }
    return 0;
}

/******************************************************************************
* Function Definitions
******************************************************************************/
int lookup(char name[])
{
    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0)
            return i;
    }
    return -1;
}
void install(char name[], char def[])
{
    int pos = lookup(name);
    if (pos == -1) {
        if (count >= MAX)
            return;

        pos = count++;
    }
    strcpy(table[pos].name, name);
    strcpy(table[pos].def, def);
}
void process(char s[])
{
    char name[LEN], def[LEN], word[LEN];
    int i = 0, j = 0, pos;
    if (strncmp(s, "#define", 7) == 0) {
        if (sscanf(s + 7, "%29s %29s", name, def) == 2)
            install(name, def);
        return;
    }
    while (s[i] != '\0') {
        if (isalnum((unsigned char)s[i]) || s[i] == '_') {
            if (j < LEN - 1)
                word[j++] = s[i];
        }
        else {
            if (j > 0) {
                word[j] = '\0';
                pos = lookup(word);
                if (pos != -1)
                    printf("%s", table[pos].def);
                else
                    printf("%s", word);
                j = 0;
            }
            putchar(s[i]);
        }
        i++;
    }
        if (j > 0) {
        word[j] = '\0';
        pos = lookup(word);
        if (pos != -1)
            printf("%s", table[pos].def);
        else
            printf("%s", word);
    }
}

/******************************************************************************
* End of File
******************************************************************************/
