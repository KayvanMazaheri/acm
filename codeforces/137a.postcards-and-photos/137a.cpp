#include <iostream>
#include <string>

using namespace std;

int main()
{
	string inp;
	cin >> inp;
	int pointer = 0, result = 0;
	while(inp.size()-pointer > 0)
	{
		char f = inp[pointer];
		for(int i=0; (inp.size()-pointer) &&  i<5 && inp[pointer] == f; i++ )
			pointer ++;
		result ++;
	}
	cout << result << endl;
	return 0;
}
