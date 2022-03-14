#include <stdio.h>

void insertion(int arr[], int size);
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	// int arr[] = {3, 1, 7, 2, 8, 4, 6, 2, 5};
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

	int size = sizeof(arr)/sizeof(int);
	printf("before------\n");
	for (int i = 0 ; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
	printf("after---------\n");
	insertion(arr, size);
	for (int i = 0 ; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void insertion(int arr[], int size)
{
    int i, j;
    int temp;

    i = 1;
    while (i < size)
    {
        j = i - 1;
        temp = arr[i];
        while (j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        i++;
    }
}