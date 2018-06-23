#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int map[1001][1001];
int visited[1001][1001];
int n, first_num,cnt_result;
queue < pair < pair < int, int >, int > > q;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
vector <int> vfirst;
vector <int> vcnt;
void bfs(int x,int y) {
	q.push(make_pair(make_pair(x, y), 1));
	
	//cout << "map"<<map[x][y]<<'\n';
	visited[x][y] = 1;
	//cnt_result = 0;
	int vfirst_ = map[x][y]; 
	// 처음 맵의 값을 vfirst_에 넣는다. (다음수가 1이 클때는 이값이 정답 그러나 다음수가 -1일때는 마지막값이 정답)
	while (!q.empty()) {
	
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cnt = q.front().second;

		q.pop();
		
		for (int i = 0; i < 4; i++) {
			
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if (nx >= 0 && ny >= 0 && nx < n&&ny < n) {
				if (map[nx][ny] == map[cx][cy] + 1 && visited[nx][ny] == 0) { //1이 더많을때
					visited[nx][ny] = 1;
					q.push(make_pair(make_pair(nx, ny), ++cnt));			
				
			
					
				}
				else if (map[nx][ny] == map[cx][cy] - 1 && visited[nx][ny] == 0) { //1이 더적을때
					visited[nx][ny] = 1;
					q.push(make_pair(make_pair(nx, ny), ++cnt));
				
					if (vfirst_ > map[nx][ny]) // 이동할 수가 1이 작다면 다음수(마지막수)가 제일 작다.
						vfirst_ = map[nx][ny];
				
				}
				
			}
			if (cnt_result < cnt)
				cnt_result = cnt;
			//cnt수가 제일 큰것 
		} 
		
		
	}
	vfirst.push_back(vfirst_);
	//vfirst_값을 vector 에 넣는다.
}
int main() {
	int testcase;
	cin >> testcase;

	for (int t = 1; t <= testcase; t++) {
		cin >> n;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				map[i][j] = 0; //초기화

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			} //map 입력
		}


		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				visited[i][j] = 0;//초기화

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == 0)
					cnt_result = 0;//초기화
					bfs(i, j);
					vcnt.push_back(cnt_result); // cnt값 vector에 넣는다.
			}
		}

		int max = 0; //초기화
		int min = 987654321; //초기화
		
		for (int i = 0; i < vcnt.size(); i++) {
		if (vcnt[i] > max) {
			max = vcnt[i];
		} //vector vcnt 값중 cnt 최댓값 넣기

		}

		for (int i = 0; i < vfirst.size(); i++) {
			if (vcnt[i] == max)
			{				
				if (vfirst[i] < min)
					min = vfirst[i];
			}
		} //vector vfirst 값중에서 max값과 같은값중 제일 최솟값 넣기


		cout << "#" << t << " " <<min <<" " <<max <<endl;

		vcnt.clear(); 
		vfirst.clear();  //vector값 다 지우기

	}

}