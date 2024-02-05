#include<iostream>
#include<vector>
using namespace std;
vector<int> v[51];
bool isvisited[51];
int ans; 

bool isleaf(int node){ //주변에 다 방문해야 리프
    for(auto u : v[node]){
        if(!isvisited[u]) //방문 안한곳 있으면 false 리턴
            return false;
    }
    return true;
}

void dfs(int node){
    if(isvisited[node])
        return;
    isvisited[node]=true;

    if(isleaf(node))
        ans++;
    for(auto u : v[node]){
        if(!isvisited[u])
            dfs(u);
    }
}

int main(){
    int N,root; cin>>N;
    for(int i=0;i<N;i++){ //2번부터 N-1노드 까지
        int num;   cin>>num;
        if(num==-1){
            root=i;
            continue;
        }
        v[num].push_back(i);
        v[i].push_back(num);
    }
    int cut; cin>>cut;
    isvisited[cut]=1;
    dfs(root);
    cout<<ans;
}