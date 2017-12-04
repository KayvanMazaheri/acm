#include <iostream>
#include <string>
using namespace std;

int get_val (string s)
{
	//cerr << s << endl;
	if (s.size() > 6 && s != "1000000")
		return -1;
	if (s[0] == '0' && s.size() > 1)
		return -1;
	int result = 0;
	for(int i=0; i<s.size(); i++)
		(result *= 10) += s[i] - '0';
	return result;
}

int main()
{
	string s;
	cin >> s;
	//cerr << get_val(inp) << endl;
	int result = -1;
	for(int i=1; i<s.size(); i++)
		for(int j=1; j+i<s.size(); j++)
		{
			int p1 = get_val(s.substr(0, i));
			int p2 = get_val(s.substr(i, j));
			int p3 = get_val(s.substr(i+j, s.size()));
			//cerr << endl << endl;
			if (p1 == -1 || p2 == -1 || p3 == -1)
				continue;
			result = max (result, p1 + p2 + p3);
		}

	cout << result << endl;
}
