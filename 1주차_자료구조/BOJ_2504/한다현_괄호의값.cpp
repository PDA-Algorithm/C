#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<int> st;
    
    string s;
    
    cin>>s;
    
    for(int i=0;i<s.size();i++){
        
        if(s[i]=='['||s[i]=='(') st.push(s[i]);
        
        else if(s[i]==')'){
            if(st.empty()){cout<<0;  return 0;}
            else{
                if(st.top()=='(') st.pop();
                else {cout<<0;  return 0;}
            }
        }
        
        else{ //]라면
            if(st.empty()) {cout<<0;  return 0;}
            else{
                if(st.top()=='[') st.pop();
                else {cout<<0;  return 0;}
            }
        }
        
    }
    
    if(!st.empty()) {cout<<0; return 0;}
    int ans=0;
    //현재까지의 값을 계속 갱신하며(* or /), 값이 더해져야하는 순간에(제일 안쪽 괄호를 만났을 때) 결과에 반영한다.
    int temp=1;
    
    for(int i=0;i<s.size();i++){
        
        
        if(s[i]=='['){
            temp*=3;
            
        }
        
        else if(s[i]=='('){
            temp*=2;
        }
        
        else if(s[i]==']'){
            if(s[i-1]=='['){
                ans+=temp;
                temp/=3;
            }
            
            else{
                temp/=3;
            }
        }
        
        
        else if(s[i]==')'){
            if(s[i-1]=='('){
                ans+=temp;
                temp/=2;
            }
            
            else{
                temp/=2;
            }
        }
           
        
        
    }
    
    
    
    cout<<ans;
    
}
