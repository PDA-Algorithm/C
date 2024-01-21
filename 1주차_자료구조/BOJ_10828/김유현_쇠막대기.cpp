#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int solve(string str) 
{
    stack<char> s;
    char left = '(';
    char right = ')';

    int result = 0;

    for(int i=0; i<str.length(); i++)
    {      

        if (str[i] == left) 
        {
            s.push(str[i]);
        }
        else if (str[i] == right)
        {
            if (str[i-1] == left) // 레이저
            {
                s.pop();
                result += s.size();
            }
            else if (str[i-1] == right) // 쇠막대기
            {
                s.pop();
                result++;
            }
        }

    }

    return result;
}

void output(string str)
{
    cout << solve(str) << '\n';
}

void input() 
{
    cin >> str;
    output(str);
}

int main() 
{
    fastIO();
    input();

    return 0;
}
