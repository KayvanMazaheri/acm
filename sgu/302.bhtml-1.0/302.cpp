#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <int> stack;
string output;
int main()
{
	stack.push_back(0);
	string input ;
	cin >> input ;
	for (int i=0; i<input.size(); i++)
	{
		if (input[i]== '<')
		{
			if(input[i+1]=='/')
			{
				if(input[i+2]=='D')
				{
					stack.pop_back();
					i+=6;
				}
				else
				{
					stack.pop_back();
					i+=4;
				}
			}
			else
			{
				if(input[i+1]=='D')
				{
					stack.push_back(1);
					i+=5;
				}
				else
				{
					stack.push_back(2);
					i+=3;
				}
			}
		}
		else
		{
			if(stack[stack.size()-1] == 1)
			{
				if(input[i]>='A' && input[i]< 'a')
				{
					output += input[i] - 'Z' + 'z';
				}
				else
					output += input[i];

			}
			else if(stack[stack.size()-1] == 2)
			{
				if(input[i] >= 'a')
				{
					output += input[i] + 'Z' - 'z';
				}
				else
					output += input[i];
			}
			else
				output += input[i];
		}
	}
	cout << output ;
	return 0;

}
