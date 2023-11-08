#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct item
{
	string mandarin;
	string dialect;

	item()
		: mandarin("0"), dialect("0") {}
	item(const string& mand, const string& dial)
		: mandarin(mand), dialect(dial) {}
};

struct node
{
	bool empty;
	item it;
	node* next;

	node()
		: empty(true), it(), next(nullptr) {}
};

node dict[100010];
int dict_size{ 0 };
// mandarin "0" for empty, "-1" for delete mark

int str_hash(const string& dialect)
{
	size_t size{ dialect.size() };
	int base{ 31 }, code{ dialect[0] };
	for (int i = 1; i < size; i++) {
		code *= base;
		code %= 100010;
		code += dialect[i];
	}
	return code % 100010;
}

bool insert(const string& dialect, const string& mandarin)
{
	if (dict_size <= 100010) {
		int code{ str_hash(dialect) };
		node* ptr{ &dict[code] };
		if (ptr->empty) {
			ptr->empty = false;
			ptr->it = item{ mandarin, dialect };
		}
		else {
			while (ptr->next != nullptr) {
				ptr = ptr->next;
			}
			ptr->next = new node;
			ptr->next->empty = false;
			ptr->next->it = item{ mandarin, dialect };
			ptr->next->next = nullptr;
		}
		dict_size++;
		return true;
	}
	return false;
}

item get(const string& dialect)
{
	if (dict_size) {
		int code{ str_hash(dialect) };
		node* ptr{ &dict[code] };
		while (ptr->it.dialect != dialect && ptr->next != nullptr) {
			ptr = ptr->next;
		}
		if (ptr->it.dialect == dialect) return ptr->it;
		else return dict[0].it;
	}
	else return dict[0].it;
}

int main()
{
	string line, mandarin, shanghainese;
	istringstream sin;
	do {
		getline(cin, line);
		if (line != "") {
			sin = istringstream(line);
			sin >> mandarin >> shanghainese;

			insert(shanghainese, mandarin);
		}
	} while (line != "");

	while (cin >> line) {
		item g{ get(line) };
		if (g.dialect == line) cout << g.mandarin << endl;
		else cout << "eh" << endl;
	}
	return 0;
}
