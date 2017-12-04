#include <iostream>
#include <string>

using namespace std;

int main()
{
	//cout << int('z') << " " << int ('A') ;
	string inp, up, down;
	int a = 0;
	cin >> inp;
	up.resize(inp.size());
	down.resize(inp.size());
	for(int i=0; i<inp.size(); i++)
	{
		if(inp[i] > 'Z')
		{
			down[i] = inp[i];
			up[i] = inp[i] - 'a' +'A';
			a++;
		}
		else
		{
			up[i] = inp[i];
			down[i] = inp[i] - 'A' +'a';
			a--;
		}
	}
	//cerr << a << endl ;
	//cerr << down << " " << up << endl ;
	if(a >= 0)
		cout << down << endl;
	else
		cout << up << endl ;
	return 0;
}
