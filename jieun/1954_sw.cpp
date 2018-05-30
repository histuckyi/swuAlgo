#include <iostream>

using namespace std;
int map[11][11];
int visited[11][11];
int num;
int dx[4] = { 0,1,0,-1 };// 0오  ,1아 , 2왼 , 3위 
int dy[4] = { 1,0,-1 ,0 };

int n;

void init_map() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			map[i][j] = 100;
		
		}
}
void init_visited() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;

		}
}
void solve(int x, int y, int dir)
{
	num++;

	if (map[x][y]==0 && visited[x][y] ==0)
	{
		x = x - dx[dir];
		y = y - dy[dir];
		dir = (dir + 1) % 4;
		
	
			if (num <= n * n) {
		
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				map[nx][ny] = num;
				visited[x][y] = 1;
			
				
			//		cout << map[nx][ny] << '\n';
				
			
				solve(nx+ dx[dir], ny+ dy[dir], dir);
				
			}
			
		

	
	} 
	else if(map[x][y] == 100&& visited[x][y] == 0)
	{
	
		if (num <= n * n) {

			map[x][y] = num;
			visited[x][y] = 1;
		
			solve(x + dx[dir], y + dy[dir], dir);

		}

	}

	else {
		if (num <= n * n) {
			x = x - dx[dir];
			y = y - dy[dir];
			dir = (dir + 1) % 4;
			

			if (num <= n * n) {

				int nx = x + dx[dir];
				int ny = y + dy[dir];
			
				map[nx][ny] = num;
				visited[x][y] = 1;
			

			//	cout << map[nx][ny] << '\n';
			solve(nx + dx[dir], ny + dy[dir], dir);
			}
		}
	}

}


int main()
{
	int testcase;
	
	cin >> testcase;
	for (int t = 1; t <= testcase; t++)
	{	
		cin >> n;

		cout << "#" << t<<" ";
		init_map();
		init_visited();
		num = 0; //숫자 초기화
		
		solve(0,0,0);
	
		
		for (int i = 0; i < n; i++) 
		{
			cout << '\n';

			for (int j = 0; j < n; j++)
			{
				cout << map[i][j]<<" ";
			}
			
		}
		cout << endl;
	}


}
