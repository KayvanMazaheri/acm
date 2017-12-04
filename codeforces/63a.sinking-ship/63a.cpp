#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 1e2 + 12;

pair <int, pair<int, string> > crew[MAXN];

int priority(string s)
{
	if (s == "rat")
		return 1;
	if (s == "woman" || s == "child")
		return 2;
	if (s == "man")
		return 3;
	if (s == "captain")
		return 4;
	return -1;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		string name, status;
		cin >> name >> status;
		crew[i] = make_pair(priority(status), make_pair(i, name));
	}
	sort(crew, crew + n);
	for(int i=0; i<n; i++)
		cout << crew[i].second.second << endl;
	return 0;
}

