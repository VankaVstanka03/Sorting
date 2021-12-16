#include "My_sorting.h"
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void ForwSort(int* arr, int n) {
	int min;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) {
				swap(&arr[j], &arr[min]);
			}
		}
		swap(&arr[i], &arr[min]);
	}
}

void QuickSort(int* arr, int r, int l) {
	int r_con = r;
	int l_con = l;
	int lead = arr[l];
	while (r > l) {
		while ((arr[r] >= lead) && (l < r)) {
			r--;
		}
		if (l != r) {
			arr[l] = arr[r];
			l++;
		}
		while ((arr[l] <= lead) && (l<r)) {
			l++;
		}
		if (l != r) {
			arr[r] = arr[l];
			r--;
		}
	}
	arr[l] = lead;
	lead = l;
	l = l_con;
	r = r_con;
	if (l < lead) {
		QuickSort(arr, lead - 1, l);
	}
	if (r > lead) {
		QuickSort(arr, r, lead + 1);
	}
}

//void MergeSort(int* arr, int n) {
//	int mid = n / 2;
//	if (n % 2 == 1) {
//		mid++;
//	}
//	int* c = (int*)malloc(sizeof(int) * mid);
//	
//}