#include <iostream>
#include<queue>
using namespace std;

priority_queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, x;
	cin >> N; //���� Ƚ��

	for (int k = 0; k < N; k++) {

		cin >> x;

		if (x == 0) { //�ִ� �� ��� �� ����
			if (q.empty()) { //�ִ� �� ��������� 0���
				cout << 0 << '\n';
			}
			else { //�ִ� �� ���
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else { //��� ����
			q.push(x);
		}
	}

	return 0;
}