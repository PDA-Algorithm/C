#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, k; // T=tc 개수, k=연산 개수
	cin >> T;
	char c; int n;

	for (int i = 0; i < T; i++) {
		multiset<int> pq;//이중 우선 순위 큐, 내림차순 정렬, multiset->중복허용
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> c >> n;
			if (c == 'I') { //삽입
				pq.insert(n);
			}
			else { //삭제
				if (pq.empty()) { //비어있으면 넘어가기
					continue;
				}
				if (n == 1) { //촤댓값(맨끝) 삭제
					pq.erase(--pq.end());
				}
				else { //최솟값(맨앞) 삭제
					pq.erase(pq.begin());
				}

			}
		}

		if (!pq.empty()) {
			cout << *(--pq.end()) << " " << *(pq.begin()) << "\n";
		}
		else //pq 비어있으면 empty 출력
			cout << "EMPTY\n";
	}
}