#include<iostream>
#include<string>
#include<stack>
#include<math.h>
using namespace std;
int ans,temp,check;
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
            if(check==0){ //닫는 괄호 일 때만 더하기!
                temp += (pow(2,s) * pow(3,m)); //내앞에 소괄호 중괄호 몇개있나 확인 ex) 앞에 (([ 있으면 2*2*3임
                check=1; //체크용 변수 (())일때 2번더하는 등 불참사 막기
            }
            if(i==str.size()-1) // ((( ')' )) 4번째 문자 끝까지 안더해짐 (더해야 하는 문자 무조건 남는데 맨 마지막에 더해주기)
                ans+=temp;      //체크는 굳이 바꿔주지 않는다
            subparan(str[i]);
            continue;
        }
        ans+=temp; //더하는건 현재 문자가 닫는괄호 아닐때 ==> ((()))
        temp=0; check=0;    //더했으니까 0으로 초기화 => 
        addparan(str[i]);
    }
    cout<<(stk.empty() ? ans : 0);
}