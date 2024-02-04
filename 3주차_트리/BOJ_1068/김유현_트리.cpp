
#include <iostream>
#include <queue>
#include <string.h> // memset
#include <algorithm>

#define MAX 50

using namespace std;

int N;
int parent[MAX];
int deletedNode;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> parent[i];
    }

    cin >> deletedNode;

    return; 
}

int solve(int N, int parents[], int deletedNode) {
    int answer = 0;

    vector<int> childs[MAX];
    bool isLeafNode[N];
    int rootNode;
    memset(isLeafNode, true, sizeof(isLeafNode));

    // 연결
    for(int child=0; child<N; child++) {
        if (parents[child] != -1) {
            isLeafNode[parents[child]] = false; // 부모 -> 리프 노드 아님
            childs[parents[child]].push_back(child); // 부모 - 자식
        } else {
            rootNode = child;
        }
    }

    // 루트 노드를 삭제하면 0이 나와야한다. 
    if (deletedNode == rootNode) {
        return answer;
    }

    // 리프 노드 개수
    for(int i=0; i<N; i++) {
        if (isLeafNode[i]) answer++;
    }
    
    queue<int> q;
    q.push(deletedNode);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        if (isLeafNode[curr]) {
            answer--;
        } else {
            for(int child : childs[curr]) {
                q.push(child);
            }
        }
    }

    // 지운 노드의 부모가 리프노드인지 체크하기
    int target = parents[deletedNode];
    if (find(childs[target].begin(), childs[target].end(), deletedNode) != childs[target].end()) {
        childs[target].erase(remove(childs[target].begin(), childs[target].end(), deletedNode));
    }
    if (childs[target].size() == 0) answer++;

    return answer;
}

void output(int answer) {
    cout << answer << '\n';
}

int main() {
    fastIO();
    input();
    output(solve(N, parent, deletedNode));
}