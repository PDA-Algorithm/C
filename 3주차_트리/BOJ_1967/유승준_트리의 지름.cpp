#include<iostream>
#include<vector>
using namespace std;
int N,maxValue;
vector<pair<int,int>> v[10001];
bool isvisited[10001];

void init(){
    for(int i=0;i<10001;i++)
        isvisited[i]=false;
}

void dfs(int i,int cost){

    if(isvisited[i])
        return;
    isvisited[i]=true;
    
    maxValue = max(maxValue,cost);

    for(auto u : v[i]){
        dfs(u.first,cost+u.second);
    }
}
int main(){
    cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b,c; cin>>a>>b>>c;
        v[a-1].push_back({b-1,c});
        v[b-1].push_back({a-1,c});
    }
    for(int i=0;i<N;i++){
        dfs(i,0);
        init();
    }
    cout<<maxValue;
}