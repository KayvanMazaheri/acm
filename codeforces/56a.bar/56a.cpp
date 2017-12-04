#include <iostream>
#include <string>

using namespace std;

string alcholes[11] = { "ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};

bool mustChecked(string s);
int str2int(string s);

int main()
{
	int n, result = 0;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		string inp;
		cin >> inp;
		if (mustChecked(inp))
			result ++;
	}
	cout << result << endl;
	return 0;
}

bool mustChecked(string s)
{
	for(int i=0; i<11; i++)
		if (s == alcholes[i])
			return true;
	if (s[0] - '0' >= 0 && s[0] - '0' < 10)
		if (str2int(s) < 18)
			return true;
	return false;
}

int str2int(string s)
{
	int result = 0;
	for(int i=0; i<s.size(); i++)
	{
		result *= 10;
		result += s[i] - '0';
	}
	return result;
}
