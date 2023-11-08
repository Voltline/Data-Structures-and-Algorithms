#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N{ 0 };
    cin >> N;
    vector<int> vec;
    int t{ 0 };
    for (int i = 0; i < N; i++) {
        cin >> t;
        vec.push_back(t);
    }
    sort(vec.begin(), vec.end());
    int last{ 0 };
    for (int i = 0; i < vec.size(); i++) {
        if (i == 0) {
            cout << vec[0] << " ";
            last = vec[0];
        }
        else {
            if (vec[i] != last) {
                cout << vec[i] << " ";
                last = vec[i];
            }
        }
    }
    return 0;
}
