#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Queue
{
	struct Node* rear;
	struct Node* front;
};

struct Node
{
	struct Node* next;
	int data;
};

struct Queue* queue = NULL;
struct Node* node = NULL;

void createQueue()
{
	queue = (struct Queue* )malloc(sizeof(struct Queue));
	queue->front = NULL;
	queue->rear = NULL;
}

void enqueue(int data)
{
	struct Node* newNode = (struct Node* )malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;

	// first element
	if(queue->front == NULL && queue->rear == NULL)
	{
		queue->front = newNode;
		queue->rear = newNode;
	}
	else
	{
		queue->rear->next = newNode;
		queue->rear = queue->rear->next;
	}
}

int dequeue()
{
	int item;
	if(queue->front == NULL)
	{
		printf("No items to dequeue\n");
	}
	else
	{
		item = queue->front->data;
		queue->front = queue->front->next;
	}
	return item;
}

void printQueue()
{
	struct Node* temp = queue->front;
	
	while(temp != NULL)
	{
		printf("data = %d\n", temp->data);
		temp = temp->next;
	}

}

bool QueueIsEmpty()
{
	if(queue->rear == NULL)
		return true;
	return false;
}
// int main(int argc, char const *argv[])
// {
// 	createQueue();
// 	enqueue(1);
// 	enqueue(2);
// 	enqueue(3);
// 	enqueue(4);
// 	printf("--- print eleemnts -----\n");
// 	printQueue();
// 	printf("dequeued elemet = %d\n", dequeue());
// 	printf("dequeued elemet = %d\n", dequeue());
// 	printf("dequeued elemet = %d\n", dequeue());
// 	printf("dequeued elemet = %d\n", dequeue());
// 	printf("dequeued elemet = %d\n", dequeue());
// 	return 0;
// }