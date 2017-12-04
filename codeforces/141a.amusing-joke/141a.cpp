#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string guest, host, pile;
	cin >> guest >> host >> pile ;
	string buffer = guest + host ;
	sort(pile.begin(), pile.end() ) ;
	sort(buffer.begin(), buffer.end());
	if (buffer == pile)
		cout << "YES" << endl ;
	else
		cout << "NO" << endl ;
	return 0;
}
