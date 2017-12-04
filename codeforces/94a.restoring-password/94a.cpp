#include <iostream>
#include <string>

using namespace std;

int main()
{
	string hashed;
	string table[10];
	cin >> hashed ;
	for(int i=0; i<10; i++)
		cin >> table[i] ;
	string pass = "" ;
	for(int i=0; i<80; i+=10)
	{
		string buffer = hashed.substr(i, 10);
		for(int j=0; j<10; j++)
			if (buffer == table[j])
			{
				pass = pass + char(j + '0');
				break;
			}

	}
	cout << pass << endl ;
	return 0;
}
