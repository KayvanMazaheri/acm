// In the name of God
// SGU, Problem Number 296
// Saha vs. Kate
// Solution : Greedy

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int max(int begin, int end);

string n;

int main()
{
	int k;
	cin >> n >> k;
	string result = "";
	int begin = 0;
	int end = n.size();
	k = end - k;
	int maximum ;
	for (int i=0; i < k; i++)
	{
		//cerr << i << endl ;
		maximum = max (begin, end-(k-i-1));
		begin = maximum + 1 ;
		result = result + char(n[maximum]) ;
	}
	cout << result << endl ;
	return 0;
}

int max(int begin, int end)
{
	int MAX = begin ;
	for (int i=begin; i<end; i++)
	{
		if (n[i] > n[MAX])
			MAX = i;
	}
	return MAX ;
}
