#include<iostream>
#include<vector>
using namespace std;
vector<int> v[100001];
bool isvisited[100001];
int parent[100001];

void dfs(int node){
    if(isvisited[node])
        return;
    isvisited[node]=true;
    for(auto u : v[node]){
        if(!isvisited[u]){
            parent[u]=node;
            dfs(u);
        }
    }
}
int main(){
    int N;  cin>>N;
    for(int i=0;i<N-1;i++){
        int num1,num2; cin>>num1>>num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }
    dfs(1);
    for(int i=2;i<=N;i++){
        cout<<parent[i]<<'\n';
    }
}