#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

template<typename T>
class heap
{
	// Big root heap
public:
	vector<T> data;
	size_t size;
	heap()
	{
		size = 0;
	}

	heap(const vector<T>& nums)
	{
		// 99 5 36 7 22 17 46 12 2 19 25 28 1 92
		this->data = nums;
		this->size = nums.size() - 1;
		for (size_t i = size / 2; i >= 1; i--) {
			siftdown(i);
		}
	}

	void siftup(size_t i)
	{
		bool check = false;
		if (i == 1) return;
		else {
			while (i != 1 && !check) {
				if (this->data[i] < this->data[i / 2]) {
					T temp = this->data[i / 2];
					this->data[i / 2] = this->data[i];
					this->data[i] = temp;
					i /= 2;
				}
				else check = true;
			}
		}
		return;
	}

	void siftdown(size_t i)
	{
		bool check = false;
		size_t t = 0;
		while (i * 2 <= this->size && !check) {
			if (this->data[i] < this->data[i * 2]) {
				t = i * 2;
			}
			else t = i;

			if (i * 2 + 1 <= this->size) {
				if (this->data[t] < this->data[i * 2 + 1]) {
					t = i * 2 + 1;
				}
			}

			if (t != i) {
				T temp = this->data[t];
				this->data[t] = this->data[i];
				this->data[i] = temp;
				i = t;
			}
			else {
				check = true;
			}
		}
		return;
	}

	T deletemin()
	{
		T temp = this->data[1];
		this->data[1] = this->data[this->size--];
		siftdown(1);
		return temp;
	}

	void addElement(T num)
	{
		this->data.push_back(num);
		this->size++;
		siftup(this->size);
	}

	void heap_sort()
	{
		heap<T> h_temp{ *this };
		while (h_temp.size >= 1) {
			printf("%d ", h_temp.deletemin());
		}
		printf("\n");
	}

	void heap_select(int m)
	{
		if (m >= this->size-1) heap_sort();
		else {
			int cnt{ 0 };
			heap<T> h_temp{ *this };
			while (cnt < m) {
				printf("%d ", h_temp.deletemin());
				cnt++;
			}
			printf("\n");
		}
	}

	bool empty()
	{
		if (this->size == 0) return true;
		else return false;
	}
};

int main()
{
	int N{ 0 }, M{ 0 };
	scanf("%d%d", &N, &M);
	int in{ 0 };
	vector<int> em{ -1 };
	for (int i = 0; i < N; i++) {
		scanf("%d", &in);
		em.push_back(in);
	}
	heap<int> embs(em);
	embs.heap_select(M);
	return 0;
}
