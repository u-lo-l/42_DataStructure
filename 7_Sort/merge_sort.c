#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int start, int mid, int end);
void mergeSort(int *arr, int start, int end);

/*
int main()
{
	int arr[10] = {40, 30, 100, 60, 80, 70, 90, 10, 20, 50};
	int i = 0;

	printf("before\n");
	for (;i < 10 ; i++)
		printf("%d ", arr[i]);
	printf("\n\n");

	mergeSort(arr, 0, 9);
	printf("after\n");
	for (i = 0;i < 10 ; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
}
*/
void mergeSort(int *arr, int start, int end)
{
	if(start < end)
	{
		int mid = (start + end) / 2;

		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
	return ;
}

void merge(int *arr, int start, int mid, int end)
{
	int *temp = malloc(sizeof(int) *(end - start + 1));
	int i = start, j = mid + 1, k = 0;
	printf("in merge %d %d %d\n",start, mid, end);
	while(i <= mid && j <= end)
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	while(i <= mid)
		temp[k++] = arr[i++];
	while(j <= end)
		temp[k++] = arr[j++];
	while(--k >= 0)
		arr[start + k] = temp[k];
	free(temp);
}