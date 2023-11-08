#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n{0};
    cin >> n;
    vector<int> ls;
    for (int i = 0; i < n; i++) {
        int temp{0};
        cin >> temp;
        ls.push_back(temp);
    }
    int q{0}, cmd{0}, k{0};
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> cmd >> k;
        k--;
        if (cmd == 1) {
            int x{0};
            cin >> x;
            ls.insert(ls.begin() + k, x);
        }
        else {
            if (k < ls.size()) {
                cout << ls[k] << endl;
                ls.erase(ls.begin() + k);
            }
            else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}
