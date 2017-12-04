#include <iostream>
#include <algorithm>
#include <string>

#define EPS 1e-8
#define point pair <int , int>
#define X first
#define Y second

using namespace std;

const int MAXN = 1e9;

int compare(string a, string b);

int main()
{
	int result = 0, minimum = MAXN;
	string s, u;
	cin >> s >> u;
	if (s.size() < u.size())
	{
		//result += s.size() - u.size();
		//s += u.substr (s.size(), s.size() - u.size());
		for(int i=0; i<s.size() - u.size(); i++)
			s+= '`';
	}
	for(int i=0; i<u.size()+2; i++)
		s+= '`';
	for(int i=0; i<u.size()+2; i++)
		s = '`' + s;
	for(int i=0; i<= s.size()-u.size(); i++)
	{
		string sb = s.substr(i, u.size());
		if (compare(sb, u) < minimum)
			minimum = compare(sb, u);
	}

	result += minimum ;
	cout << result << endl;

	return 0;
}

int compare(string a, string b)
{
	int result = 0;
	for(int i=0; i<a.size(); i++)
		if (a[i] - b[i])
			result ++;
	return result ;
}
