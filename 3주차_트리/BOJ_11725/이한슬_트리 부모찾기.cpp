#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> tree[100001];
bool visit[100001];
int res[100001];

void find_tree(void);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N-1; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		tree[n1].push_back(n2);
		tree[n2].push_back(n1); //노드에 연결된 각 노드들 저장
	}

	find_tree();

	for (int i = 2; i <= N; i++) { // root 제외하고 출력
		printf("%d\n", res[i]);
	}

	return 0;
}

void find_tree(void) {
	queue<int> q;
	visit[1] = true;
	q.push(1); //root 1이라고 함

	while (!q.empty()) {
		int p = q.front();
		q.pop();

		for (auto it = tree[p].begin(); it != tree[p].end(); it++){
			int c = *it;
			if (!visit[c])
			{
				res[c] = p;
				visit[c] = true;
				q.push(c);
			}
		}
	}
}
