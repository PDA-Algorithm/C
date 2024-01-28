#include<iostream>
#include<string>
#include<set>
#include<map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	set<pair<int, int>> list; //{난이도, 문제번호}, 난이도별로 오름차순 정렬
	map<int, int> list_key; //문제번호에 대해 난이도 다른 값 들어오면 다시 개선 

	int N, M; int P, L;

	cin >> N; //리스트에 있는 문제 개수
	for (int n = 0; n < N; n++) {
		cin >> P >> L;
		list_key[P] = L;
		list.insert({ L,P });
	}

	cin >> M; //명령문 개수
	for (int m = 0; m < M; m++) {
		string s;
		cin >> s;
		if (s == "recommend") {
			int x;
			cin >> x;
			if (x == 1) { //가장 어려운 문제 출력
				cout << (*(--list.end())).second << endl;
			}
			else { //가장 쉬운 문제 출력
				cout << (*list.begin()).second << endl;
			}
		}
		else if (s == "add") {
			cin >> P >> L;
			list_key[P] = L;
			list.insert({ L,P });
		}
		else {
			cin >> P;
			list.erase({ list_key[P],P }); //list_key[P]가 P문제에 대한 value=난이도
			list_key.erase(P);
		}
	}
	return 0;
}