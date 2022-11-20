#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	uint64_t k = 1000000000;
	bool* prime = new bool[k];
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i < k; i++) {
		prime[i] = true;
	}
	
	int index{1};
	
	while (index < k) {
		while (!prime[index]) {
			index++;
			if (index >= k) break;
		}
		if (index < k) {
			for (int i = 2; index*i < k; i++) {
				prime[i*index] = false;
			}
		}
		index++;
	}
//	for (int i = 0; i < 2000000; i++) {
//		if (prime[i]) cout << i << " ";
//	}
//	cout << endl;
	delete[] prime;
	return 0;
}