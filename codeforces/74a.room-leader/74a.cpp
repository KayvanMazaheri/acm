#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 5e1 + 123;

pair <long long, string> contestants[MAXN];

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int plus, minus, a, b, c, d, e;
		string handle;
		cin >> handle >> plus >> minus >> a >> b >> c >> d >> e;
		contestants[i] = make_pair((plus * 100 - minus * 50 + a + b + c + d + e), handle);
	}
	sort(contestants, contestants+n);
	cout << contestants[n-1].second << endl;
	return 0;
}

