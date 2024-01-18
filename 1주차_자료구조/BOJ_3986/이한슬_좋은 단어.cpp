#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    int N; int cnt = 0;
    cin >> N;

    for (int i = 0; i < N; i++) //단어 개수
    {
        stack<char> s;
        string w;
        cin >> w; //A,B 문장입력

        for (int j = 0; j < w.size(); j++)
        {
            if (s.empty()) //stack 비어있으니까 일단 넣어
                s.push(w[j]);
            else
            {
                if (s.top() == w[j])
                    s.pop();
                else
                    s.push(w[j]);
            }
        }

        if (s.empty()) //다 짝지어져서 비워지면 좋은단어
            cnt++;
    }
    cout << cnt << endl;

    return 0;
}
