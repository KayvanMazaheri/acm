#include <iostream>
#include <string>
using namespace std;

string inp;


bool isLetter (char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int emo(int n)
{
	if (inp[n+1] == ')')
		return n+1;
	for(int i=n+1; i<inp.size()-1 && (isLetter(inp[i]) || inp[i] == ' '); i++)
		if (inp[i+1]==')')
			return i+1;
	return -1;
}

int main()
{
	int result = 0;
	getline(cin, inp);

	for(int i=0; i<inp.size(); i++)
	{
		if (inp[i] == ')' )
			result ++;
		if( inp[i] == '(' )
			if ( emo(i) == -1)
				result ++;
			else
			i = emo(i);
	}
	cout << result << endl;
	return 0;
}
