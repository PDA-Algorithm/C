#include <iostream>

using namespace std;

int sticker[2][100001];
int dp[2][100001];

int main()
{
	ios::sync_with_stdio(false);    
	cin.tie(NULL);

	int T, n;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		cin >> n;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> sticker[i][j]; //스티커 입력 
			}
		}
		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];
		dp[0][1] = dp[1][0] + sticker[0][1];
		dp[1][1] = dp[0][0] + sticker[1][1]; // 초기값 설정

		for (int i = 2; i < n; i++) {
			dp[0][i] = sticker[0][i] + max(dp[1][i - 1], dp[1][i-2]);
			dp[1][i] = sticker[1][i] + max(dp[0][i - 1], dp[0][i-2]);
		}

		if (dp[1][n - 1] > dp[0][n - 1]) {
			cout << dp[1][n - 1] <<endl;
		}
		else {
			cout << dp[0][n - 1] << endl;
		}
	}

	return 0;
}