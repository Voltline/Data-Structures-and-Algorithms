#include <iostream>
#include <cctype>
#include <stack>
#include <string>
using namespace std;
const char c[]{ '+', '-', '*', '/', '(', ')', '~' };

string ToRPN(const string& origin);
int transform(char c);
int cmp(char c1, char c2);
int calculate(const string& RPN);

int main()
{
	string temp;
	cin >> temp;
	// cout << ToRPN(temp);
	cout << calculate(ToRPN(temp));
	return 0;
}

string ToRPN(const string& origin)
{
	string ans;
	stack<char> ch;
	bool isInner{ false };
	bool lastNum{ false };
	bool isNegative{ true };
	for (const auto& i : origin) {
		if (isdigit(i)) {
			ans.push_back(i);
			lastNum = true;
		}
		else {
			if (lastNum) {
				lastNum = false;
				isNegative = false;
				ans.push_back(' ');
			}
			if (ch.empty()) {
				if (i == '-' && !isInner && ans.empty()) ch.push('~');
				else {
					ch.push(i);
					if (i == '(') isInner = true, isNegative = true;
				}
			}
			else {
				if (i != ')') {
					if (i == '(') {
						ch.push(i);
						isNegative = true;
						isInner = true;
					}
					else if (!ch.empty() && (cmp(i, ch.top()) > 0 || (!isdigit(i) && isInner && ch.top() == '('))) {
						if (ch.top() == '(' && isNegative && i == '-') ch.push('~');
						else ch.push(i);
					}
					else {
						while (!ch.empty() && ch.top() != '(' && cmp(i, ch.top()) <= 0) {
							if (ch.top() != '(') {
								ans.push_back(ch.top());
								ans.push_back(' ');
							}
							ch.pop();
						}
						ch.push(i);
					}
				}
				else {
					while (!ch.empty() && ch.top() != '(') {
						ans.push_back(ch.top());
						ans.push_back(' ');
						ch.pop();
					}
					if (!ch.empty()) ch.pop();
					isInner = false;
				}
			}
		}
	}
	if (lastNum) ans.push_back(' ');

	while (!ch.empty()) {
		ans.push_back(ch.top());
		ans.push_back(' ');
		ch.pop();
	}
	return ans;
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
	case '~':
		return 6;
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

int calculate(const string& RPN)
{
    cout << RPN << endl;
	stack<int> s;
	int temp{ 0 };
	bool num{ false };
	for (int i = 0; i < RPN.size(); i++) {
		if (isdigit(RPN[i])) {
			temp *= 10;
			temp += RPN[i] - '0';
			num = true;
		}
		else if (!isdigit(RPN[i])) {
			if (RPN[i] == ' ') {
				if (num) {
					num = false;
					s.push(temp);
					temp = 0;
				}
				continue;
			}

			if (RPN[i] == '~') {
				int num = s.top();
				s.pop();
				s.push(-num);
			}
			else  {
				int num1{ 0 }, num2{ 0 };
				num2 = s.top();
				s.pop();
				num1 = s.top();
				s.pop();
				if (RPN[i] == '+') s.push(num1 + num2);
				else if (RPN[i] == '-') s.push(num1 - num2);
				else if (RPN[i] == '*') s.push(num1 * num2);
				else if (RPN[i] == '/') s.push(num1 / num2);
			}
		}
	}
	return s.top();
}
