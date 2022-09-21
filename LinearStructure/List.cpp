#include <iostream>
using namespace std;

template<typename T, int n>
class List
{
public:
	T content[n];
	int length{ n };

	List() = default;
	T FindKth(int K);
	int Find(T X);
	void Insert(T X, int i);
	void Delete(int i);
	int Length();

	template<typename U, int n>
	friend ostream& operator<<(ostream& output, List<U,n> L);
};

int main()
{
	List<int, 5> L;
	for (int i = 0; i < 5; i++) {
		int temp;
		cin >> temp;
		L.Insert(temp, i);
	}
	cout << L << endl;
	L.Insert(1000, 2);
	cout << L << endl;
	L.Delete(1);
	cout << L << endl;
	cout << "The length of L is " << L.Length() << endl;
	cout << "The Kth element of L is " << L.FindKth(4) << endl;
	return 0;
}

template<typename T, int n>
T List<T, n>::FindKth(int K)
{
	return this->content[K];
}

template<typename T, int n>
int List<T, n>::Find(T X)
{
	for (int i = 0; i < this->length; i++) {
		if (this->content[i] == X) {
			return i;
		}
	}
	return -1;
}

template<typename T, int n>
void List<T, n>::Insert(T X, int i)
{
	for (int j = this->length - 1; j >= i; j--) {
		if (this->length != 1) {
			if (j != i) {
				this->content[j] = this->content[j - 1];
			}
			else {
				this->content[j] = X;
			}
		}
		else {
			this->content[j] = X;
		}
	}
}

template<typename T, int n>
void List<T, n>::Delete(int i)
{
	for (int j = i; j < this->length; j++) {
		if (j != this->length - 1) {
			this->content[j] = this->content[j + 1];
		}
		else {
			this->content[j] = T{};
		}
	}
}

template<typename T, int n>
int List<T, n>::Length()
{
	return this->length;
}


template<typename U, int n>
ostream& operator<<(ostream& output, List<U, n> L)
{
	for (auto& i : L.content) {
		output << i << '\t';
	}
	return output;
}
