#include<stdio.h>
#define MAX 32

int stack[MAX];
int top=-1;

void push(int data)
{
    top++;
    stack[top]=data;
}

int pop()
{
    return stack[top--];
}

void decimaltobinary(int num)
{
    while(num > 0)
    {
        push(num % 2);
        num /= 2;
    }
    printf("Binary Equvalent =");
    while(top != -1)
    {
        printf("%d",pop());
    }
    printf("\n");
}

int main()
{
    int x;
    printf("enter number");
    scanf("%d",&x);
    
    if(x == 0)
    {
        printf("0");
    }
    else
    {
        decimaltobinary(x);
    }
    return 0;
}
