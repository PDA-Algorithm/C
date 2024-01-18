#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int N;
    cin >> N;
    stack<int> stack;

    for (int i = 0; i < N; i++) {

        string s;
        cin >> s; //명령 받음

        if (!s.compare("push")) { //push
            int num;
            cin >> num;
            stack.push(num);
        }
        else if (!s.compare("pop"))
        {
            if (stack.empty())
                cout << "-1" << endl;
            else {
                int t = stack.top();
                stack.pop();
                cout << t << endl;
            }
        }
        else if (!s.compare("size"))
        {
            cout << stack.size() << endl;
        }
        else if (!s.compare("empty")) {
            if (stack.empty())
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
        else if (!s.compare("top")) {
            if (stack.empty())
                cout << "-1" << endl;
            else
                cout << stack.top() << endl;
        }
    }

    return 0;
}
