#include<iostream>
#include<vector>
#include <algorithm>


#define SWAP(a,b)  {int t; t = a; a=b; b=t;}//a와 b를 교환

using namespace std;

vector<int> v;
int tmp[6]; int tmp2[6];
int n, r;
int ans;
int num_;
int cnt;
int result;
int maxNum;
int minNum;
int count_,maxN;


void make() {
	v.clear();

	num_ = n / 100000;
	v.push_back(num_);

	n = n - (num_ * 100000);
	num_ = n / 10000;
	v.push_back(num_);

	n = n - (num_ * 10000);
	num_ = n / 1000;
	v.push_back(num_);

	n = n - (num_ * 1000);
	num_ = n / 100;
	v.push_back(num_);

	n = n - (num_ * 100);
	num_ = n / 10;
	v.push_back(num_);

	n = n - (num_ * 10);
	num_ = n / 1;
	v.push_back(num_);
	// 나눠서 배열에 저장 

	for (int ii = 0; ii < v.size(); ii++) {
		tmp[ii] = v[ii]; //초기화
	}

	for (int ii = 0; ii < v.size(); ii++) {
		tmp2[ii] = tmp[ii]; //초기화
	}

}


void MaxCount() {// 최댓값 몇개 있는지 세기
	count_ = 0;
	maxNum = 0;
	minNum = 987654321;
	for (int m = (v.size() - cnt); m < v.size(); m++) {
		maxNum = max(maxNum, tmp[m]);
		minNum = min(minNum, tmp[m]);
	}
	
	for (int m = (v.size() - cnt); m < v.size(); m++)
		if (tmp[m] == maxNum)
			count_++;
	
}

void solve() {

		for (int i = (6 - cnt); i <6; i++) {
			for (int j = 5; j >(6 - cnt - 1); j--) {

				if (count_ < 3) { // 최댓값 똑같은 숫자가 3개 미만일때 for문을 돌렸을때 제일 큰 값을 리턴한다.
					if (i != j) {		
						SWAP(tmp[i], tmp[j])
							result = tmp[0] * 100000 + tmp[1] * 10000 + tmp[2] * 1000 + tmp[3] * 100 + tmp[4] * 10 + tmp[5] * 1;
						if (ans < result)
							ans = result;
						n = ans;
						for (int ii = 0; ii < v.size(); ii++)
							tmp[ii] = tmp2[ii]; //tmp돌린값 초기화 다시 for문을 돌렸을때 원래값에서 변화해야 한다.

					

					}
				}else if (count_ >= 3) {
					if (i != j && maxNum == tmp[j] && minNum == tmp[i]) { //i는 앞에서부터 j는 뒤에서부터 살피면서 ,, 제일작은수가 있는자리와 제일 큰 수가 있는자리를 바꾼다
						SWAP(tmp[i], tmp[j])
							result = tmp[0] * 100000 + tmp[1] * 10000 + tmp[2] * 1000 + tmp[3] * 100 + tmp[4] * 10 + tmp[5] * 1;
							n = result;
							ans = result;		
						
					}

				break; // else if 문이 끝나면 다시 for문이 돌면안됨 
				}
				
			}
		}

	
}

int main() {
	int testcase;
	cin >> testcase;


	for (int t = 1; t <= testcase; t++) {
		cin >> n >> r;
		ans = n;
		make(); //맨 처음 초기화
		MaxCount();//최댓값 개수 세기
	
		cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			if (tmp[i] != 0)
				cnt++;

		} //몇자리 숫자인가? 배열을 6개를 선언해주었기 때문에 088832인경우 0이상의 숫자를 세주어야한다.

		
		//===============================================================// n이 최댓값일때 ?
			int sorttmp[6];
		for (int ii = 0; ii < v.size(); ii++) {
			sorttmp[ii] = v[ii]; //초기화
		}
		sort(sorttmp, sorttmp+6);
		
		maxN= sorttmp[5] * 100000 + sorttmp[4] * 10000 + sorttmp[3] * 1000 + sorttmp[2] * 100 + sorttmp[1] * 10 + sorttmp[0] * 1;
		
		//===============================================================
		


	
		for (int rr = 0; rr < r; rr++) { //몇번 숫자를 바꾸나?
			
			if (maxN == ans && count_ >= 2)  //겹치는 숫자가 2개 이상이고, 최댓값이면 그대로 출력
				break;
			
			solve();
		
			if (ans == maxN && (r - rr) % 2 == 1 ) { //남은 돌릴횟수가 홀수이고 , 이미 최댓값이면 맨끝자리 바꿔줌
				ans = tmp[0] * 100000 + tmp[1] * 10000 + tmp[2] * 1000 + tmp[3] * 100 + tmp[5] * 10 + tmp[4] * 1;

				break;
			}

			count_ = 0; //count값을 

			make(); // n을 배열에 넣는다.
		}
		cout << "#" << t << " " << ans << endl;;
		


	}
	}