#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2e4 + 123;

int arr[MAXN];
vector <long long> vec;

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	for(int i=1; i<= n/3; i++)
	{
		//cerr << 1 << endl;
		if ( i && n%i)
			continue;
		for(int j=0; j<i; j++)
		{
			long long sum = 0;
			for(int k=j; k<n; k+=i)
				sum+= arr[k];
			vec.push_back(sum);
		}
	}
	sort(vec.begin(), vec.end());
	cout << vec[vec.size()-1] << endl;

	return 0;
}
