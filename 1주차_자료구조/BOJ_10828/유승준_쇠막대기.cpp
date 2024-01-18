#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  
    
    stack<int> s;
    int a;
    cin>>a;
    string c;    
    
    for(int i=0;i<a;i++){
        cin>>c;

        if(c=="push") {
            int num;
            cin>>num;
            s.push(num);
        }
        else if(c=="pop"){
            if(!s.empty()){
                cout<<s.top()<<'\n';
                s.pop();
            }
            else
                cout<<"-1\n";
        }
        else if(c=="size")
            cout<<s.size()<<'\n';
        
        else if(c=="empty")
            cout<<(s.empty() ? 1 : 0)<<'\n';  
            
        else if(c=="top"){
            if(!s.empty())
                cout<<s.top()<<'\n';
            else
                cout<<"-1"<<'\n';
        
        }
    }
    return 0;
}