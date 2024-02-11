#include <iostream>
#include <vector>
using namespace std;

int T[15];
int P[15];
int N;
int maxmoney= 0;

void sol(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}
	sol(0, 0);
	cout << maxmoney << endl;

	return 0;
}

void sol(int len, int sum) {
	if (len > N)
		return;
	maxmoney = max(sum, maxmoney);
	for (int i = len; i < N; i++) {
		sol(T[i] + i, sum + P[i]);
	}
}