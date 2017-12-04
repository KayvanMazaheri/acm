#include <iostream>
#include <string>
using namespace std;

bool wrong (string inp)
{
	for (int i=1; i<inp.size(); i++)
		if (int(inp[i]) > int('Z'))
			return false ;
	return true ;
}
int main()
{
	string input, result;
	cin >> input ;
	// cerr << int('Z') << " " << int('a') << " " << int('b') << endl ;
	if (wrong(input))
		for (int i=0; i<input.size(); i++)
			if(input[i] > 'Z')
				result += (input[i] + 'A' - 'a') ;
			else
				result += (input[i] - 'A' + 'a') ;
	else
		result = input ;
	cout << result << endl ;
}
