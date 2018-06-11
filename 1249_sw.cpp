#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;
int n;
int time_;
int map[101][101];
int visited[101][101];
int dx[] = { 1,-1,0,0 }; // 위 아 오 왼
int dy[] = { 0,0,1,-1 };
queue < pair < pair < int, int >, int> > q;

//int nx, ny;

void init_map() {
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			map[i][j] = 0;
}

void init_visited() {
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			visited[i][j] = 0;
}

void bfs() {
	
	q.push(make_pair(make_pair(0, 0), 0)); //  
	visited[0][0] = 1;

	while (!q.empty()) {
		
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cur_time= q.front().second;
		visited[x][y] = 1;
		q.pop();

		if (x == n - 1 && y == n - 1) {
			cout << "last" << '\n';
		//	cout << cur_time;
			time_ = min(cur_time, time_);
			continue;

		}

		//temp = 987654321;


		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (visited[nx][ny] == 0 ) { //map nxny값이 최솟값time과 같으면?
				//	visited[nx][ny] = 1;
					q.push(make_pair(make_pair(nx, ny),cur_time+ map[nx][ny])); //push 해라
					cout << "nx" << nx << " ny" << ny << '\n';
					cout << cur_time + map[nx][ny] <<'\n';

				}//if
			}//if

		
		}//for
		

	}//while
	
} //bfs


int main() {
	int testcase;

	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		init_visited();
			init_map();

		cin >> n;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf_s("%1d", &map[i][j]);

		time_ = 987654321;
		bfs();
		cout << "# " << t << " " << time_ << endl;

	
	
	}
	return 0;
}