#include<iostream>
using namespace std;
int arr[2][100000];
int dp[2][100000];
int main(){
    int T;  cin>>T;
    for(int q=0;q<T;q++){
        int N;  cin>>N;

        for(int i=0;i<N;i++)
            cin>>arr[0][i];
        for(int i=0;i<N;i++)
            cin>>arr[1][i];

        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        
        dp[0][1] = dp[1][0] + arr[0][1];
        dp[1][1] = dp[0][0] + arr[1][1];

        if(N==1){
            cout<<max(dp[0][0], dp[1][0])<<'\n';
            continue;
        }
        if(N==2){
            cout<<max(dp[0][1], dp[1][1])<<'\n';
            continue;
        }

        for(int i=2;i<N;i++){
            dp[0][i] = max( max(dp[0][i-2]+arr[0][i],dp[1][i-2]+arr[0][i]), dp[1][i-1]+arr[0][i]);
            dp[1][i] = max( max(dp[1][i-2]+arr[1][i],dp[0][i-2]+arr[1][i] ), dp[0][i-1]+arr[1][i]);
        }
        cout<<max(dp[0][N-1],dp[1][N-1])<<'\n';

        // for(int i=0;i<N;i++){
        //     cout<<dp[0][i]<<' ';
        // }
        // cout<<'\n';
        
        // for(int i=0;i<N;i++){
        //     cout<<dp[1][i]<<' ';
        // }
        // cout<<'\n';
    }
}