#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


char* twoStackArray;
int firstStackIndex = -1;
int secondArrayIndex = -1;
int totalcapacity = -1;


void createTwoStack(int stackCapacity)
{

	totalcapacity = stackCapacity;
	firstStackIndex = -1;
	secondArrayIndex = stackCapacity ;
	twoStackArray = (char* )malloc(stackCapacity * sizeof(char));
}

void printArray()
{
	int i,j; 
	printf("------------ first Array ------------\n");

	if(firstStackIndex != -1)
	{
		for (i = 0; i <= firstStackIndex; i++)
		{
			printf("\ntest\n");
			printf("%c\n",twoStackArray[i]);
		}
	}

	else
		printf("first satck does not have an element\n");


    printf("------------ second Array ------------ \n");

    if (secondArrayIndex != totalcapacity)
    {
	    for(j = totalcapacity - 1 ; j >= secondArrayIndex; j--)
	    {
	    			printf("%c\n",twoStackArray[j] );

	    }
	}
	else
		printf("second satck does not have an element\n");


}

void pushInFirstStack(char item)
{
	if(firstStackIndex < totalcapacity/2 - 1)
	{
		firstStackIndex++;
		twoStackArray[firstStackIndex] = item;

		printf("----------- now item is pushed as = %c\n", twoStackArray[firstStackIndex] );
	}
	else
		printf("The first array is full\n");
}

void pushInsecondStack(char item)
{
	if(secondArrayIndex >= totalcapacity/2 || secondArrayIndex < totalcapacity)
	{
		secondArrayIndex--;
		twoStackArray[secondArrayIndex] = item;
	}
	else
		printf("The second array is full\n");
}

void popFromFirstStack()
{
	char popedItem;
	
	printf("---------- The firstIndex Test = %d--------\n", firstStackIndex);
	if(firstStackIndex < 0)
		printf("first stack has no item to pop\n");

	else
	{
		popedItem = twoStackArray[firstStackIndex];
		firstStackIndex --;
		printf("--------------- popeed element is = %c -------------------\n",popedItem );
	}
}

void popFromSecondStack()
{
	char popedItem;
	
	printf("The second Test = %d", secondArrayIndex);
	if(secondArrayIndex == totalcapacity - 1)
		printf("second stack has no item to pop\n");

	else
	{
		popedItem = twoStackArray[secondArrayIndex];
		secondArrayIndex ++;
		printf("%c\n",popedItem );
	}
}

 int main(int argc, char const *argv[])
{
	int choice;
	char item;
	createTwoStack(10);
	while(1)
	{
		printf("choose operation \n 1.push1 \n 2.push2 \n 3.pop1 \n 4.pop2\n 5.print array \n 6.exit----------- \n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
			printf("Enter the element to be pushed in stack 1\n");
			item = getchar();
			scanf("%c",&item);

			pushInFirstStack(item);
			break;

			case 2:
			printf("Enter the element to be pushed in stack 2\n");
			item = getchar();
			scanf("%c",&item);
			pushInsecondStack(item);
			break;

			case 3:
			popFromFirstStack();
			break;

			case 4: 
			popFromSecondStack();
			break;

			case 6:
			exit(0);

			case 5:
			printArray();
			break;
				
			default:
			printf("------- wrong choice \n -------");

		}

	}	

	return 0;
}
