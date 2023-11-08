#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int>& vec)
{
    int cmp{ 0 }, chg{ 0 }, times{ 0 };
    int right = vec.size() - 1;

    for (int i = 0; i < vec.size() - 1; i++) {
        bool flag = false;
        int last_swap = 0;

        for (int j = 0; j < right; j++) {
            cmp++;
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                chg++;
                flag = true;
                last_swap = j;
            }
        }
        if (!flag) {
            break;
        }
        right = last_swap;
        times++;

    }
    if (right != 0) times++;
    cout << cmp << " " << chg << " " << times << endl;
}

int main()
{
    int N{ 0 }, tmp{ 0 };
    cin >> N;
    vector<int> vec;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    bubble_sort(vec);
    return 0;
}
