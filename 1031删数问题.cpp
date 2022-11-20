#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string n;
	int s{0};
	cin >> n >> s;
	for (int i = 0; i < n.length() - 1; i++) {
		if (s > 0) {
			if (n[i] > n[i+1]) {
				n.erase(n.begin() + i);
				s--;
				i = -1;
			}
		}
	}
	while (n[0] == '0') {
		n.erase(n.begin());
	}
	if (s != 0) 
		cout << n.substr(0, n.length()-s) << endl;
	else cout << n << endl;
	return 0;	
}