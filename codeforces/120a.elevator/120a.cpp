#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	string door;
	int rail ;
	int d;
	cin >> door >> rail;
	rail -- ;
	if(door == "front")
		d = 1;
	else
		d = 0;
	if(rail ^ d)
		cout << "L" << endl;
	else
		cout << "R" << endl;
	return 0;
}
