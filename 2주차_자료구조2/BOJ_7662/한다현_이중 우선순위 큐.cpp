#include<iostream>
#include<queue>
#include<map>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    map<int,int> m;

    int t;
    cin>>t;
    
    for(int i=0;i<t;i++){
        int k;
        cin>>k;
        m.clear();
        for(int j=0;j<k;j++){
            char s;
            int n;
            cin>>s>>n;
            
            if(s=='I'){ //추가
                m[n]++;
               
            
            }
            
            else if(s=='D'){ //삭제
                
                if(m.empty()) continue; //비어있다면 무시
                int tmp;
                
                if(n==1){ //최댓값 삭제
                    tmp=prev(m.end())->first;
                    m[tmp]--;
                    if(m[tmp]==0) m.erase(tmp);
                }
                
                else{ //최솟값 삭제
                    tmp=m.begin()->first;
                    m[tmp]--;
                    if(m[tmp]==0) m.erase(tmp);
                  
                }
            }
        }
    
        if(m.empty()) cout<<"EMPTY\n";
        else{
            cout<<prev(m.end())->first<<" "<<m.begin()->first<<"\n";
        }
    }
}
