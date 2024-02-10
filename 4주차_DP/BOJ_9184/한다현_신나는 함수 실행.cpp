#include<iostream>
#include<algorithm>


using namespace std;
int dp[101][101][101];  //음수로 들어오는 값들도 저장해주기 위해 +50을 해서 100 100 100에 저장
int a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    //if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns: 1
    for(int i=0;i<=50;i++){
        for(int j=0;j<=100;j++){
            for(int k=0;k<=100;k++){
                dp[i][j][k]=1;
                dp[j][i][k]=1;
                dp[j][k][i]=1;
            }
        }
    }
    
    /*
    if a < b and b < c, then w(a, b, c) returns:
        w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

    otherwise it returns:
        w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
    */
     for(int i=51;i<=70;i++){
        for(int j=51;j<=70;j++){
            for(int k=51;k<=70;k++){

                if(i<j&&j<k) {
                    dp[i][j][k]=dp[i][j][k-1]+dp[i][j-1][k-1]-dp[i][j-1][k];
                }
                else 
                    dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k]+dp[i-1][j][k-1]-dp[i-1][j-1][k-1];
                
                
            }
        }
     }


    //if a > 20 or b > 20 or c > 20, then w(a, b, c) returns: w(20, 20, 20)
      for(int i=71;i<=100;i++){
        for(int j=51;j<=100;j++){
            for(int k=51;k<=100;k++){
                dp[i][j][k]=dp[70][70][70];
                dp[j][i][k]=dp[70][70][70];
                dp[k][j][i]=dp[70][70][70];
            }
        }
    }


    while(true){
        
        cin>>a>>b>>c;
        if(a==b&&b==c&&c==-1) break;

       
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<dp[a+50][b+50][c+50]<<"\n";
    }


    return 0;
}
