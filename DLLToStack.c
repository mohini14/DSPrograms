#include<stdio.h>
#include<stdlib.h>

struct DoubleLinkedList
{
	int data;
	struct DoubleLinkedList* next;
	struct DoubleLinkedList* prev;
};

struct DoubleLinkedList* root = NULL;

void addToLinkedList(int item)
{
	if(root == NULL)
	{
		root = (struct DoubleLinkedList* ) malloc(sizeof(struct DoubleLinkedList));
		root->data = item;
		root->next = NULL;
		root->prev = NULL;
	}
	else
	{
		struct DoubleLinkedList* tempNode = root;
		struct DoubleLinkedList* prevNode;
		while(tempNode != NULL)
		{
			prevNode = tempNode;

			tempNode = tempNode->next;
		}

		tempNode = (struct DoubleLinkedList* ) malloc(sizeof(struct DoubleLinkedList));

		tempNode->data = item;

		tempNode->prev = prevNode;
		prevNode->next = tempNode;

		tempNode->next = NULL;
	}
}

void removeFromLinkedList()
{

}

void printDLL()
{
	struct DoubleLinkedList* tempNode = root;
	while(tempNode != NULL)
	{
		printf("%d\n", tempNode->data);
		tempNode = tempNode->next;
	}
}

 int main(int argc, char const *argv[])
{
	addToLinkedList(5);
	addToLinkedList(20);
	addToLinkedList(6);
	printDLL();

	return 0;
}