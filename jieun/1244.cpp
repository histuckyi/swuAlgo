#include<iostream>
#include<vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
vector<int> v;
int n, r;
int num_; 
int cnt;
int result;
int temp;
int main() {
	int testcase;
	cin >> testcase;
	

	for (int t = 1; t <= testcase; t++) {
		cin >> n >> r;

		for(int rr=0;rr<r;rr++){
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

			cnt = 0;
			for (int i = 0; i < v.size(); i++) {
				if (v[i] != 0)
					cnt++;
				
			}
		
			for (int i = (v.size() - cnt); i < v.size(); i++) {
				for (int j = (v.size() - cnt); j < v.size(); j++) {
					if (i != j) {
						temp=0;
						temp = v[i];
						v[i] = v[j];
						v[j] = temp;

					//	for (int i = 0; i < v.size(); i++) {
					//		cout << v[i];
					//	}
					//	cout << '\n' << n;
						result = v[0] * 100000 + v[1] * 10000 + v[2] * 1000 + v[3] * 100 + v[4] * 10 + v[5] * 1;
						if (n<result)
							n= result;

					}



				}
			}
		}

		cout << "#" << t << " " << n << endl;
	}
}