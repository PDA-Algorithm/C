#include<iostream>
#include<vector>
using namespace std;

vector<int> tree[50];
int parent[50];
int N, del;

int cnt(int);

int main()
{
	cin >> N; // ��� ����

	int root=0;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		
		if (p == -1) {
			root = i; // �θ� -1�̸� �ش� �ε����� root
		}
		else {
			parent[i] = p; // �� ����� �θ� ���
			tree[p].push_back(i); // �θ� ����� �ڽ� ���� ����
		}
	}
	cin >> del; //������ ���

	if (del == root) { // ������ ��尡 root ����̸�
		cout << 0<<"\n"; //������� ����
		return 0;
	}
	int res = cnt(root) - cnt(del); //root����϶� ���� - ������� �ؿ� ���
	int del_up = parent[del];
	// ������ ����� �θ����� �ڽ��� �ϳ��� �����ϰ� �θ��尡 ��������->+1
	if (tree[del_up].size() == 1) 
		res++;

	cout << res << "\n";

	return 0;
}

int cnt(int node) {
	int n = tree[node].size(); //���� ����� �ڽ� ��尡 �����
	
	if (n == 0) //�ڽ� ��� ������ 
		return 1; // return 1

	int reef = 0;
	for (int i = 0; i < n; i++) {
		reef = reef + cnt(tree[node][i]);
	}
	return reef;
}