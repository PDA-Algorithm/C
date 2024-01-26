#include<iostream>
#include<map>
#include<sstream>


using namespace std;

//map의 자동정렬되는 속성을 이용해서 풀이함

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    map<pair<int,int>,int> mapp;
    map<int,int> problemList;

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int p,l;
        cin>>p>>l;
        mapp[{l,p}]++;
        problemList[p]=l;
    }
    
    int m;
    cin>>m;
    cin.ignore(); //getline이 호출되기 전 받는입력이 있다면, 버퍼에 개행문자가 남아있어 '\n'이 getline에 바로 입력되어버리는 현상이 발생
    
    for(int i=0;i<m;i++){
       
        string s;
        getline(cin,s);
        //cout<<s<<endl;
        
        if(s[0]=='a'){ //add
            stringstream ss(s);
            string num1,num2;
            string a;
            ss>>a>>num1>>num2;
            mapp[{stoi(num2),stoi(num1)}]++;
            
        }
        
        else if(s[0]=='r'){//recommend
            stringstream ss(s);
            string a,num;
            ss>>a>>num;
            if(stoi(num)==1){ //가장 어려운 문제의 번호 출력
                cout<<prev(mapp.end())->first.second<<"\n";
            }
            else{ //가장 쉬운 문제 번호 출력
                cout<<mapp.begin()->first.second<<"\n";
            }
            
        }
        
        else{//solved
            stringstream ss(s);
            string a,num;
            ss>>a>>num;
            mapp.erase({problemList[stoi(num)],stoi(num)}); //mapp에서 지워주기

        }
        
        
        
    }
    
}
