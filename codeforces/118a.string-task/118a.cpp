#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c)
{
	char vowels[12] = {'a', 'A', 'e', 'E', 'o', 'O', 'i', 'I', 'u', 'U', 'y', 'Y'} ;
	for (int i=0; i<12; i++)
		if (c == vowels[i])
			return true ;
	return false ;
}
int main()
{
	string str, result = "" ;
	cin >> str ;
	for (int i=0; i<str.size(); i++)
		if (!isVowel(str[i]))
			{
				result += '.' ;
				if (str[i] < 'a')
					result += char(int(str[i])+int('a')-int('A'));
				else
					result += str[i];
			}
	cout << result << endl;
	return 0;
}
