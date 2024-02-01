#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int visited[52];
int visited2[52];
vector<int> child[52];
int ans=0,root;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    
    cin>>n;
    
    if(n==1) { //노드가 하나인 경우
        cout<<0;
        return 0;
    }
    
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a==-1) {
            root=i; //루트노드 확인
            continue;
        }
        
        child[a].push_back(i);
        
    }
    

    int erase;
    cin>>erase;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<child[i].size();j++){
            if(child[i][j]==erase){
                child[i].erase(child[i].begin()+j);
            }
        }
    }
        
        if(erase==root){ //루트 삭제하는 경우
            cout<<0;
            return 0;
        }
        
        queue<int> q;
        if(!child[erase].empty()){ //erase가 child를 가지고 있다면
            q.push(erase);
            visited[erase]=1;
        }
        
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            if(!child[cur].empty()) continue;
            
            for(int i=0;i<child[cur].size();i++){
                if(visited[child[cur][i]]) continue;
                q.push(child[cur][i]);
                child[cur].erase(child[cur].begin()+i);
                visited[child[cur][i]]=1;
            }
        }

        
        queue<int> q2;
        
        if(child[root].empty()){ //루트노드가 리프노드인경우
            cout<<1;
            return 0;
        }
        
        for(int i=0;i<child[root].size();i++){
            q2.push(child[root][i]);
            visited2[child[root][i]]=1;
        }
        
        
        while(!q2.empty()){
            
            int cur=q2.front();
            
           
            q2.pop();
            
            if(child[cur].empty()) { //자식이없으면 리프노드이기 때문에
              
                ans++;
                continue;
            }
            
            for(int i=0;i<child[cur].size();i++){
               
                if(visited2[child[cur][i]]) continue;
                q2.push(child[cur][i]);
                visited2[child[cur][i]]=1;
                
                
            }
        }
        cout<<ans;
        
    
}
    





