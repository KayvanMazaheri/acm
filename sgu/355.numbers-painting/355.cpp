#include <iostream>
using namespace std;

int main()
{
	int n, max = 0;
	cin >> n ;
	if (n == 1)
	{
		cout << 1 << endl << 1 << endl ;
		return 0;
	}
	int numbers[n] ;
	for (int i=0; i<n; i++)
		numbers[i] = 1 ;
	for (int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if (((j+1) % (i+1) == 0) && (numbers[i] == numbers[j]))
			{
				numbers[j] ++ ;
				if (numbers[j] > max)
					max = numbers[j] ;
			}
	cout << max << endl ;
	for (int i=0; i<n; i++)
		cout << numbers[i] << " " ;
	cout << endl;
	return 0;
}
