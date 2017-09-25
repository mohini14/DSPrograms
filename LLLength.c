#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* root = NULL;
struct Node* BHeadPointer = NULL;

void addInA(int item)
{
	struct Node* tempNode;
	struct Node* newNode;

	if(root == NULL)
	{
		root = (struct Node* ) malloc (sizeof(struct Node));
		root->data = item;
		root->next = NULL;
	}
	else
	{
 		tempNode = root;
 		while(tempNode->next != NULL)
 			tempNode = tempNode->next;

 		newNode = (struct Node* ) malloc (sizeof(struct Node));
 		newNode->data = item;
 	 	tempNode->next = newNode;
 	 	newNode->next = NULL;
 	 }
}

void addInB(int item)
{
	struct Node* tempNode;
	struct Node* newNode;

	if(BHeadPointer == NULL)
	{
		BHeadPointer = (struct Node* ) malloc (sizeof(struct Node));
		BHeadPointer->data = item;
		BHeadPointer->next = NULL;
	}
	else
	{
 		tempNode = BHeadPointer;
 		while(tempNode->next != NULL)
 			tempNode = tempNode->next;

 		newNode = (struct Node* ) malloc (sizeof(struct Node));
 		newNode->data = item;
 	 	tempNode->next = newNode;
 	 	newNode->next = NULL;
 	 }
}

int getLengthRecursively(struct Node* root, int count)
{
	if(root == NULL)
		return count;
	// count = count + 1;
	return getLengthRecursively(root->next, count + 1);
}

void print1LL()
{
	struct Node* tempNode = root;

	printf("----------- printing 1 LL -----------\n");
	while(tempNode != NULL)
	{
		printf("%d\n", tempNode->data );
		tempNode = tempNode->next;
	}


}
 
 void print2LL()
 {
 	struct Node* tempNode = BHeadPointer;

	printf("----------- printing 2 LL -----------\n");
	while(tempNode != NULL)
	{
		printf("%d\n", tempNode->data );
		tempNode = tempNode->next;
	}
 }

void printGeneric(struct Node* head)
{
	struct Node* tempNode = head;

	printf("----------- printing generic -----------\n");
	while(tempNode != NULL)
	{
		printf("%d\n", tempNode->data );
		tempNode = tempNode->next;
	}
}

void deleteHeadNode()
{
	struct Node* tempNode = root;
	tempNode = tempNode->next;
	root = tempNode;
}

void swapPointerInLL(int x, int y)
{
	struct Node* XNode = root;
	struct Node* prevXNode = NULL;
	struct Node* YNode = root;
	struct Node* prevYNode = NULL;
	struct Node* tempNode ;

	/// serach x and y
	while( XNode != NULL  && XNode->data != x)
	{
		prevXNode = XNode;
		XNode = XNode->next;
	}


	while(YNode != NULL && YNode->data != y)
	{
		prevYNode = YNode;
		YNode = YNode->next;
	}


	if(XNode == NULL)
	{
		printf(" data is not found = %d\n",x );
		return;
	}

	if(YNode == NULL)
	{
		printf(" data is not found = %d\n",y);
		return;
	}

	if(x == y)
	{
		printf("---- nodes are equal---\n");
		return;
	}

 	// case : when no node is head node then swap
	if(prevYNode != NULL && prevXNode !=NULL)
	{
		printf("--- i  am here ----\n");
		tempNode = YNode->next;
		prevXNode->next = YNode;
		YNode->next = XNode->next;
		prevYNode->next = XNode;
		XNode->next = tempNode;
	}

	else
	{
	
	tempNode = YNode->next;
	YNode->next = XNode->next;
	prevYNode->next = XNode;
	XNode->next = tempNode;
	root = YNode;

	printf("root data = %d x data is =%d and y data is = %d\n",root->data, XNode->data, YNode->data );
	}

}

int getMiddleOfLinkedList()
{
	struct Node* slow = root;
	struct Node* fast = root;

if(root!= NULL)
{
	while(fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

	}

	return slow->data;
}

return 99;
}

int getNthNodeFromLast(int getNthNodeFromLast)
{
	struct Node* mainPointer = root;
	struct Node* refrencePointer = root;

	getNthNodeFromLast--;
	while(getNthNodeFromLast != 0)
	{
		mainPointer = mainPointer->next;
		getNthNodeFromLast--;
	}

	while(mainPointer->next != NULL)
	{
		mainPointer = mainPointer->next;
		refrencePointer = refrencePointer->next;
	}

	return refrencePointer->data;

}

void meargeTwoSortedLL()
{
	struct Node* a =root;
	struct Node* b = BHeadPointer;

	if(a->data > b->data)
	{
		struct Node* temp = a;
		a = b;
		b = temp;
	}


	struct Node* mearged;
	mearged = a;
	while(a != NULL && a->next != NULL && b != NULL)
	{

		if(a->next->data > b->data)
		{
			struct Node* temp = a->next;

			a->next = b;
			b = temp;
		}
		a = a->next;

	}
	if(a->next == NULL && b != NULL)
		a->next = b;

		printGeneric(mearged);


}


void printRevreseRecursively(struct Node* head)
{
	if(head == NULL)
		return;
	printRevreseRecursively(head->next);
	// printf("%d\n",head->data );
}
 int main(int argc, char const *argv[])
{
	addInA(2);
	addInA(4);
	addInA(5);
	// addInA(10);
	// addInA(9);


	addInB(3);
	addInB(6);
	addInB(7);
	// addInB(8);


	// deleteHeadNode();
	// printLL();
	// swapPointerInLL(10, 80);
	// printf("get the middle = %d\n", getMiddleOfLinkedList());

	// printf("get the nth node from last = %d", getNthNodeFromLast(5));

	// meargeTwoSortedLL();

	printRevreseRecursively(root);
	printGeneric(root);
	// printLL();

	// printf("the length of linkedList is = %d\n", getLengthRecursively(root,0) );
	return 0;
}
