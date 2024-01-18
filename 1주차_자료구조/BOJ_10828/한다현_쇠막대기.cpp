#include<iostream>
#include<stack>
#include<string>
#include<sstream>

using namespace std;

int main(){
    int n;
    cin>>n;
    
    stack<int> stk;
    cin.ignore();
    
    for(int i=0;i<n;i++){
        string s;
        
        getline(cin, s);
        
        if(s[0]=='t'){ //top인 경우
            if(stk.empty()) cout<<-1<<"\n";
            else cout<<stk.top()<<"\n";
        }
        
        else if(s[0]=='s'){ //size인 경우
            cout<<stk.size()<<"\n";
        }
        
        else if(s[0]=='e'){ //empty인 경우
            if(stk.empty()) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        
        else{
            if(s[1]=='o'){ //pop인 경우
                if(stk.empty()) {
                    cout<<-1<<'\n';
                }
                else{
                    cout<<stk.top()<<"\n";
                    stk.pop();
                    
                }
            }
            
            else{ //push인 경우
                //cout<<s[5]<<endl;
                istringstream ss (s);
                string subs1;

                while(getline(ss,subs1,' ')){
                    if(subs1!="push"){
                        stk.push(stoi(subs1));
                    }
                }

            }
        }
        
        
    }
    
}
