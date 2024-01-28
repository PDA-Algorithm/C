#include<iostream>
#include<string>
#include<set>
#include<map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	set<pair<int, int>> list; //{���̵�, ������ȣ}, ���̵����� �������� ����
	map<int, int> list_key; //������ȣ�� ���� ���̵� �ٸ� �� ������ �ٽ� ���� 

	int N, M; int P, L;

	cin >> N; //����Ʈ�� �ִ� ���� ����
	for (int n = 0; n < N; n++) {
		cin >> P >> L;
		list_key[P] = L;
		list.insert({ L,P });
	}

	cin >> M; //��ɹ� ����
	for (int m = 0; m < M; m++) {
		string s;
		cin >> s;
		if (s == "recommend") {
			int x;
			cin >> x;
			if (x == 1) { //���� ����� ���� ���
				cout << (*(--list.end())).second << endl;
			}
			else { //���� ���� ���� ���
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
			list.erase({ list_key[P],P }); //list_key[P]�� P������ ���� value=���̵�
			list_key.erase(P);
		}
	}
	return 0;
}