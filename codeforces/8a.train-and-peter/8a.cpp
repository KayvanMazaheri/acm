#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string way, s1, s2;
	cin >> way >> s1 >> s2;
	bool a2b = false;
	bool b2a = false;
	if (way.find(s1) != string::npos && way.substr(way.find(s1) + s1.size()).find(s2) != string::npos)
		a2b = true;
	reverse(way.begin(), way.end());
	if (way.find(s1) != string::npos && way.substr(way.find(s1) + s1.size()).find(s2) != string::npos)
		b2a = true;
	if (a2b && b2a)
		cout << "both" << endl;
	else if (a2b)
		cout << "forward" << endl;
	else if (b2a)
		cout << "backward" << endl;
	else
		cout << "fantasy" << endl;
	return 0;

}
