#include <iostream>
#include<algorithm>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string name, value;
    map<string, string, greater<string>> m;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name >> value;
        if (value == "enter")
            m[name] = value;
        else
            m.erase(name);
    }

    for (auto it : m) {
        cout << it.first << "\n";
    }

    return 0;
}