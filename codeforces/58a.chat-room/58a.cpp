#include <iostream>
#include <string>

using namespace std;

const int null = -1;

string hello = "hello";
int sp = 0;
string s;

int hasLetter(int p, char c)
{
	for(int i=p; i<s.size(); i++)
		if (s[i] == c)
			return i+1;
	return null;
}

int main()
{
	cin >> s;
	for (int i=0; i<hello.size(); i++)
		if (!((sp = hasLetter(sp, hello[i]))+1))
		{
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
	return 0;
}
