#include<iostream>
#include<vector>
using namespace std;

vector<int> tree[50];
int parent[50];
int N, del;

int cnt(int);

int main()
{
	cin >> N; // 노드 개수

	int root=0;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		
		if (p == -1) {
			root = i; // 부모가 -1이면 해당 인덱스는 root
		}
		else {
			parent[i] = p; // 각 노드의 부모 노드
			tree[p].push_back(i); // 부모 노드의 자식 노드들 저장
		}
	}
	cin >> del; //삭제할 노드

	if (del == root) { // 삭제할 노드가 root 노드이면
		cout << 0<<"\n"; //리프노드 없음
		return 0;
	}
	int res = cnt(root) - cnt(del); //root노드일때 리프 - 삭제노드 밑에 노드
	int del_up = parent[del];
	// 삭제할 노드의 부모노드의 자식이 하나면 삭제하고서 부모노드가 리프노드됨->+1
	if (tree[del_up].size() == 1) 
		res++;

	cout << res << "\n";

	return 0;
}

int cnt(int node) {
	int n = tree[node].size(); //현재 노드의 자식 노드가 몇개인지
	
	if (n == 0) //자식 노드 없으면 
		return 1; // return 1

	int reef = 0;
	for (int i = 0; i < n; i++) {
		reef = reef + cnt(tree[node][i]);
	}
	return reef;
}