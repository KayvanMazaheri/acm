#include <iostream>
#include <string>
using namespace std;

string inp;



int main()
{
	cin >> inp;
	if ((inp.find("0000000") != string::npos)||(inp.find("1111111") != string::npos))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
