#include <iostream>
#include <stack>
#include <string>

using namespace std;

int N;
string str;
int result = 0;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(string str) 
{
    stack<char> s;

    for(char ch : str) 
    {
        if (!s.empty() && s.top() == ch) 
        {
            s.pop();
        }
        else 
        {
            s.push(ch);
        }      
    }
    
    if (s.empty()) 
    {
        result++;
    }
    
    return;
}

void output(string str)
{
    cout << result << '\n';
}

void input() 
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> str;
        solve(str);
    }

    output(str);
}

int main() 
{
    fastIO();
    input();

    return 0;
}
