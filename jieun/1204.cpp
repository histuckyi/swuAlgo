#include<iostream>

using namespace std;
int n;
int num[1001];
int solve() {
	int num_ = 0;
	int max = 0;
	for (int i = 0; i <= 1000; i++) {
		if (max <= num[i]) {
			max = num[i];
			num_ = i;
		}
	}
	return num_;
}
int main() {
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++)
	{
		cin >> t;
		for (int i = 0; i <= 1000; i++)
			num[i] = 0; // 초기화
		for (int i = 0; i < 1000; i++) {
			cin >> n; // n입력
			num[n]++;
		}
		
		cout << "#"<< t <<" " <<solve()<< endl;

	}
	return 0;
}