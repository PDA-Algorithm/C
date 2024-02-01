#include<iostream>
#include <vector>
#include<queue>
#include<map>

using namespace std;
int visited[100000];
map<int,int> m;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> info[100001];
    
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        info[a].push_back(b);
        info[b].push_back(a);
    }
    
    queue<int> q;
    
    for(int i=0;i<info[1].size();i++){
        q.push(info[1][i]);
        m[info[1][i]]=1;
        visited[info[1][i]]=1;
       
    }
   
    while(!q.empty()){
       
        int cur=q.front();
       
        q.pop();
        for(int i=0;i<info[cur].size();i++){
            if(visited[info[cur][i]]==1) continue;
            q.push(info[cur][i]);
            m[info[cur][i]]=cur;
            visited[info[cur][i]]=1;
        }
    }
    
    for(auto iter:m){
        if(iter.first==1) continue;
        cout<<iter.second<<"\n";
    }
    
}
