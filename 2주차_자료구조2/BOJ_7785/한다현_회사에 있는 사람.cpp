#include<iostream>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    
    set<string> s;
    
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        
        if(b=="enter")
        {
            s.insert(a);
        }
        
        else{
            s.erase(a);
        }

    }
    
    for (set<string>::reverse_iterator iter = s.rbegin(); iter != s.rend(); iter++) {
           cout << *iter << "\n";
       }
    
  
   
    
}
