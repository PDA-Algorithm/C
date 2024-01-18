#include<iostream>
#include<string>
#include<stack>
using namespace std;
int ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin>>N;
    for(int i=0;i<N;i++){
        stack<int> stk;
        string str; cin>>str;
        for(int i=0;i<str.size();i++){
            if(!stk.empty() && stk.top()==str[i])
                stk.pop();
            else
                stk.push(str[i]);
        }
        if(stk.size()==0)
            ans++;
    }
    cout<<ans;
}