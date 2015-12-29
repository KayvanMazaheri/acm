#include <iostream>
#include <string>
using namespace std;

string input;
char stack1[1000*1000];
char stack2[1000*1000];
int ps1=0,ps2=0;

int main()
{
	cin >> input ;
	for(int pi=0; pi<input.size(); pi++)
	{

		if (input[pi] == 'L')
		{
			if (ps1!=0)
			{
				stack2[ps2]=stack1[ps1-1];
				ps2++;
				ps1--;
			}
		}
		else if (input[pi]=='R')
		{
			if (ps2!=0)
			{
				stack1[ps1]=stack2[ps2-1];
				ps2--;
				ps1++;
			}

		}
		else
		{
			stack1[ps1]=input[pi];
			ps1++;
		}

		//cerr << input[pi] << " ps1 :" << ps1 << " ps2 :" << ps2 <<" pi :" << pi <<endl ;
	}

	for(; 0<ps2; ps2--)
	{
		stack1[ps1]=stack2[ps2-1];
		ps1++;
	}
	//cerr << ps1 ;
	for(int i=0; i<ps1; i++)
		cout << stack1[i];
	return 0;
}
