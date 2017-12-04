#include <iostream>
#include <string>
using namespace std;

int chars[100];

int main()
{
	int k;
	string s;
	cin >> k >> s;
	int n = s.size();

	for(int i=0; i<n; i++)
		chars[s[i]-'a'] ++;
	for(int i=0; i<100; i++)
	{
		if (chars[i] % k != 0)
		{
			cout << -1 << endl;
			return 0;
		}
		chars[i] /= k;
	}
	string gen;
	for(int i=0; i<100; i++)
		for(int j=0; j<chars[i]; j++)
			gen += char(i+'a');
	string result;
	for(int i=0; i<k; i++)
		result += gen;
	cout << result << endl;
	return 0;
}
