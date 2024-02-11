#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

vector<pair<int, int>> tree[10001];
int visit[10001] = { false, };
int maxlength = 0;
int maxnode;

void dfs(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i < n; i++) { // root노드 1부터 생각, 간선정보 n-1개
		int v1, v2, e;
		cin >> v1 >> v2 >> e; // 부모노드 자식노드 가중치
		tree[v1].push_back({ v2,e });
		tree[v2].push_back({ v1,e });
	}

	// 1번 (root)노드부터 찾기 시작
	dfs(1, 0);
	
	memset(visit, false, sizeof(visit)); //초기화
	maxlength = 0;
	dfs(maxnode, 0); //가장 먼 정점에서 제일 먼 정점 찾기

	cout << maxlength << "\n";
	return 0;
}

void dfs(int node, int w) {
	
	if (visit[node]) //방문한 적 있으면 return
		return;
	visit[node] = true;

	if (w > maxlength) {
		maxlength = w;
		maxnode = node;
	}
	for (int i = 0; i < tree[node].size(); i++) { 
		int next = tree[node][i].first;
		int next_weight = tree[node][i].second + w;
		dfs(next, next_weight);
	}
}