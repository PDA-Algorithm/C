#include<iostream>

using namespace std;

int main(){
    int n;
    int card[10003];
    int dp[10003];
    //dp[i] : i개 살 때의 최대값을 저장해둠
    
    
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>card[i];
    }
    
    dp[1]=card[1];
    
    for(int i=2;i<=n;i++){
        dp[i]=card[i];
        for(int j=1;j<=i/2;j++){

            dp[i]=max(dp[i-j]+dp[j],dp[i]);
            
        }
    }

    cout<<dp[n];
    
    
}
