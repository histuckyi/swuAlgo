#include<iostream>

using namespace std;
int map[101][101];
int x, y;
int visited[101][101];
int dy[4] = { 0,1,-1 }; // up0  right1 left2
int dx[4] = { -1,0,0 };

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

void solve() {
	//cout << "-";
	if (map[x + dx[1]][y + dy[1]] == 1&&visited[x + dx[1]][y + dy[1]]==0) {
//		cout << "+";
		x = x + dx[1];
		y = y + dy[1];
		visited[x][y] = 1;
		solve();
	}
	else if (map[x + dx[2]][y + dy[2]] == 1&& visited[x + dx[2]][y + dy[2]] == 0) {
	//	cout << "=";
		x = x + dx[2];
		y = y + dy[2];
		visited[x][y] = 1;
		solve();
	}
	else if(map[x+dx[0]][y+dy[0]] == 1&& visited[x + dx[0]][y + dy[0]] == 0){
	//	cout << "_";
		x = x + dx[0];
		y = y + dy[0];
		visited[x][y] = 1;
			solve();
	}


	//cout << "*";
}
int main() {
	
	for (int t = 1; t <= 10; t++)
	{

		cin >> t;
		init_visited();
	//	init_map();
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
		
		if (map[i][j] == 2) {
			x = i;
			y = j;
		}
			}
		}
		solve();

		cout << "#" << t << " " << y << endl;;
	}
}
