#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int low, int mid, int high)
{
	int i;
	int j;
	int k;
	int length1 = mid - low + 1;
	int length2 = high - mid;

	int temp1[length1];
	int temp2[length2];

	// copy items in temp arrays
	for(i = 0; i < length1; i++)
	{
		temp1[i] = arr[low + i];
	}
	for(j = 0; j < length1; j++)
	{
		temp2[j] = arr[mid + low + j];
	}

	i = 0;
	j = 0;
	k = low;
	while(i < length1 && j < length2)
	{
		if(temp1[i] < temp2[j])
		{
			arr[k] = temp1[i];
			i++;
		}
		else
		{
			arr[k] = temp2[j];
			j++;
		}

		k++;
	}

	while(i < length1)
	{
		arr[k] = temp1[i];
		i++;
		k++;
	}

	while(j < length2)
	{
		arr[k] = temp2[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int low, int high)
{
	int mid;
	if(low < high)
	{
		mid = (high + low)/ 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1,high);
		merge(arr, low, mid, high);
	}
}

void printArray(int arr[], int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("%d\n",arr[i] );
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {2,1,4,3};

	mergeSort(arr,0,3);
	printArray(arr, 4);
	return 0;
}