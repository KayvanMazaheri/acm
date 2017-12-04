#include <iostream>
#include <string>
using namespace std;

int main()
{
	string inp;
	cin >> inp;
	for(int i=0; i<inp.size(); i++)
		if (inp[i] == 'r')
			cout << i+1 << endl;;
	for(int i=inp.size()-1; i >= 0; i--)
		if (inp[i] == 'l')
			cout << i+1 << endl;
	return 0;

}
