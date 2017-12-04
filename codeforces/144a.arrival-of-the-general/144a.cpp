#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int squad[n];
	for(int i=0; i<n; i++)
		cin >> squad[i] ;
	int max = *max_element(squad,squad+n) ;
	int min = *min_element(squad,squad+n) ;
	int min_index = 0;
	int max_index = 0;
	for (int i=0; i<n; i++)
	{
		if (squad[i] == max)
		{
			max_index = i ;
			break ;
		}
	}
	for (int i=n-1; i>=0; i--)
	{
		if (squad[i] == min)
		{
			min_index = i;
			break ;
		}
	}
	int result = n - min_index ;
	if (max_index > min_index)
		max_index -- ;
	result += max_index ;
	cout << result -1 << endl ;
	return 0;
}
