#include<iostream>
#include<vector>
using namespace std;
int n;
int map[10][10];
int ans1[10][10];
int ans2[10][10];
int ans3[10][10];
int cnt;
vector <int> v;
void init_map() {

	for (int i = 0; i < 10; i++) 
		for (int j = 0; j < 10; j++)
			map[i][j] = 0;
	

}
void init_ans() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			ans1[i][j] = 0;
			ans2[i][j] = 0;
			ans3[i][j] = 0;
		}
	}
}	

void solve_90(int y) {

	if (y < 0) {
		return;
	}

		for (int i = 0; i < n; i++) {
			ans1[i][y] = v[i+cnt];
		}
		cnt= cnt + n;
		solve_90(y - 1);
}

void solve_180(int  x) {

	if (x < 0) {

		return;
	}

	for (int i = n - 1; i >= 0; i--) {
		ans2[x][i] = v[n - 1 -i + cnt];
		
	}
	cnt = cnt + n;
	solve_180(x-1);

}
void solve_270(int y) {

	if (y >n - 1) {

		return;
	}

	for (int i = n - 1; i >= 0; i--) {
		ans3[i][y] = v[n - 1 -i + cnt];
	}
	cnt = cnt + n;
	solve_270(y + 1);
}
int main() {
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		v.clear();
		init_map();
		init_ans();
		cin >> n;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cin >> map[i][j]; 
				}
			}
		

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					v.push_back(map[i][j]);

	

			cout <<'\n'<< "#" << t;
			cnt = 0;
			solve_90(n-1);

			cnt = 0;
			solve_180(n-1);

			cnt = 0;
			solve_270(0);

			for (int i = 0; i < n; i++) {
				cout << '\n';
				for (int j = 0; j < n; j++) {
					cout << ans1[i][j];
				}
			cout << " ";
				for (int j = 0; j < n; j++) {
					cout << ans2[i][j];
				}
			cout << " ";
				for (int j = 0; j < n; j++) {
					cout << ans3[i][j];
				}
				}
			
	}
}