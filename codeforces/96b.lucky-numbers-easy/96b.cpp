#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <char> vec;

int main()
{
	string n;
	cin >> n;
	if (n.size() % 2 )
		n = "0" + n;
	string result;
	for(int i=0; i<n.size()/2; i++)
		result += "4";
	for(int i=0; i<n.size()/2; i++)
		result += "7";
	while(result < n && next_permutation(result.begin(), result.end()));
	if (result < n)
	{
		result = "";
		for(int i=0; i<n.size()/2 + 1; i++)
			result += "4";
		for(int i=0; i<n.size()/2 + 1; i++)
			result += "7";

	}
	cout << result << endl;
	return 0;


}
