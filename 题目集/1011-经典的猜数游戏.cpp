#include <iostream>
#include <string>
using namespace std;
int MAXINT = 1000000000, MININT = -1000000000;

int main()
{
	int test{ 0 };

	string in;
	for (int i = 0; i < 31; i++) {
		cout << test << endl;
		cin >> in;
		if (in == "big") {
			MAXINT = test;
			test += MININT;
			test = (test % 2 == 0) ? test : test - 1;
			test /= 2;
		}
		else if (in == "small") {
			MININT = test;
			test += MAXINT;
			test = (test % 2 == 0) ? test : test + 1;
			test /= 2;
		}
		else {
			break;
		}
	}
	return 0;
}
