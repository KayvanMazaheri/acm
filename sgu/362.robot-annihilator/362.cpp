#include <iostream>
using namespace std;

int main()
{
    char map[12][12];
	int m, n;
	int i, j;
	string result;
	cin >> m >> n >> i >> j;
	for (int k=0; k<12; k++)
		for(int t=0; t<12; t++)
			map[k][t] = '-';
	for(int k=0; k<m; k++)
		for(int t=0; t<n; t++)
			map[k+1][t+1] = '0';
	while(1)
	{
		cerr << i << " " << j << endl ;
		map[i][j] = '2';
		if (map[i+1][j] == '0')
		{
			i++;
			result += 'D';
		}
		else if (map[i][j-1] == '0')
		{
			j--;
			result += 'L';
		}
		else if (map[i-1][j] == '0')
		{
			i--;
			result += 'U';
		}
		else if (map[i][j+1] == '0')
		{
			j++;
			result += 'R';
		}
		else
			break;
	}
	cout << result << endl;
	return 0;
}
