#include<stdio.h>
#include<stdbool.h>
int queue[5];
int size_max=5;
int front;
int rear;
void enqueue(int element);
void dequeue();
int getfront();
int getrear();
void viewqueue();
bool isfull();
bool isempty();


int main()
{
	front=-1;
	rear=-1;
		
		
        	enqueue(10);
	    	enqueue(20);
			enqueue(30);
			enqueue(40);
			enqueue(50);
				dequeue();
				enqueue(99);
			int a=getfront();
			int b=getrear();
			printf("\n Front element is = %0d",a);
			printf("\n Rear element is = %0d",b);
			viewqueue();
			return 0;
}

void enqueue(int element)
{
	if(rear==-1 && front==-1)
	{
		rear=0;
		front=0;
		queue[rear]=element;
		printf("\n enqueue %d",queue[rear]);
	}
	else if(rear==size_max-1 && front==0)
	{
		printf("\n queue is full");
	}
	else if(rear==size_max-1 && front!=0)
	{
		rear=0;
		queue[rear]=element;
		printf("\n enqueue %d",queue[rear]);
	}
	else
	{
		rear=rear+1;
		queue[rear]=element;
		printf("\n enqueue %d",queue[rear]);
	}

}

void dequeue()
{
	if(front==-1)
	{
		printf("\n queue is empty..");
	}
	else
	{
		printf("\n dequeue %d",queue[front]);
		queue[front]=0;
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else if(front==size_max-1)
		{
			front=0;
		}
		else
		{
			front=front+1;
		}
	}
}

int getfront()
{
	int x=queue[front];
	return x;
}

int getrear()
{
	int y=queue[rear];
	return y;
}

void viewqueue()
{

 if (rear >= front) {
 	
 	printf("\n Queue Elements are :");
            for (int i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        } else {
            
            for (int i = front; i < size_max; i++) {
                printf("%d ", queue[i]);
            }
            
            for (int i = 0; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
    }
