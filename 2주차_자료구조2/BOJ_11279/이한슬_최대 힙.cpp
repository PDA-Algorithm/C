#include <iostream>
#include<queue>
using namespace std;

priority_queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, x;
	cin >> N; //연산 횟수

	for (int k = 0; k < N; k++) {

		cin >> x;

		if (x == 0) { //최대 값 출력 후 삭제
			if (q.empty()) { //최대 힙 비어있으면 0출력
				cout << 0 << '\n';
			}
			else { //최대 값 출력
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else { //계속 저장
			q.push(x);
		}
	}

	return 0;
}