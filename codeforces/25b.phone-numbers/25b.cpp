#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, pointer = 0;
	string inp, result;
	cin >> n >> inp;
	if (n%2)
	{
		result += inp.substr(0, 3) ;
		pointer = 3;
	}
	for(int i=pointer; i<n; i+=2)
		result +=  '-' + inp.substr(i, 2);
	if (result[0] == '-')
		result = result.substr(1, result.size()-1);
	cout << result << endl;
	return 0;
}
