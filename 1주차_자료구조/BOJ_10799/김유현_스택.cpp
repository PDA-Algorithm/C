#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
vector<int> v;

void push(int x)
{
    v.push_back(x);
}

int size()
{
    return v.size();
}

int top()
{
    if (size() == 0)
        return -1;
    return v[v.size()-1];
}

int pop()
{  
    if (size() == 0)
        return -1;

    int x = top();
    v.pop_back();
    return x;
}

bool empty()
{
    return (size() == 0);
}

void output(int x) 
{
    cout << x << '\n';
}

void solve(string cmd)
{
    int x;
    if (cmd == "push")
    {
        cin >> x;
        push(x);
    }
    else if (cmd == "pop")
    {
        output(pop());
    }
    else if (cmd == "size")
    {
        output(size());

    }
    else if (cmd == "empty")
    {
        output(empty());
    }
    else if (cmd == "top")
    {
        output(top());
    }
}

void input()
{
    cin >> N;

    string cmd;
    int x;
    for(int i=0; i<N; i++)
    {
        cin >> cmd;
        solve(cmd);
    }
}

int main() 
{
    input();

    return 0;
}