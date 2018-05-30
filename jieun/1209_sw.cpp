#include <iostream>
#include<algorithm>
using namespace std;
int map[100][100];


int dx[4] = { 0,1,0,-1 };// 0오  ,1아 , 2왼 , 3위 
int dy[4] = { 1,0,-1 ,0 };
int dia0, dia1, dia2;
int n;
int col1, temp;
int row1;
int _max[3];
void init_map() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			map[i][j] = 0;

		}
}

void col(int y) //열
{
	
	temp = 0;
	if (y < n) {
		for (int i = 0; i < n; i++)
		{
			temp += map[i][y];
			
		}
		if (col1 < temp) {
			col1 = temp;
		
		}

		y++;
		col(y);
		
	}
	_max[0] = col1;

	
}
void row(int x)//행
{

	//row1 = 0;
	temp = 0;
	if (x < n) {
		for (int j = 0; j < n; j++)
		{
			temp += map[x][j];
			
			}
		if (row1 < temp) {
			row1 = temp;
	
		}
		x++;
		
		row(x);
	}
	_max[1] = row1;
	
}
void dia ()//대각
{
	dia0 = 0;
	dia1 = 0; dia2 = 0;
	for (int i = 0; i < n; i++){
	//	cout << "1=======" << '\n';
		 dia1 += map[i][i];
		 dia2 += map[i][n - 1 - i];
		}

	
	if (dia1 < dia2) 
		dia0 = dia2;

	else
		dia0 = dia1;

	_max[2] = dia0;
	//cout <<":"<< _max[2];
//	cout << "2=======" << '\n';
}
int main()
{
	int testcase;
	int maxx;
	
	n =100;
	for (int t = 1; t <= 10; t++)
	{
		cin >> t;
		init_map();

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}

		
		cout << "#" << t << " ";
		col1 = 0;
		row1 = 0;
		col(0); row(0); dia();
		maxx = 0;

		for (int i = 0; i < 3; i++) {
			
			if (_max[i]>maxx)
				maxx = _max[i];
			
		}
		cout << _max[0] << _max[1] << _max[2] << '\n';
		cout<< maxx << endl;
	}


}
