//2814 최장경로
//초기화 조심
#include<iostream>

using namespace std;
int n, m;
int x, y;
int cnt,result;
int visited[21];
int map[21][21];

void init_map() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			map[i][j] = 0;
}
void init_visited() {
	for (int i = 1; i <= n; i++)
		visited[i] = 0;

}

void solve(int start) {
	if (result < cnt)
		result = cnt;

	for (int j = 1; j <= n; j++) {
		if (map[start][j] == 1 && visited[j] ==0)
		{
			visited[j] = 1;
			cnt++;
			solve(j);
			cnt--;
			visited[j] = 0;
	
		}		
	}
	
		
	
}
int main(){
	init_map();
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++)
	{
		cin >> n >> m;
		for (int i = 1; i <= m; i++) 
		{
			cin >> x >> y;
			map[x][y] = 1;
			map[y][x] = 1;
		}
	

		result = 0;
		
		for (int i = 0; i < n; i++) {
			cnt = 1;
			init_visited();
			visited[i] = 1;
			solve(i);
		}
			
		init_map();

		cout << "#" << t << " "<< result<<endl;
	}

}