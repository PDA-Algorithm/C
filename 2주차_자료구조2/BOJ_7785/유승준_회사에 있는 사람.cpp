#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
set<string,greater<string>> s;
int n;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        string str1, str2;
        cin>>str1>>str2;
        if(str2=="enter")
            s.insert(str1);
        else
            s.erase(str1);
    }
    for(auto u : s)
        cout<<u<<'\n';
}