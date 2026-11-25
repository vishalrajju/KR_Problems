/******************************************************************************
* File Name    : KR_Q4.4.c
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
#define MAX 100
/******************************************************************************
* Typedefs and Structures
******************************************************************************/

/******************************************************************************
* Global Variables
******************************************************************************/

/******************************************************************************
* Function Prototypes
******************************************************************************/
void push(int x);
int pop(void);
void print(void);
void duplicate(void);
void swap(void);
void clear(void);
/******************************************************************************
* Main Function
******************************************************************************/
int stack[MAX];
int top = -1;
int main()
{
    push(10);
    push(20);
    push(30);

    print();

    duplicate();
    print();

    swap();
    print();

    clear();
    print();

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
void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack is full\n");
        return;
    }

    stack[++top] = x;
}
int pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }

    return stack[top--];
}
void print()
{
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Top element = %d\n", stack[top]);
}
void duplicate()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    push(stack[top]);
}
void swap()
{
    int temp;

    if (top < 1)
    {
        printf("Not enough elements to swap\n");
        return;
    }

    temp = stack[top];
    stack[top] = stack[top - 1];
    stack[top - 1] = temp;
}
void clear()
{
    top = -1;
    printf("Stack cleared\n");
}

/******************************************************************************
* End of File
******************************************************************************/