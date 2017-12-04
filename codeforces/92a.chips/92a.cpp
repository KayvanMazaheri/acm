#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	long long k = (n * (n+1)) / 2;
	int s = m%k;
	for(int i=1; i<=n && (s-i) >= 0; i++ )
		s -= i;
	cout << s << endl;
	return 0;
}
