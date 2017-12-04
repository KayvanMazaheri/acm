#include <iostream>
using namespace std;

int main()
{
	int k, l;
	cin >> k >> l;

	int i=0;
	for(i=0; l>1; i++)
	{
		if(l%k)
		{
			cout << "NO" << endl;
			return 0;
		}
		l/=k;
	}
	cout << "YES" << endl;
	cout << i-1 << endl;
	return 0;
}
