#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin>>str;
    stack<char> stk;

    int paran=0;
    int ans=0;

    for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            stk.push(str[i]);
            paran++;   
        }
        else{
            if(stk.top()=='('){
                stk.push(str[i]);
                ans += --paran;
            }
            else{
                stk.push(')');
                ans++;
                paran--;
            }
        }
    }
    cout<<ans<<'\n';
}