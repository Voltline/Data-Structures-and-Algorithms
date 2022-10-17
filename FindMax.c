#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start, stop;

double duration1, duration2;
double duration1_sum, duration2_sum;

int Find_Max_DC(int* array, int n);
int Find_Max_N(int array[], int n);

int main()
{
	int array[262144] = {0};
	int max_DC = 0, max_N = 0;
	for (int i = 0; i < 1000; i++) {
		srand((unsigned int)clock());
		for (int j = 0; j < 262144; j++) {
			array[j] = rand()%10000;
		}
		start = clock();
		max_DC = Find_Max_DC(array, 262144);
		stop = clock();
		duration1 = ((double)(stop - start))/(CLK_TCK);
		duration1_sum += duration1;
		
		start = clock();
		max_N = Find_Max_N(array, 262144);
		stop = clock();
		duration2 = ((double)(stop - start))/(CLK_TCK);
		duration2_sum += duration2;
	}
	duration1_sum /= 1e3;
	duration2_sum /= 1e3;

	printf("DC function occupies %6.8e s\n", duration1_sum);	
	printf("N function occupies %6.8e s\n", duration2_sum);
//	int array[10] = {0};
//	for (int j = 0; j < 10; j++) {
//		array[j] = rand()%100;
//	}
//	int max_DC = Find_Max_DC(array, 10);
//	printf("Max = %d\n", max_DC);
	return 0;
}

// O(logn)
int Find_Max_DC(int* array, int n)
{
//	for (int i = 0; i < n; i++) {
//		printf("%d  ", *(array+i));
//	}
//	printf("\n");
	
	if (n == 2) {
		return *(array+0) > *(array+1) ? *(array+0) : *(array+1);
	}
	if (n == 3) {
		return *(array+0) > *(array+1) ? *(array+0) > *(array+2) ? *(array+0) : *(array+2) : *(array+1) > *(array+2) ? *(array+1) : *(array+2);
	}
	else {
		int half = 0, left, right;
		if (n%2 == 0) {
			left = Find_Max_DC(&array[0], n/2);
			right = Find_Max_DC(&array[n/2], n/2);
		}
		else {
			left = Find_Max_DC(&array[0], (n+1)/2);
			right = Find_Max_DC(&array[n/2], (n+1)/2);
		}
		return left > right ? left : right;
	}
}


// O(n)
int Find_Max_N(int array[], int n)
{
	int max = array[0];
	for (int i = 1; i < n; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	return max;
}
