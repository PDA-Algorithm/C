#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>

using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

pair<int, vector<pair<int, int>>> input() {
    int N, M;
    cin >> N;

    vector<pair<int, int>> problems;
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        int problem, level;
        cin >> problem >> level;
        problems.push_back({level, problem});
        m[problem] = level;
    }

    cin >> M;

    return {M, problems};
}

vector<int> solve(int M, const vector<pair<int, int>>& problems) {
    set<pair<int, int>> s;
    map<int, int> m;

    vector<int> results;
    while (M--) {
        string input;
        cin >> input;

        if (input == "recommend") {
            int order;
            cin >> order;
            if (order == 1) {
                auto it = s.rbegin();  // set 맨 뒤에 있는 문제
                results.push_back(it->second);
            } else {
                auto it = s.begin();  // 가장 앞에 있는 문제
                results.push_back(it->second);
            }
        } else if (input == "add") {
            int problem, level;
            cin >> problem >> level;
            s.insert({level, problem});
            m[problem] = level;
        } else {
            int problem;
            cin >> problem;
            // 문제 번호를 키로 난이도를 구함
            s.erase({m[problem], problem});
        }
    }

    return results;
}

void output(const vector<int>& results) {
    // 최종 결과 출력
    for (int i : results) {
        cout << i << '\n';
    }
}

int main() {
    fastIO();

    // 입력 받아오기
    auto [M, problems] = input();

    // 각 쿼리 해결 및 결과 출력
    vector<int> results = solve(M, problems);
    output(results);

    return 0;
}
