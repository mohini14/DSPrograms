#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode
{
	int data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
};

struct Queue
{
	struct Node* rear;
	struct Node* front;
};

struct Node
{
	struct Node* next;
	struct TreeNode* data;
};


struct TreeNode* root = NULL;
struct Queue* queue = NULL;
struct Node* node = NULL;
void createQueue()
{
	queue = (struct Queue* )malloc(sizeof(struct Queue));
	queue->front = NULL;
	queue->rear = NULL;
}

void printQueue()
{
	printf("---- printing queue\n");
	struct Node* temp = queue->front;
	
	while(temp != NULL)
	{
		printf("data = %d\n", temp->data->data);
		temp = temp->next;
	}
}

void enqueue(struct TreeNode* data)
{
	struct Node* newNode = (struct Node* )malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	// first element
	if(queue->front == NULL )
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

struct TreeNode* dequeue()
{
	struct TreeNode* item;
	if(queue->front == NULL)
	{
		printf("No items to dequeue\n");
		return NULL;
	}
	else
	{
		item = queue->front->data;
		queue->front = queue->front->next;
		if(queue->rear == NULL)
			queue->front = NULL;
	}
	return item;
}



bool QueueIsEmpty()
{
	if(queue->front == NULL)
		return true;
	return false;
}

struct TreeNode* insert(struct TreeNode* root, int data)
{
	if(root == NULL)
	{
		root = (struct TreeNode* )malloc(sizeof(struct TreeNode));
		root->lchild = NULL;
		root->rchild = NULL;
		root->data = data;
		return root;
	}
	if(root->data > data)
		root->lchild = insert(root->lchild, data);
	else
		root->rchild = insert(root->rchild, data);

	return root;
}

void printTree(struct TreeNode* root)
{
	if(root != NULL)
	{
		printf("%d\n", root->data);
		printTree(root->lchild);
		printTree(root->rchild);
	}
}



void breathOrderTraversal()
{
	struct TreeNode* tempNode; 
	if(root != NULL)
	{
		createQueue();
		enqueue(root);
		enqueue(NULL);
	}
	while(!QueueIsEmpty())
	{
		
		tempNode = dequeue();

		if(tempNode == NULL)
		{
			printf("\n");

			enqueue(NULL);
		}
		else
		{
		if(tempNode->lchild == NULL && tempNode->rchild == NULL)
			break;
		else
		{
		if(tempNode->lchild != NULL)
			enqueue(tempNode->lchild);
		if(tempNode->rchild != NULL)
			enqueue(tempNode->rchild);


		printf("the data is = %d\n", tempNode->data);
	}}
	}

}

int main(int argc, char const *argv[])
{
	root = insert(root, 1);
	root = insert(root, 0);
	root = insert(root, 2);
	root = insert(root, 4);
	root = insert(root, 5);
	root = insert(root, 6);



	
	
	printTree(root);

	printf("the level wise traversal is------------\n");
	breathOrderTraversal();
	
	return 0;
}

