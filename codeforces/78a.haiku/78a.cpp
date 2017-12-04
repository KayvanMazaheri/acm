#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c)
{
	if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
		return true;
	return false ;
}

int main()
{
	string s[3];
	int v[3] = {0, 0, 0};
	for (int i=0; i<3; i++)
		getline(cin, s[i]);
	for(int i=0; i<3; i++)
		for(int j=0; j<s[i].size(); j++)
			if(isVowel(s[i][j]))
				v[i] ++ ;
	if (v[0] == 5 && v[1] == 7 && v[2] == 5)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
