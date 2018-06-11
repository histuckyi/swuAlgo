#include<iostream>
using namespace std;

int money[8];

int main() {
	int n;
	int testcase;
	cin >> testcase;

	for (int t = 1; t <= testcase; t++) {
		
		cin >> n;
		cout << "#" << t<<'\n';

		money[0] = n / 50000;
		n = n % 50000;
		money[1] = n / 10000;
		n = n % 10000;
		money[2] = n / 5000;
		n = n % 5000;
		money[3] = n / 1000;
		n = n % 1000;
		money[4] = n / 500;
		n = n % 500;
		money[5] = n / 100;
		n = n % 100; 
		money[6] = n / 50;
		n = n % 50;
		money[7] = n / 10;
		n = n % 10;



		for (int i = 0; i <= 7; i++) 
		cout <<money[i]<<" ";


		cout << endl;
	}
}