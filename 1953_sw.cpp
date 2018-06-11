#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int check[51][51];
int map[51][51];
// 위 아 왼 오
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int n, m, r, c, l;
vector <int> v[8];
int cnt;

bool Possible(int dir, int type) {
	if (dir == 0) {
		if (type == 1 || type == 2 || type == 5 || type == 6)
			return true;
	}
	else if (dir == 1) {
		if (type == 1 || type == 2 || type == 4 || type == 7)
			return true;
	}
	else if (dir == 2) {
		if (type == 1 || type == 3 || type == 4 || type == 5)
			return true;

	}
	else
		if (type == 1 || type == 3 || type == 6 || type == 7)
			return true;

	return false;
}
void solve(int x, int y, int time)
{
	//  
	if (time == l - 1)
		return;
	check[x][y] = time;
	int temp = map[x][y];
	for (int i = 1; i <= 7; i++) {
		if (temp == i) {
			for (int j = 0; j < (int)v[i].size(); j++) {
				int k = v[i][j];
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (0 <= nx && nx < n && 0 <= ny && ny < m) {
					if (Possible(k, map[nx][ny])) {
						check[nx][ny] = time + 1;
						solve(nx, ny, time + 1);
					}
				}
			}
		}
	}//이동
}


int main() {
	int testcase;

	cin >> testcase;

	for (int k = 0; k<4; k++)
		v[1].push_back(k);


	v[2].push_back(0);
	v[2].push_back(1);

	v[3].push_back(2);
	v[3].push_back(3);

	v[4].push_back(0);
	v[4].push_back(3);

	v[5].push_back(1);
	v[5].push_back(3);

	v[6].push_back(1);
	v[6].push_back(2);

	v[7].push_back(0);
	v[7].push_back(2);

	for (int t = 1; t <= testcase; t++) {

		cin >> n >> m >> r >> c >> l;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf_s("%1d", &map[i][j]);
				check[i][j] = 31;
			}
		}

		solve(r, c, 0);
		int ans = 0;
		for (int i = 0; i<n; i++)
			for (int j = 0; j<m; j++)
				if (check[i][j] != 31)
					ans++;
		if (l == 1)
			ans = 1;

		cout << "# " << t << " " << ans << endl;



	}
	return 0;
}