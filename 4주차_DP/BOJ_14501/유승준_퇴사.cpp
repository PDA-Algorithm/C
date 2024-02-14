#include<iostream>
#include<algorithm>
using namespace std;
int arr[16];
int dp[16];
int M=0;
int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int n;
        cin>>n>>arr[i];
        
        

        for(int j=i;j<N;j++){
            dp[n+j-1] = max(dp[i-1]+arr[i], dp[n+j-1]);
        }
        for(int j=0;j<N;j++){
            if(dp[j]>M)
                M = dp[j];
        }
    }
    cout<<M;
}