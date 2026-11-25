
/******************************************************************************
* File Name    : KR_Q6.5.c
* Description  : Delete a name using undef
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
void undef(char name[]);
/******************************************************************************
* Main Function
******************************************************************************/
int main()
{
    install("MAX", "100");
    install("SIZE", "50");
    install("COUNT", "25");
    printf("Before deleting:\n");
    for (int i = 0; i < count; i++) {
        printf("%s = %s\n", table[i].name, table[i].def);
    }
    undef("SIZE");
    printf("\nAfter deleting SIZE:\n");
    for (int i = 0; i < count; i++) {
        printf("%s = %s\n", table[i].name, table[i].def);
    }
    return 0;
}
/******************************************************************************
* Function Definitions
******************************************************************************/
int lookup(char name[])
{
    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}
void install(char name[], char def[])
{
    int pos = lookup(name);
    if (pos != -1) {
        strcpy(table[pos].def, def);
        return;
    }
    if (count >= MAX) {
        return;
    }
    strcpy(table[count].name, name);
    strcpy(table[count].def, def);
    count++;
}
void undef(char name[])
{
    int pos = lookup(name);
    if (pos == -1) {
        printf("Name not found: %s\n", name);
        return;
    }
    for (int i = pos; i < count - 1; i++) {
        table[i] = table[i + 1];
    }
    count--;
}
/******************************************************************************
* End of File
******************************************************************************/