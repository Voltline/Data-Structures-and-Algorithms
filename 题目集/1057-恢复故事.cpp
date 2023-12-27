#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
	string line;
	node* next;
};

struct pic
{
	string head;
	string tail;
	node* ls;
	node* end;
};

int find(const vector<string>& v, const string& s)
{
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == s) return i;
	}
	return -1;
}

int main()
{
	int p{ 0 }, l{ 0 };
	cin >> p >> l;
	cin.get();
	string line;
	vector<pic> pics;
	vector<string> heads, tails;
	for (int i = 0; i < p; i++) {
		pics.push_back(pic{ "--/", "--/", nullptr, nullptr });
		auto& curpic{ pics[i] };
		for (int j = 0; j < l; j++) {
			getline(cin, line);
			if (curpic.head == "--/") curpic.head = curpic.tail = line;
			else curpic.tail = line;
			node* newnode{ new node{line, nullptr} };
			if (curpic.ls == nullptr) curpic.ls = newnode;
			else {
				node* ptr{ curpic.ls };
				while (ptr->next != nullptr) ptr = ptr->next;
				ptr->next = newnode;
			}
			curpic.end = newnode;
		}
		heads.push_back(pics[i].head);
		tails.push_back(pics[i].tail);
	}

	int cnt{ 1 };
	pic* first{ &pics[0]};
	for (int i = 0; i < heads.size(); i++) {
		if (find(tails.begin(), tails.end(), heads[i]) == tails.end()) {
			first = &pics[i];
			break;
		}
	}
	while (cnt < pics.size()) {
		int idx = find(heads, first->tail);
		first->end->next = pics[idx].ls->next;
		first->end = pics[idx].end;
		first->tail = pics[idx].tail;
		cnt++;
	}
	node* lines{ first->ls };
	while (lines != nullptr) {
		cout << lines->line << endl;
		lines = lines->next;
	}
	return 0;
}
