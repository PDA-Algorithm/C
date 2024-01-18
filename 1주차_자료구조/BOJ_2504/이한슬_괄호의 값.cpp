#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char>line_stack; //괄호 담는 stack
stack<int> num_stack; //괄호값 계산하는 stack
string s;
int cnt = 0;
int tmp = 1;

int main()
{
	cin >> s; //괄호 입력

	if (s.size() % 2) //괄호 홀수면 무조건 안됨
		cnt = 0;
	else {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[') { //여는 괄호면 stack에 담기
				line_stack.push(s[i]);
				if (s[i]=='(')
					tmp = tmp * 2;
				else if (s[i] == '[')
					tmp = tmp * 3;
			}
			else { // ')' 이거나 ']'인 경우
				if (line_stack.empty()) { //닫았는데 닫을게 없으면 잘못됨
					cnt = 0;
					break;
				}
				char p = line_stack.top();
				line_stack.pop();

				if (p == '(' && s[i] == ')') { //쌍이 맞는 경우
					if (s[i - 1] == p) { //닫는 괄호 앞==pop
						cnt = cnt + tmp;
					}
					tmp = tmp / 2;
				}
				else if (p == '[' && s[i] == ']') {
					if (s[i - 1] == p) { //닫는 괄호 앞==pop
						cnt = cnt + tmp;
					}
					tmp = tmp / 3;
				}
				else {
					cnt = 0;
					break;
				}
			}
		}
	}
	cout << cnt << endl;


	return 0;
}
