#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 5e5 + 123;


long long dpa[MAXN];
long long dpb[MAXN];


int main() {
	int n;
	cin >> n;
	vector<int> p;
	for (int i = 0; i < n; ++i)
	{
		int pp;
		cin >> pp;
		p.push_back(pp);
	}
	string s;
	cin >> s;
	for (int i = 0; i < n; ++i)
	{
		char c = s[i];
		if (c == 'A') {
			dpa[i] = (i == 0 ? 0 :(c == 'A' ? dpa[i-1]: dpb[i-1])) + p[i];
			dpb[i] = (i == 0 ? 0 : dpb[i-1]);
		} else {
			dpb[i] = (i == 0 ? 0 :(c == 'A' ? dpa[i-1]: dpb[i-1])) + p[i];
			dpa[i] = (i == 0 ? 0 : dpa[i-1]);
		}
	}

	long long result = dpb[n-1];
	long long bestAdd = 0;
	for (int i = 0; i < n; ++i)
		bestAdd = max(bestAdd, dpa[i] - dpb[i]);

	// cerr << result << " " << bestAdd << endl;
	reverse(s.begin(), s.end());
	reverse(p.begin(), p.end());
	for (int i = 0; i < n; ++i)
	{
		char c = s[i];
		if (c == 'A') {
			dpa[i] = (i == 0 ? 0 :(c == 'A' ? dpa[i-1]: dpb[i-1])) + p[i];
			dpb[i] = (i == 0 ? 0 : dpb[i-1]);
		} else {
			dpb[i] = (i == 0 ? 0 :(c == 'A' ? dpa[i-1]: dpb[i-1])) + p[i];
			dpa[i] = (i == 0 ? 0 : dpa[i-1]);
		}
		// cerr << "dp i " << dpa[i] << " " << dpb[i] << endl;
	}
	for (int i = 0; i < n; ++i){
		// cerr << "nn " << dpa[i] - dpb[i] << endl;
		bestAdd = max(bestAdd, dpa[i] - dpb[i]);
	}

	// cerr << result << " " << bestAdd << endl;

	cout << result + bestAdd << endl;

}
