#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, k; // T=tc ����, k=���� ����
	cin >> T;
	char c; int n;

	for (int i = 0; i < T; i++) {
		multiset<int> pq;//���� �켱 ���� ť, �������� ����, multiset->�ߺ����
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> c >> n;
			if (c == 'I') { //����
				pq.insert(n);
			}
			else { //����
				if (pq.empty()) { //��������� �Ѿ��
					continue;
				}
				if (n == 1) { //�Ҵ�(�ǳ�) ����
					pq.erase(--pq.end());
				}
				else { //�ּڰ�(�Ǿ�) ����
					pq.erase(pq.begin());
				}

			}
		}

		if (!pq.empty()) {
			cout << *(--pq.end()) << " " << *(pq.begin()) << "\n";
		}
		else //pq ��������� empty ���
			cout << "EMPTY\n";
	}
}