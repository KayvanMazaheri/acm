#include <iostream>
#include <string>

using namespace std;


string month[13] = {"December", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int which (string s)
{
	for(int i=0; i<12; i++)
		if (s == month[i])
			return i;
	return -1;
}

int main()
{
	int k;
	string m;
	cin >> m >> k;
	cout << month[(( k + which(m)) % 12) ] << endl;
	return 0;
}
