#include<iostream>
#include<algorithm>

using namespace std;
int T[25];
int P[25];
int dp[25];

/*
 
       1   2   3   4   5    6    7    8   9
 T     3   5   1   1   2    4    2    2   1
 P    10  20  10  20   15  40   200   4   8
 
 인 경우
 
 dp[9]=P[9]
 dp[8]=max(P[8]+dp[10],dp[9])
 dp[7]=max(P[7]+dp[9],dp[8]) ->여기서 9는 T[i]+i
 dp[6]=max(P[6]+dp[10],dp[7])
 
 => 점화식 dp[i]=max(dp[i+1],P[i]+dp[idx]);
 
 */
int main(){
    
    int n;
    cin>>n;
    
    
    for(int i=1;i<=n;i++){
        
        cin>>T[i]>>P[i];
        
    }
    
    for(int i=n;i>=1;i--){
        int idx=T[i]+i;
        if(idx>n+1){
            dp[i]=dp[i+1];
        }
        else{
            dp[i]=max(dp[i+1],P[i]+dp[idx]);
        }
        
      
       
    }
    cout<<dp[1];
    
    
    
}
