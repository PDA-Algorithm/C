#include<iostream>
#include<string>

using namespace std;
bool prime(int n){
    if(n<2){
        return false;
    }
    
    else{ //소수인지 판별
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
}

bool palin(int n){
    string str;
    str=to_string(n);
    for (int i = 0; i < str.size(); i++) {
            if (str[i] != str[str.size()-1-i]) { //팰린드롬이 아니라면
                return false;
            }
        }
     
        return true;
    
}

int main(){
    int n;
    cin>>n;
    while(1){
        if(prime(n)&&palin(n)){ //소수이면서 팰린드롬이라면
            cout<<n;
            break;
        }
        else{
            n++;
        }
    }
    
}
