#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int visited[10001];
vector<pair<int,int> >node[10001];
int maxVal=-1, maxnode=0;

//루트에서 가장 먼 노드를 찾고 찾은 노드에서 가장 먼 노드를 찾는 문제!

void dfs(int now, int val){

    visited[now]=1; //방문 처리
    if(maxVal < val){ //최대값이 갱신될 경우
        maxVal=val;
        maxnode=now;
    }
    
    for(int i=0; i<node[now].size();i++){
        if(visited[node[now][i].first]==1) //이미 방문한 경우
            continue;
        dfs(node[now][i].first,val+node[now][i].second);
    }
}

int main(){
    cin>>n;
    
    int s,e,w;
    for(int i=0; i<n-1; i++){
        cin>>s>>e>>w;
        node[s].push_back(make_pair(e,w));
        node[e].push_back(make_pair(s,w));
    }
    dfs(1,0); //루트에서 가장 먼 노드 찾기
    
    fill_n(visited, n+1, 0);
    
    maxVal=-1;
    dfs(maxnode,0); //그 노드에서 가장 먼 노드 찾기
    cout<<maxVal<<endl;
}
