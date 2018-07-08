//1249 보급로
//using 다익스트라
#include<iostream>
#include<queue>
#define MAX 987654321;

using namespace std;
int n;
int map[101][101];
int map2[101][101];
int dx[] = {0,-1 ,1,0 }; // 위 아 오 왼
int dy[] = {-1,0, 0,1 };
queue < pair < pair < int, int >, int> > q;

void init_map() {
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			map[i][j] = 0;
}
void init_map2() {
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			map2[i][j] = MAX;
}


void solve() { //대각선 방향으로 보면서 숫자를 더해나감 , 겹치는 부분은 더 작은값을 집어넣음

	q.push(make_pair(make_pair(0, 0), 0)); 


	while (!q.empty()) {

		int x = q.front().first.first;
		int y = q.front().first.second;
		int cur_time = q.front().second;

		q.pop();
		if (cur_time > map2[x][y])
			continue;

	

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int time = map[nx][ny];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (cur_time+time<map2[nx][ny]) { //map2에 있는 값이 curtime + time 보다 크면? curtime+time을 집어넣는다.
					map2[nx][ny] = cur_time + time; //map2값에 지금까지 시간고 + map에 있는 시간을 합한것을 집어넣는다.
					q.push(make_pair(make_pair(nx, ny), map2[nx][ny])); //push 해라

				}
			}
		}//for
	}//while
}


int main() {
	int testcase;

	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {

		init_map();

		cin >> n;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf_s("%1d", &map[i][j]);

		init_map2();
		solve();
		cout << "#" << t << " " << map2[n-1][n-1] << endl;



	}
	return 0;
}