#include <iostream>
#include <cctype>
#include <stack>
#include <string>
using namespace std;

void ToRPN(const string& origin);
int transform(char c);
int cmp(char c1, char c2);

int main()
{
	string temp;
	cin >> temp;
	ToRPN(temp);
	return 0;
}

void ToRPN(const string& origin)
{
	stack<char> ch;
	bool isInner{ false };
	for (const auto& i : origin) {
		if (isdigit(i)) {
			cout << i;
		}
		else {
			if (ch.empty()) ch.push(i);
			else {
				if (i != ')') {
					if (i == '(') {
						ch.push(i);
						isInner = true;
					}
					else if (!ch.empty() && cmp(i, ch.top()) > 0 || (!isdigit(i) && isInner && ch.top() == '(')) {
						ch.push(i);
					}
					else {
						while (!ch.empty() && ch.top() != '(' && cmp(i, ch.top()) <= 0) {
							if (ch.top() != '(') cout << ch.top();
							ch.pop();
						}
						ch.push(i);
					}
				}
				else {
					while (!ch.empty() && ch.top() != '(') {
						cout << ch.top();
						ch.pop();
					}
					if (!ch.empty()) ch.pop();
					isInner = false;
				}
			}
		}
	}
	while (!ch.empty()) {
		cout << ch.top();
		ch.pop();
	}
}

int transform(char c)
{
	switch (c) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	case '(':
		return 4;
	case ')':
		return 5;
	default:
		return -1;
	}
}

// c1 > c2 return > 0, c1 == c2 return 0, else return < 0
int cmp(char c1, char c2)
{
	int a{ transform(c1) }, b{ transform(c2) };
	return a - b;
}
