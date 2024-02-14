#include<iostream>
using namespace std;
int arr[1001];
int dp[1001];
int N; 

int func(int n){
    int M=0;
    for(int i=1; i<=n/2; i++){
        M = max(M, arr[n]);
        M = max(M, dp[i]+dp[n-i]);
    }
    return M;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  

    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
        if(i==1){
            dp[i] = arr[i];
        }
        else{
            dp[i] = func(i);
        }
    }
    cout<<dp[N];
}