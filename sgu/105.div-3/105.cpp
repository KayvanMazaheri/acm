#include <iostream>
#include <string>
using namespace std;

string sequence;
int main()
{
	int n;
	cin >> n;
	if (n%3 == 2)
		cout << 2*(n/3)+1;
	else
		cout << 2*(n/3);
	return 0;
}
