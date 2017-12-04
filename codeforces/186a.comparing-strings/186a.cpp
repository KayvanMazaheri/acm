#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	if (a.size() != b.size())
	{
			cout << "NO" << endl;
			return 0;
	}
	int n = a.size();
	int pos[2];
	int num = 0;
	for(int i=0; i<n && num < 3; i++)
		if (a[i] != b[i])
			pos[num++] = i;
	if (num != 2 || !(a[pos[0]] == b[pos[1]] && a[pos[1]] == b[pos[0]]))
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}
