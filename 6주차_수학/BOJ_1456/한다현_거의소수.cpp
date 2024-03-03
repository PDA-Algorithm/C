#include<iostream>
#include <cmath>
#include<vector>

using namespace std;

vector<bool> v(10000002, true);
int ans=0;
long long a,b;

//에라토스테네스의 체로 소수 구하기
void calPrime(long double n){
        for (int i=2; i*i<=n; i++) {
        if (v[i]) {
            for (int k =i*i; k<=n; k+=i) {
                v[k]=false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin>>a>>b;
    long double jisu,jisu2;
    long double i=2.0;
    

    calPrime(sqrt(b));

    while(true){
        if(i==300) break; //종료조건을 제대로 못구해서 그냥 큰 수를 넣어둠...
    
        jisu=pow(b,(1.0/i));
        jisu2=pow(a,(1.0/i));


        for(int j=2;j<=jisu;j++){
           
            if(v[j]&&j>=jisu2) {//소수이고 j가 jisu2보다 크거나 같으면
                 ans++;
             }
        }    
        i+=1;

    }

    cout<<ans;



}
