#include <iostream>
#include <string>

using namespace std;

string s;

bool isLucky()
{
	for(int i=0; i<s.size(); i++)
		if (!(s[i] == '4' || s[i] == '7'))
			return false ;
	return true ;
}

int main()
{
	int n;
	cin >> n >> s;
	int sum = 0 ;
	for (int i=0; i<n/2; i++)
		sum += int(s[i] - '0');
	for (int i=n/2; i<s.size(); i++)
		sum -= int(s[i] - '0');

	if (isLucky() && sum == 0)
		cout << "YES" << endl ;
	else
		cout << "NO" << endl ;
	return 0;
}
