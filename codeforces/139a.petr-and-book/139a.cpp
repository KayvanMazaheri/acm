// In the name of God
// Code Forces Contest
// Problem 1
// Solution : ...

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void input();

long long n;
long long week[8];

int main()
{
	input();
	long long day = 1;
	while(n>0)
	{
		n -= week[day];
		if (n>0)
			day++ ;
		if (day == 8)
			day = 1;
	}
	cout << day  << endl ;
	return 0;
}

void input()
{
	cin >> n;
	for (int i=1; i<8; i++)
		cin >> week[i];
	return ;
}
