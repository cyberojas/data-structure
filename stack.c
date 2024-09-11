#include<stdio.h>
#include<conio.h>

int stack_size = 5;
int stack[5];  // Array to hold the stack elements
int top = -1;  // Initial value of top indicating an empty stack

void printstack();
void push(int data);
void pop();
int peek();
void isempty();
void isfull();

int main()
{
	isempty();
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	pop();
	printstack();
	int x= peek();
	isfull();
	printf("Top Element is = %0d\n",x);
	isempty();
	return 0;
}

	void push(int data)
	{
		if(top>=stack_size-1) // 
		{
			printf("OverFlow\n");
		}
		else
		{
			top++;
			stack[top]=data;
			printf("%0d is Pushed in Stack\n", data);
		}
	}
	
	void printstack()
	{
		if(top==-1)
		{
			printf("UnderFlow\n");
		}
		else
		{
			printf("Stack Elements Are :\n");
			for(int i=top; i >=0 ; i--)
			{
				printf("%0d\n",stack[i]);
			}
			printf("\n");
		}
	}
	
	void pop()
	{
		if(top==-1)
		{
			printf("UnderFlow\n");
		}
		else
		{
			int x= stack[top];
			top--;
			printf("%0d is Pop\n", x);
		}
	}
	
	int peek()
	{
		if(top==-1)
		{
			printf("Stack is Emmpty\n");
			return -1;
		}
		else
		{
			return stack[top];
		}
	}

void isfull()
{
	if(top>=stack_size-1)
	{
		printf("Stack is Full\n");
	}
	else
	{
		printf("Stack is Not full\n");
	}
}

void isempty()
{
	if(top==-1)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		printf("Stack is Not Empty\n");
	}
}
