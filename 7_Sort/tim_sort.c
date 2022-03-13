#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>

const int RUN = 5;

int min(int a, int b)
{
	if (a <= b)
		return a;
	else
		return b;
}

void timSort(int *arr, int n)
{
	for (int i = 0; i < n; i += RUN)
		insertionSort(arr, i, min(i + RUN + 1, n - 1));
	for (int size = RUN ; size < n; size *= 2)
	{
		for (int left = 0; left < n; left += 2*size)
		{
			int mid = left + size - 1;
			int right = min(left + 2 * size - 1, n - 1);
			if (mid < right)
				merge(arr, left, mid, right);
		}
	}
}

int main()
{
	int arr[10] = {40, 30, 100, 60, 80, 70, 90, 10, 20, 50};
	int i = 0;

	printf("before\n");
	for (;i < 10 ; i++)
		printf("%d ", arr[i]);
	printf("\n\n");

	timSort(arr, 10);
	printf("after\n");
	for (i = 0;i < 10 ; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
}