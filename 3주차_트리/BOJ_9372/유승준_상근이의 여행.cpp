#include<iostream>
#include<vector>
using namespace std;
vector<int> v[1001];
bool isvisited[1001];
int cnt=0;
void init(){
    for(int i=0;i<1001;i++){
        isvisited[i]=false;
        v[i].clear();
    }
}
void bfs(int n){
    if(isvisited[n])
        return;
    isvisited[n]=true;
    cnt++;
    for(auto u : v[n]){
        // cout<<"u : "<<u<<' ';
        if(!isvisited[u])
            bfs(u);
    }
}
int main(){
    int T; cin>>T;
    for(int i=0;i<T;i++){
        int N,M;    cin>>N>>M;
        for(int i=0;i<M;i++){
            int num1,num2; cin>>num1>>num2;
            v[num1].push_back(num2);
            v[num2].push_back(num1);
        }
        for(int i=1;i<=N;i++){
            bfs(i);
        }
        init();

    }
}