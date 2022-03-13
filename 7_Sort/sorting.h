#ifndef SORT_H
# define SORT_H
/*utils*/


/*Insertion Sort*/
void insertionSort(int *arr, int left, int right);
/*Merge Sort*/
void mergeSort(int *arr, int start, int end);
void merge(int *arr, int start, int mid, int end);

/*Quick Sort*/
int min(int a, int b);
void quickSort(int *arr, int start, int end);

/*Tim Sort*/
#endif
