#include <iostream>
#include <string>
using namespace std;

string board[10];

int main()
{
	for(int i=0; i<8; i++)
		cin >> board[i];
	bool flag = true;
	for(int i=0; i<8; i++)
		for(int j=0; j<7; j++)
			flag *= board[i][j] != board[i][j+1];
	cout << (flag ? "YES" : "NO") << endl;
	return 0;
}
