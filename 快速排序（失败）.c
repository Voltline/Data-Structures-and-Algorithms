#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void QuickSort(int* array, int numsSize);

int main()
{
	int k = 10000;
	int* a = (int*)malloc(k * sizeof(int));
	for (int i = 0; i < k; i++) {
		a[i] = rand() % 100000;
	}
	QuickSort(a, k);
//	for (int i = 0; i < k; i++) {
//		printf("%d ", a[i]);
//	}	
//	printf("\n");
	return 0;	
}

void QuickSort(int* array, int numsSize)
{
	if (numsSize > 1) {
		int* pivot = array, *right_p = pivot + 1;
		while (right_p < array + numsSize) {
			if (*right_p < *pivot) {
				int temp = *right_p;
				int bit = right_p - pivot;
				memcpy(pivot+1, pivot, bit*sizeof(int));
				*pivot = temp;
				pivot++;
				right_p++;
			}
			else {
				right_p++;
			}
		}
		int left = pivot - array;
		int right = array + numsSize - pivot - 1;
		QuickSort(array, left);
		QuickSort(pivot+1, right);
	}
	else return;
}
