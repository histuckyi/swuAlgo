// 부분수열의 합
//백트래킹사용 
#include<iostream>
#include<vector>

using namespace std;
int n,k,aa; 
int a[100],visitedTop[100],visited[100];
vector <int> v;
int cnt;

void solve(int index, int sum) {
	if (index >= n) //만약에 n번보다 많은 횟수면 
		return; //끝내기  ..그러면 백트래킹으로 뒤로 돌아간다.
	if (sum > k) // 다 합친값이 k보다 크면 
		return; // 끝내기
	if (sum == k) { // 합이 k와 같다면?
		cnt++; // cnt 1더해줌
		return; // 끝
	}
	if (sum < k) { //k보다 작으면  ?
		for (int i = index + 1; i < n; i++)
			solve(i,sum+a[i]); // 재귀로 돌리기 
			//-> 재귀로 돌리면 함수가 다 끝나지 않은상태에서 계속 돌아가기때문에 
		    //나중에 return 을 하면 다시 백트래킹으로 전에 있던 값으로 돌아간다.
	}

}

int main() {
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		cnt = 0;
		cin >> n >> k;
		
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		solve(-1,0);
		cout << "#" << t << " " << cnt << endl;

	}
}