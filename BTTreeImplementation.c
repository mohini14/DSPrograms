#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* lchild;
	struct Node* rchild;
};

struct QueueNode
{
	int data;
	int rear;
	int front;
	int* array;
	int capacity;
	int size;

};

struct Node* root = NULL;
struct QueueNode* queueNode = NULL;

struct Node* insert(struct Node* root, int data)
{
	if(root == NULL)
	{
		root = (struct Node* )malloc(sizeof(struct Node));
		root->lchild = NULL;
		root->rchild = NULL;
		root->data = data;
		return root;
	}
	if(root->lchild == NULL)
		root->lchild = insert(root->lchild, data);
	else
		root->rchild = insert(root->rchild, data);

	return root;
}
void createQueue(int capacity)
{
	queueNode = (struct QueueNode* )malloc(sizeof(struct QueueNode));
	queueNode->rear = -1;
	queueNode->front = -1;
	queueNode->capacity = capacity;
	queueNode->size = 0;
	queueNode->array = (int* )malloc(capacity * sizeof(int));
}

void enqueue(int data)
{
	if(!(queueNode->rear == queueNode->capacity - 1))
	{
	// first insertion
		if(queueNode->rear == -1 && queueNode->front == -1)
			{
				queueNode->rear++;
				queueNode->front++;
			}
		else
			queueNode->rear = (queueNode->rear + 1)%queueNode->capacity;

		queueNode->array[queueNode->rear] = data;
		queueNode->size++;
	}
	else
		printf("Queue is full\n");
}

int deque()
{
	int item;
	if(queueNode->front == -1 || queueNode->rear < queueNode->front)
	{
		printf("the queue is empty\n");
		return -11;
	}
	else
	{
		item = queueNode->array[queueNode->front];
		queueNode->size--;
		queueNode->front = (queueNode->front + 1)%queueNode->capacity;
	}
	return item;
}
void printTree(struct Node* root)
{
	if(root != NULL)
	{
		printf("%d\n", root->data);
		printTree(root->lchild);
		printTree(root->rchild);
	}
}

void printQueue()
{
	if(queueNode->size == 0)
		printf("No elements to print in Queue\n");
	else
	{
		for(int i = queueNode->front; i <= queueNode->rear; i++)
			printf("%d\n", queueNode->array[i]);
	}

}

void breathOrderTraversal()
{

}

int main(int argc, char const *argv[])
{
	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 4);

	
	
	printTree(root);
	printf("--------Queue thing------------\n");
	createQueue(5);
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	
	
	printf("the deque element 1.%d\n 2.%d\n 3.%d\n ",deque(),deque(),deque() );
	
	printQueue();


	
	return 0;
}

