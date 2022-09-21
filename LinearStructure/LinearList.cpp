#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS

typedef struct
{
	int a;
	int i;
} tuple;

void print(tuple d[], int n)
{
	for (int i = 0; i < n; i++) {
		printf("%dx^%d  ", d[i].a, d[i].i);
	}
}

int main()
{
	tuple d[3] = {
		{ 9, 12 },
		{ 15, 8 },
		{ 3, 2 }
	};
	print(d, 3);
	return 0;
}