#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t,n,m,a,b,ans=0;
    vector<int> v[1001];
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        for(int j=0;j<m;j++){
            cin>>a>>b;
            
        }
        //모든 노드가 연결되어있음, 가중치가 없음 -> 최소스패닝트리, 최소스패닝트리의 조건: 간선의 개수가 노드개수-1
        cout<<n-1<<"\n";
    }
    return 0;
}
