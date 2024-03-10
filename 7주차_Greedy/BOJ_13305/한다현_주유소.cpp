#include<iostream>

using namespace std;

int main(){
    int n;
    long long ans=0;
    long long road[100003];
    long long price[100003];

    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>road[i];
    }

    for(int i=0;i<n;i++){
        cin>>price[i];
    }

    long long min=price[0];
    ans+=price[0]*road[0];

    for(int i=1;i<n-1;i++){
        if(min>price[i]){
            min=price[i];
            
        }
        ans+=min*road[i];
       
    }

    cout<<ans;

}
