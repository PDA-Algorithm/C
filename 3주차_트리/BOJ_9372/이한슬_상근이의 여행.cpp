#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int TC, N, M;
	cin >> TC;
	for (int t = 0; t < TC; t++) {
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
		}
		printf("%d\n", N - 1);
	}
	
	return 0;
}