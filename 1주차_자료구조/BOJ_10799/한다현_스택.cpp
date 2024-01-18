#include<iostream>
#include<stack>

using namespace std;

int main(){
    string s;
    stack<char> st;
    long long ans=0;
    cin>>s;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]=='('&&s[i+1]==')') {
            ans+=st.size();
            //cout<<s[i]<<" "<<ans<<endl;
            i++;
        }
        else if(s[i]=='(') st.push('(');
        else{
            ans++;
            //cout<<s[i]<<" "<<ans<<endl;
            if(!st.empty())
                st.pop();
        }
        
    }
    
    if(s[s.length()-1]==')'&&s[s.length()-2]!='(')
        ans+=1;
    
    cout<<ans;
}
