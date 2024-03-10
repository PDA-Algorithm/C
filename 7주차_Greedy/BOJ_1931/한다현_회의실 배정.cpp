#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

bool cmp(const pair<int,int> a,const pair<int,int> b){
    if(a.first==b.first){
       return a.second<b.second;
    }
    return a.first<b.first;
}

int main(){
    int n;
    int ans=1;
    cin>>n;
    vector<pair<int,int>> v;
    int a,b;

    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(),v.end(),cmp);

    int start=v[n-1].first;

    for(int i=n-2;i>=0;i--){
        if(v[i].second<=start){
            start=v[i].first;
            ans++;
        }
    }

    cout<<ans;
}
