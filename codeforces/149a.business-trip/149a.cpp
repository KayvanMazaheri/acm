#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool mark[12] ;

int main()
{
	int k;
	cin >> k;
	int month[12];
	for (int i=0; i<12; i++)
		cin >> month[i];
	int s = 0;
	int free = 12 ;

	while (k > 0 && free > 0)
	{
		pair<int, int> maxM;
		maxM.first = 12;
		maxM.second = 0;
		for (int i=0; i<12; i++){
			if (month[i] > maxM.second && mark[i] == false)
			{
				maxM.first = i;
				maxM.second = month[i];
			}
		}
		mark[maxM.first] = true ;
		free -- ;
		k -= maxM.second;
		s ++ ;
	}
	if (k > 0 && free < 1)
		s = -1 ;
	cout << s << endl ;

	return 0;
}
