#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
static void swap(int *a, int *b);
void quickSort(int *arr, int start, int end);
int partition(int *arr, int start, int end);
/*
int main()
{
	int arr[10] = {40, 30, 100, 60, 80, 70, 90, 10, 20, 50};
	int i = 0;

	printf("before\n");
	for (;i < 10 ; i++)
		printf("%d ", arr[i]);
	printf("\n\n");

	quickSort(arr, 0, 9);
	printf("after\n");
	for (i = 0;i < 10 ; i++)
		printf("%d ", arr[i]);
	printf("\n\n");

}
*/
static void swap(int *a, int *b)
{
	int temp;

	if (*a != *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

int partition(int *arr, int start, int end)
{
	int pivot;
	int i;
	int index;
	int ran;

	srand(time(NULL));
	ran = start + rand() % (end - start + 1);
	pivot = arr[ran];
	swap(&(arr[ran]), &(arr[end]));
	printf("\033[0;33m%d %d\033[0m\n", ran, pivot);
	i = start;
	index = start;
	for (; i < end ; i++)
	{
		if (arr[i] <= pivot)
		{
			swap(&(arr[i]), &(arr[index]));
			index++;
		}
	}
	swap(&(arr[index]), &arr[end]);
	return (index);
}

void quickSort(int *arr, int start, int end)
{
	int index;

	if (start < end)
	{
		index = partition(arr, start, end);
		quickSort(arr, start, index - 1);
		quickSort(arr, index + 1, end);
	}
	else
		return;
}