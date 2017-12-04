#include <iostream>
#include <string>
using namespace std;

string inp;

bool isHQ()
{
	for (int i=0; i<inp.size(); i++)
		if (inp[i] == 'H' || inp[i] == 'Q' || inp[i] == '9')
			return true ;
	return false ;
}

int main()
{
	getline(cin, inp);
	if (isHQ())
		cout << "YES" << endl ;
	else
		cout << "NO" << endl ;
	return 0;
}
