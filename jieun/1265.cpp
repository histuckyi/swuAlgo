#include<iostream>
using namespace std;

int n, p;
int a, b;

int main() {
	int testcase;
	cin >> testcase;

	for (int t = 1; t <= testcase; t++) {
		long long result = 1;
		cin >> n >> p;
		a = n / p;
		b = n % p;
		for (int i = 0; i <(p - b); i++) 
			result = result * a;
	
		for (int i = 0; i < b; i++) 
			result = result * (a + 1);

		cout <<"#" << t <<" "<< result << endl;
	}
}