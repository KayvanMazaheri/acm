#include <iostream>
#include <string>
using namespace std;

int main()
{
	string inp;
	cin >> inp;
	string result;
	if (inp.substr(0, 4) == "http")
	{
		result = "http://";
		inp = inp.substr(4);
	//	cerr << inp;
	}
	else
	{
		result = "ftp://";
		inp = inp.substr(3);
		//cerr << inp ;
	}
	result += inp[0];
	inp = inp.substr(1);
	int domain_pos = inp.find("ru");
	result += inp.substr(0, domain_pos) + ".ru";
	inp = inp.substr(domain_pos + 2);
	if (inp.size())
		result += "/" + inp;
	cout << result << endl;
	return 0;
}
