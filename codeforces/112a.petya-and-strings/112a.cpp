#include <iostream>
#include <string>
using namespace std;

string lowercase (string inp)
{
	string result = "" ;
	for (int i=0; i<inp.size(); i++)
		if (inp[i] < 'a')
			result += (inp[i] + 'a' - 'A');
		else
			result += inp[i];
	return result ;
}
int main()
{
	string a, b;
	cin >> a >> b;
	a = lowercase(a) ;
	b = lowercase(b);
	int result = 0 ;
//	if (a.size()>b.size())
//			result = 1;
//	else if (a.size()<b.size())
//		result = -1 ;
//	else
		for (int i=0; i<a.size(); i++)
			if (a[i] > b[i])
			{
				result = +1 ;
				break ;
			}
			else if (a[i] < b[i])
			{
				result = -1 ;
				break ;
			}
	cout << result << endl ;
	return 0;
}
