#include <iostream>
#include <string>
#include <deque>
using namespace std;

int n, k;
string str;
deque <char> deq;
int main() {
	int n, k;
	cin >> n >> k;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {

		while (k && !deq.empty() && deq.back() < str[i]) { 
			deq.pop_back();
			k--;
		}
		deq.push_back(str[i]);
	}


	for (int i = 0; i < deq.size() - k; i++) 
		cout << deq[i];

}
