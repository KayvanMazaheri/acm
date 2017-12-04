#include <iostream>
using namespace std;

bool punctuation(char c);

int main()
{
	string input ;
	string result ;
	getline(cin, input);
	for (int i=0; i<input.size(); i++)
	{
		if(input[i] == ' ')
		{
			//cerr << "space " << endl ;
			if (result.size()>0)
				if(result[result.size()-1] != ' ')
					if (i<input.size()-1)
						if(!punctuation(input[i+1]))
							result += input[i];
		}
		else if (punctuation(input[i]))
		{
			result += input[i];
			if (i<input.size()-1)
				if (input[i+1] != ' ')

					result += " ";
		}
		else
			result += input[i];

	}
	input = result ;
	result = "" ;
	for (int i=0; i<input.size(); i++)
	{
		if(input[i] == ' ')
		{
			//cerr << "space " << endl ;
			if (result.size()>0)
				if(result[result.size()-1] != ' ')
					if (i<input.size()-1)
						if(!punctuation(input[i+1]) )
							result += input[i];
						else if (punctuation(input[i-1]))
							result += input[i];
		}
		else if (punctuation(input[i]))
		{
			result += input[i];
			if (i<input.size()-1)
				if (input[i+1] != ' ')

					result += " ";
		}
		else
			result += input[i];

	}
	cout << result << endl ;
}

bool punctuation (char c)
{
	if (c == ',')
		return true ;
	if (c == '?')
		return true ;
	if (c == '.')
		return true ;
	if (c == '!')
		return true ;
	return false ;
}
