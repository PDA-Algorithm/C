#include<iostream>
#include<string>
#include<stack>
#include<math.h>
using namespace std;
int ans,temp,ready;
int s,m; //소괄호 중괄호
stack<int> stk;
void addparan(char c){
    stk.push(c);
    c == '(' ? s++ : m++;
}
void subparan(char c){
    stk.pop();
    c == ')' ? s-- : m--;  
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str; cin>>str;
    for(int i=0;i<str.size();i++){
        if(!stk.empty() && (stk.top()=='(' && str[i]==')' || stk.top()=='[' && str[i]==']') ){
            if(ready){ // 닫는 괄호 일 때만 더하기!
                ans += (pow(2,s) * pow(3,m)); // 내앞에 소괄호 중괄호 몇개있나 확인 ex) 앞에 (([ 있으면 2*2*3
                ready=0; //체크용 변수 => (())일때 2번더하는 등 불참사 막기
            }
            subparan(str[i]);
            continue;
        }
        ready=1;    //여는 괄호 있으면 받을 준비 되어 있음
        addparan(str[i]);
    }
    cout<<(stk.empty() ? ans : 0);
}
