#include <iostream>
using namespace std;

int line(int n)
{
	if(n!=0)
		return line (n-1) + n ;
	else
		return 1;
}
int main()
{
	int n;
	cin >> n;
	cout << line(n);
	return 0;
}
