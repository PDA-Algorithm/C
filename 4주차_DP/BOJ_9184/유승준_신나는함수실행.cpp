#include<iostream>
using namespace std;
//-50 ~ 50 까지 => 0 ~ 100으로 일단 바꾸자
int arr[50][50][50];
void init2(){
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            arr[i][j][j]=1;
        }
    }
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            arr[0][i][j]=1;
        }
    }
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            arr[i][0][j]=1;
        }
    }
}
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            arr[0][i][j]=1;
            arr[i][0][j]=1;
            arr[i][j][0]=1;
        }
    }

    for(int i=1;i<21;i++){
        for(int j=1;j<21;j++){
            for(int k=1;k<21;k++){
                if(i < j && j< k){
                    arr[i][j][k] = arr[i][j][k-1] + arr[i][j-1][k-1] - arr[i][j-1][k];
                }else{
                    // w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
                    arr[i][j][k] = arr[i-1][j][k] + arr[i-1][j-1][k] + arr[i-1][j][k-1] - arr[i-1][j-1][k-1];
                }
            }
        }
    }
    
    while(1){
        int n1,n2,n3, ans; cin>>n1>>n2>>n3;
        if(n1==-1 && n2 == -1 && n3 == -1)
            break;
        else if ((n1<=0 || n2<=0 || n3<=0))
            ans = 1;
        else if((n1 >20 || n2>20 || n3 >20))
            ans = arr[20][20][20];
        else
            ans = arr[n1][n2][n3];
        
        cout<<"w("<<n1<<", "<<n2<<", "<<n3<<") = "<<ans<<'\n';
        
    }
}