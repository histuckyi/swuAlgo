//N-Queen 2806

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
int a[13];
int map[10][10];
int visited[10][10];
int count_;

bool check(int cnt) {
	for (int i = 0; i < cnt; i++) {
		if (a[i] == a[cnt] || (cnt - i) == std::abs(a[cnt]-a[i])) {
			return false;
		}
	}
	return true;
}
void solve(int cnt) {
	if (cnt == n - 1) {
		count_++;
		return;
	}
	for (int i = 0; i < n; i++) {
	
		a[cnt + 1] = i;
		if (check(cnt + 1)) {
			solve(cnt + 1);
		}
	}
}
int main() {
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		count_ = 0;
		cin >> n;
	
		solve(-1);

		cout << "#" << t << " " << count_;

	}
}