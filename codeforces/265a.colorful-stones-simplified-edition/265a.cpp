#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;
	int pos = 0;
	for(int i=0; i<t.size(); i++)
		if (s[pos] == t[i])
			pos++;
	cout << pos+1 << endl;
	return 0;
}
