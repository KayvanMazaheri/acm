#include <iostream>
#include <string>
using namespace std;

bool XOR(char a, char b)
{
	if (a == b)
		return false ;
	return true ;
}

int main()
{
	string a, b;
	cin >> a >> b;
	for (int i=0; i<a.size(); i++)
		cout << XOR(a[i], b[i]);
	cout << endl ;
	return 0;
}
