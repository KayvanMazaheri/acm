#include <iostream>
using namespace std;

struct page
{
	int num ;
	int size;
};
int main()
{
	int K, N;
	page dir[10];
	cin >> K >> N;
	for (int c=0; c<10; c++)
	{
		dir[c].num = 0;
		dir[c].size = 0;
	}

	int tel ;
	for(int i=0; i<N; i++)
	{
		cin >> tel ;
		tel /= 1000 ;
		if ((tel != 8)&&(tel != 0))
		{
			if(dir[tel].num > 0)
			{
				dir[tel].num --;
			}
			else
			{
				dir[tel].num = K-1;
				dir[tel].size ++;
			}
		}
	}
	int sum = 0;
	for (int i=0; i<10; i++)
		sum += dir[i].size;

	cout << sum+2 ;
	return 0;
}
