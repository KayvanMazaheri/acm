#include <iostream>
#include <string>

using namespace std;

string teams[2];
int points[2];

int main()
{
	int n;
	cin >> n;
	string inp;
	cin >> inp;
	teams[0] = inp;
	points[0] ++;
	for(int i=1; i<n; i++)
	{
		cin >> inp;
		if (inp == teams[0])
			points[0] ++;
		else
		{
			teams[1] = inp;
			points[1] ++;
		}
	}
	if (points[0] > points[1])
		cout << teams[0] << endl;
	else
		cout << teams[1] << endl;
	return 0;
}
