#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char>line_stack; //��ȣ ��� stack
stack<int> num_stack; //��ȣ�� ����ϴ� stack
string s;
int cnt = 0;
int tmp = 1;

int main()
{
	cin >> s; //��ȣ �Է�

	if (s.size() % 2) //��ȣ Ȧ���� ������ �ȵ�
		cnt = 0;
	else {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[') { //���� ��ȣ�� stack�� ���
				line_stack.push(s[i]);
				if (s[i]=='(')
					tmp = tmp * 2;
				else if (s[i] == '[')
					tmp = tmp * 3;
			}
			else { // ')' �̰ų� ']'�� ���
				if (line_stack.empty()) { //�ݾҴµ� ������ ������ �߸���
					cnt = 0;
					break;
				}
				char p = line_stack.top();
				line_stack.pop();

				if (p == '(' && s[i] == ')') { //���� �´� ���
					if (s[i - 1] == p) { //�ݴ� ��ȣ ��==pop
						cnt = cnt + tmp;
					}
					tmp = tmp / 2;
				}
				else if (p == '[' && s[i] == ']') {
					if (s[i - 1] == p) { //�ݴ� ��ȣ ��==pop
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
