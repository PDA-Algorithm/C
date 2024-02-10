#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    
    int dp[2][100000];
    int score[2][100000];
    
    while(t>0){
        int n;
        cin>>n;
        for(int j=0;j<2;j++){
            for(int i=0;i<n;i++){
                cin>>score[j][i];
            }
        }
        
        dp[0][0]=score[0][0];
        dp[1][0]=score[1][0];
        
       
        for(int j=1;j<n;j++){
            
            dp[0][j]=max(dp[0][j-1],dp[1][j-1]+score[0][j]);
            dp[1][j]=max(dp[1][j-1],dp[0][j-1]+score[1][j]);
            
        }
        
        cout<<max(dp[0][n-1],dp[1][n-1])<<"\n";

        t--;
    }
}
