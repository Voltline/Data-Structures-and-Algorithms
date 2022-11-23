#include <stdio.h>
#include <stdlib.h> // 用于创建和扩容数组
#include <string.h> // 用于扩容数组
typedef unsigned long long uint64;

typedef struct {
	uint64 size;
	uint64 capacity;
	int* data;
} vector;

void init_empty(vector* v)
{
	v->size = 0;
	v->capacity = 0;
	v->data = NULL;
}
void init_value(vector* v, int* array, uint64 n)
{
	// 利用memcpy完成数组数据拷贝更快
	v->size = n;
	v->capacity = n + 32;
	v->data = (int*)malloc(v->capacity * sizeof(int));
	if (v->data != NULL) {
		memcpy(v->data, array, n * sizeof(int));
	}
	else {
		printf("Initialize Failed!\n");
	}
}
void init_memory(vector* v, uint64 n)
{
	v->size = n;
	v->capacity = n + 32;
	v->data = (int*)malloc(v->capacity * sizeof(int));
}

void set(vector* v, uint64 index, int value)
{
	if (index < v->capacity) {
		if (index >= v->size) {
			v->size = index;
		}
		v->data[index] = value;
	}
	else {
		printf("Set Failed! Index out of range!\n");
	}
}
int push_back(vector* v, int value)
{
	/*
	增长模式：满了就把容量+32
	*/
	if (v->size == v->capacity) {
		v->capacity += 32;
		int* temp = v->data;
		v->data = (int*)malloc(v->capacity * sizeof(int));
		if (v->data != NULL) {
			memcpy(v->data, temp, v->size * sizeof(int));
			free(temp);
			temp = NULL;
		}
		else {
			printf("Push Back Failed\n");
			return 0;
		}
	}

	if (v->data != NULL) {
		v->data[v->size] = value;
		v->size++;
		return 1;
	}
	else return 0;
}
int get(vector* v, uint64 index)
{
	if (index < v->size) {
		return v->data[index];
	}
	else {
		printf("Index out of range!\n");
		return 0;
	}
}
int* get_ptr(vector* v, uint64 index)
{
	if (index < v->size) {
		return &v->data[index];
	}
	else return NULL;
}

uint64 size(vector* v)
{
	return v->size;
}
int empty(vector* v)
{
	if (v->size == 0) return 1;
	else return 0;
}

int cmp_1(const void* i1, const void* i2)
{
	return *(int*)i1 - *(int*)i2;
}

int cmp_2(const void* i1, const void* i2)
{
	return *(int*)i2 - *(int*)i1;
}

void sort(vector* v, int ascending)
{
	if (ascending) {
		qsort(v->data, v->size, sizeof(int), cmp_1);
	}
	else {
		qsort(v->data, v->size, sizeof(int), cmp_2);
	}
}
void clear(vector* v)
{
	free(v->data);
	v->data = NULL;
	v->capacity = 0;
	v->size = 0;
}

int main()
{
	/* 第一部分测试
	int a[] = {89, 69, 50, 69, 92, 1, 30, 88, 31, 100, 36, 14, 87, 70, 47, 33, 98, 1, 67, 78};
	vector v = { 0, NULL };
	init_value(&v, a, 20);
	for (uint64 i = 0; i < size(&v); i++) {
		printf("%d ", get(&v, i));
	}
	printf("\n");
	sort(&v, 1);
	for (uint64 i = 0; i < size(&v); i++) {
		printf("%d ", get(&v, i));
	}
	clear(&v);*/ 

	/* 第二部分测试
	vector v = { 0, NULL };
	int r = 0;
	for (uint64 i = 0; i < 15; i++) {
		r = rand() % 100;
		push_back(&v, r);
	}
	for (uint64 i = 0; i < size(&v); i++) {
		printf("%d ", get(&v, i));
	}
	printf("\n");
	sort(&v, 0);
	for (uint64 i = 0; i < size(&v); i++) {
		printf("%d ", get(&v, i));
	}
	clear(&v);
	*/

	int r = 0;
	vector v = { 0, NULL };
	for (uint64 i = 0; i < 40; i++) {
		r = rand() % 100;
		push_back(&v, r);
	}
	for (uint64 i = 0; i < size(&v); i++) {
		printf("%d ", get(&v, i));
	}
	printf("\n");
	set(&v, 20, 123456789);
	printf("%llu\n", size(&v));
	for (uint64 i = 0; i < size(&v); i++) {
		printf("%d ", get(&v, i));
	}
	return 0;
}
