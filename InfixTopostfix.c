#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
struct Stack
{
	int top;
	char* array;
	int capacity;
};

struct Stack* stack;

bool isEmpty()
{
	return stack->top == -1;
}

char pop ()
{
	char poppedItem;
	if(isEmpty())
	{
		printf("Stack is empty");
		return '\0';
	}
	poppedItem =  stack->array[stack->top];
	stack->top-- ;

  printf("poped element is = %c ----- \n", poppedItem);

	return poppedItem;
} 

void push(int item)
{
	stack->top ++;
	stack->array[stack->top] = item;
	printf("pushed element is = %c ----- \n", stack->array[stack->top]);
}

int getLengthOfArray(char array[])
{
	int i = 0;
	while(array[i] != '\0')
	{
		i++;
	}
	printf("----- i = %d---- \n",i );
	return i;
}


bool scannedCharHasHigherPresdence(char scannedChar)
{
	char stackTop = stack->array[stack->top];
	bool resultant;
	switch(scannedChar)
	{
		case '+' :
			if( stackTop == '*' || stackTop == '/' || stackTop == '+' || stackTop == '-' )
				resultant =  false;
			else
				resultant =  true;

			break;

		case '-':
			if( stackTop == '*' || stackTop == '/' || stackTop == '+' || stackTop == '-' )
				resultant =  false;
			else
				resultant =  true;

			break;

		case '*' : 
		if(stackTop == '+' || stackTop == '/' || stackTop == '-' || stackTop == '*')
			resultant =  true;
		else
			resultant =  false;

		break;

		case '/':
		if(stackTop == '+' || stackTop == '/' || stackTop == '-' || stackTop == '*')
			resultant =   true;
		else
			resultant =  false;

		break;

		default:
		printf("invalid choice");
	}

	return resultant;
}

void createStack(int charInExpression)
{
	stack = (struct Stack* )malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->capacity = charInExpression;

	stack->array = (char* )malloc(stack->capacity * sizeof(char));
}

bool isOperand(char scannedCharacter)
{
	if(scannedCharacter == '+' || scannedCharacter == '-' || scannedCharacter == '*' || scannedCharacter == '/')
		return false;
	return true;
}

char* infixToPostFix(char infixArray[])
{
	int i;
	int lengthOfString = getLengthOfArray(infixArray);

	printf("-----length of string is = %d----\n", lengthOfString);
	char* postFixArray = (char* )malloc(lengthOfString * sizeof(char));
	int postFixArrayFilledIndex = -1;
	char popedItem;

	for(i = 0 ; i < lengthOfString && postFixArrayFilledIndex < lengthOfString; i++)
	{
		if(isOperand(infixArray[i])) // if operand add to string
		{
			postFixArrayFilledIndex++;
			postFixArray[postFixArrayFilledIndex] = infixArray[i];
		}
		else // if a operator
		{
			if(isEmpty())
			{
				push(infixArray[i]);
			}

			else if(scannedCharHasHigherPresdence(infixArray[i]))
			{
				// postFixArrayFilledIndex++;
				// postFixArray[postFixArrayFilledIndex] = infixArray[i];
				push(infixArray[i]);
			}
			else // if scanned char has lower precedence
			{
				while(scannedCharHasHigherPresdence(infixArray[i]) == false && isEmpty() == false)
				{
					popedItem = pop();
					postFixArrayFilledIndex++;
					postFixArray[postFixArrayFilledIndex] = popedItem;
					printf("\n -----------the postFixArray index is = %d and the element is = %c ---------------- \n", postFixArrayFilledIndex,postFixArray[postFixArrayFilledIndex]);
				}
				push(infixArray[i]);
			}
		}
		
		printf("\n -----------the postFixArray index is = %d and the element is = %c ---------------- \n", postFixArrayFilledIndex,postFixArray[postFixArrayFilledIndex]);
		
	}
	if(isEmpty() == false)
	{
		popedItem = pop();
		postFixArrayFilledIndex++;
		postFixArray[postFixArrayFilledIndex] = popedItem;
		printf("\n -----------the postFixArray index is = %d and the element is = %c ---------------- \n", postFixArrayFilledIndex,postFixArray[postFixArrayFilledIndex]);

	}

	return postFixArray;
}


void printpostFixArray(char postFixArray[])
{
	int i = 0;
	printf("----------------------------------\n");

	printf("%s\n", postFixArray);
	// while(postFixArray[i] != '\0')
	// {
	// 	printf("%c\n", printpostFixArray[i]);
	// 	i++;
	// }

	printf("----------------------------------\n");

}


 int main(int argc, char const *argv[])
{
	char infixExpressionArray[] = "a+b*c+d";

	createStack(getLengthOfArray(infixExpressionArray));

	char* postFixArray = infixToPostFix(infixExpressionArray);

	printpostFixArray(postFixArray);

	return 0;
}
