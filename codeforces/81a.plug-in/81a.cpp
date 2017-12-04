#include <iostream>
#include <string>

using namespace std;

const int MAXN = 2e5 + 123;

char result[MAXN];
int pointer = 2;

int main()
{
	string s;
	cin >> s ;
	result[0] = '`';
	result[1] = s[0];
	for(int i=1; i<s.size(); i++)
	{
		if(pointer >= 2 && s[i] == result[pointer-1])
			pointer--;
		else
			result[pointer++] = s[i];
	}
	for(int i=1; i<pointer; i++)
		cout << result[i];
	cout << endl;
	return 0;
}
