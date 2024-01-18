#include<iostream>
#include<stack>

using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=0;
    
    for(int i=0;i<n;i++){
        stack<int> st;
        
        string s;
        cin>>s;
        
        for(int j=0;j<s.length();j++){
            if(st.empty()){
                st.push(s[j]);
               
            }
            
            else{
                char c;
                c=st.top();
                if(c==s[j]) {
                    st.pop();
                    //check=false;
                }
                else {
                    st.push(s[j]);
                }
            }
        }
        
        
        
        if(st.empty()) {
            ans++;
            
        }
        
        
    }
    cout<<ans;
}
