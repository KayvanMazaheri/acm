#include <iostream>
#include <string>
using namespace std;

string f(long long n)
{
    if (n%2 == 0)
		return "-1";
	if (n == 1)
		return "";
	string m1 = f((n+1) / 2);
	string m2 = f((n-1) / 2);
	if (m1 == "-1")
		return m2+"2";
	if (m2 == "-1")
		return m1+"1";
	if (m1.size() < m2.size())
		return m1+"1";
	return m2+"2";
}

int main()
{
	long long n;
	cin >> n;
	string ans = f(n) ;
	if (ans == "-1")
	{
		cout << "No solution" << endl;
		return 0;
	}
	cout << ans.size() << endl;
	if (!ans.size())
		return 0;
	cout << ans[0];
	for(int i=1; i<ans.size(); i++)
		cout << " " << ans[i];
	cout << endl;
	return 0;
}
