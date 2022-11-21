#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
using size_t = uint64_t;

template<typename T>
class heap
{
	// Small root heap
public:
	vector<T> data;
	size_t size;
	heap()
	{
		size = 0;
	}

	heap(vector<T> nums)
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
			if (this->data[i] > this->data[i * 2]) {
				t = i * 2;
			}
			else t = i;

			if (i * 2 + 1 <= this->size) {
				if (this->data[t] > this->data[i * 2 + 1]) {
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
		
		this->size--;
		this->data[1] = this->data[this->size];
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
		while (h_temp.size > 1) {
			cout << h_temp.deletemin() << " ";
		}
		cout << endl;
	}
	
	bool empty()
	{
		if (this->size == 0) return true;
		else return false;
	}

	template<typename U>
	friend ostream& operator<<(ostream& output, heap<U>& h)
	{
		size_t n = 1;
		for (size_t i = 1; i <= h.size; i++) {
			output << h.data[i] << " ";
			if (i == n * 2 - 1) {
				output << endl;
				n *= 2;
			}
		}
		output << endl;
		return output;
	}

	~heap()
	{
		this->data.~vector();
		this->size = 0;
	}
};

int main()
{
	vector<int> data;
	data.push_back(-1);
	int temp;
	while (cin >> temp) {
		data.push_back(temp);
	}
	heap<int> h(data);
	cout << h << endl;
	h.heap_sort();
	h.addElement(23);
	cout << h << endl;

	h.addElement(12);
	cout << h << endl;

	h.heap_sort();
	return 0;
}