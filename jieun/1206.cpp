#include<iostream>

using namespace std;
int h; //건물 높이
int w; //가로길이
int map[1001][256];
int visited[1001][256];
int cnt;
void init_map() {
	 	for (int i = 0; i < 1001; i++)
			for (int j = 0; j < 256; j++)
				map[i][j] = 0;
	
}
void init_visited() {
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 256; j++)
			visited[i][j] = 0;

}

void solve() {
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 256; j++) {
			if (map[i][j] == 1 && visited[i][j] == 0) { //map[][]값이 1이고 방문한적없으며
				if (map[i - 1][j] == 0 && map[i - 2][j] == 0 && map[i + 1][j] == 0 && map[i + 2][j] == 0) { //map의 2만큼 떨어져있는 값들이 다 0 이면
					cnt++;			// 갯수를 세준다.
					visited[i][j]=1; //방문표시!
				}
			}

		}
	}

}

int main() {


	for (int t = 1; t <= 10; t++)
	{
		init_map();
		cin >> w;
		for (int i = 0; i < w; i++) {  //w만큼 돌림 
			cin >> h;					//높이를 입력하고
			for (int j = 0; j < h; j++) { // 높이만큼 1으로 바꿔준다.
				map[i][j] = 1;
				
			}
		}
		cnt = 0;	
		init_visited();
		solve();


	
		cout << "#" << t << " "  <<cnt<< endl;

	}
	return 0;
}