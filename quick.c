#include <stdio.h>
#include <stdlib.h>

void quick(int arr[], int a, int b);
int main()
{
	int arr[] = {3, 1, 7, 2, 8, 4, 6, 2, 5};
	// int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

	int size = sizeof(arr)/sizeof(int);
	printf("before------\n");
	for (int i = 0 ; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
	printf("after---------\n");
	quick(arr, 0, size - 1);
	for (int i = 0 ; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void quick(int arr[], int start, int end)
{
	int l;
	int r;

	l = start;
	r = end;
	if (start >= end)
		return ;
	while(l < r)
	{
		swap(arr + l, arr + r);
		while (arr[l] <= arr[end] && l < end)
			l++;
		while (arr[r] >= arr[end] && r > l)
			r--;
	}
	swap(arr + l, arr + end);
	quick(arr, start, l - 1);
	quick(arr, l + 1, end);
}