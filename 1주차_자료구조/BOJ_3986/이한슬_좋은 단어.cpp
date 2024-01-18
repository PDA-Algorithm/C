#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    int N; int cnt = 0;
    cin >> N;

    for (int i = 0; i < N; i++) //�ܾ� ����
    {
        stack<char> s;
        string w;
        cin >> w; //A,B �����Է�

        for (int j = 0; j < w.size(); j++)
        {
            if (s.empty()) //stack ��������ϱ� �ϴ� �־�
                s.push(w[j]);
            else
            {
                if (s.top() == w[j])
                    s.pop();
                else
                    s.push(w[j]);
            }
        }

        if (s.empty()) //�� ¦�������� ������� �����ܾ�
            cnt++;
    }
    cout << cnt << endl;

    return 0;
}
