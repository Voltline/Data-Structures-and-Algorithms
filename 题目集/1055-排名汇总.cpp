#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct item
{
	string id;
	int global_grade;
	int loc;
	int local_grade;
	int score;
};

bool cmp_local(const item& i1, const item& i2)
{
	return i1.score > i2.score;
}

bool cmp_global(const item& i1, const item& i2)
{
	if (i1.score != i2.score) {
		return i1.score > i2.score;
	}
	else return i1.id < i2.id;
}


int main()
{
	int N{ 0 }, K{ 0 }, score{ 0 };
	string id;
	vector<item> list;
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<item> temp;
		cin >> K;
		for (int j = 0; j < K; j++) {
			cin >> id >> score;
			temp.push_back(item{ id, -1, i + 1, -1, score });
		}
		sort(temp.begin(), temp.end(), cmp_local);
		int last_score{ temp[0].score }, grade_cnt{ 1 };
		temp[0].local_grade = 1;
		list.push_back(temp[0]);
		for (int j = 1; j < temp.size(); j++) {
			if (temp[j].score == last_score) {
				temp[j].local_grade = temp[j - 1].local_grade;
				grade_cnt++;
			}
			else {
				temp[j].local_grade = temp[j - 1].local_grade + grade_cnt;
				grade_cnt = 1;
				last_score = temp[j].score;
			}
			list.push_back(temp[j]);
		}
	}
	sort(list.begin(), list.end(), cmp_global);
	int last_score{ list[0].score }, grade_cnt{ 1 };
	list[0].global_grade = 1;
	for (int j = 1; j < list.size(); j++) {
		if (list[j].score == last_score) {
			list[j].global_grade = list[j - 1].global_grade;
			grade_cnt++;
		}
		else {
			list[j].global_grade = list[j - 1].global_grade + grade_cnt;
			grade_cnt = 1;
			last_score = list[j].score;
		}
	}
	cout << list.size() << endl;
	for (auto& it : list) {
		cout << it.id << " " << it.global_grade << " " << it.loc << " " << it.local_grade << endl;
	}
	return 0;
}
