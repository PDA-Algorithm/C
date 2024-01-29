#include<iostream>
#include <map>
#include <string>
#include <set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int temp; cin>>temp;
    for(int i=0;i<temp;i++){
        int cnt; cin>>cnt;
        multiset<int> s;
        
        for(int i=0;i<cnt;i++){
            string str; int num; 
            cin>>str>>num;
            if(str=="I")
                s.insert(num);
                
            else{ //D인 경우
                if(s.size()==0)
                    continue;
                if(num==1)  //큰거 없애기 
                    s.erase(s.find(*(--s.end())));
                
                if(num==-1)
                    s.erase(s.find(*(s.begin())));
            }
        }
        if(s.size()==0)
            cout<<"EMPTY\n";
        else
            cout<<*(--s.end())<<" "<<*s.begin()<<'\n';
    }
}