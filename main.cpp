#include <stdio.h>
#include "My_sorting.h"
#include <stdlib.h>
#include <time.h>

int main() {
	clock_t t;
	int* arr;
	int n, k;
	printf("Enter the size of array: ");
	scanf_s("%d", &n);
	printf("Enter the kind of sorting:\n1) BubbleSort\n2) Forward sorting\n3) Quick sorting\n");
	scanf_s("%d",&k);
	arr = (int*)malloc(n * sizeof(int));
	srand(time(NULL)); //системное время
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 15000000;
	}
	switch (k){
	case 1:
		t = clock();
		BubbleSort(arr, n);
		t = clock() - t;
		printf("It took me %d (%f seconds).\n",
			(int)t, ((double)t) / CLOCKS_PER_SEC);
		break;
	case 2:
		t = clock();
		ForwSort(arr, n);
		t = clock() - t;
		printf("It took me %d clicks (%f seconds).\n",
			(int)t, ((double)t) / CLOCKS_PER_SEC);
		break;
	case 3:
		t = clock();
		QuickSort(arr, n - 1, 0);
		t = clock() - t;
		printf("It took me %d clicks (%f seconds).\n",
			(int)t, ((double)t) / CLOCKS_PER_SEC);
		break;
	default:
		printf("Encorrect entering");
		break;
	}
	free(arr);
	return 0;
}