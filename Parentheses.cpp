#include <iostream>
#include <stack>
using namespace std;
bool parenthese(stack<char> stack, string s) {
	for (unsigned int i = 0; i < s.length(); i++) {
		char c = s[i], temp;
		if ((c == '(') || (c == '[') || (c == '{')) {
			stack.push(c);
		} else if (c == ')') {
			if (stack.empty())
				return 0;
			else {
				temp = stack.top();
				stack.pop();
				if (temp != '(')
					return 0;
			}
		} else if (c == ']') {
			if (stack.empty())
				return 0;
			else {
				temp = stack.top();
				stack.pop();
				if (temp != '[')
					return 0;
			}
		} else if (c == '}') {
			if (stack.empty())
				return 0;
			else {
				temp = stack.top();
				stack.pop();
				if (temp != '{')
					return 0;
			}
		}
	}
	return 1;
}
int main() {
	int n, j = 0;
	cin >> n;
	stack<char> stack;
	int a[n];
	string s;
	while (j < n) {
		while (!stack.empty()) {
			stack.pop();
		}
		s.clear();
		cin >> s;
		a[j] = parenthese(stack, s);
		j++;
	}
	for (j = 0; j < n; j++) {
		cout << a[j] << endl;
	}
	return 0;
}
