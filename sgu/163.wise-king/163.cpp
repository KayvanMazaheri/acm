#include <iostream>
using namespace std;

int pow(int a, int b)
{
	if (b < 1)
		return 1;
	return a * pow(a, b-1);
}
int main()
{
	int m, n;
	cin >> n >> m;
	int son[n];
	for (int i=0; i<n; i++)
		cin >> son[i];
	if (m%2 == 0)
	{
		int sum = 0;
		for (int i=0; i<n; i++)
			sum += pow(son[i], m);
		cout << sum << endl ;
		cerr << "#1" << endl;
	}
	else if (m== 0)
	{
		int sum = 0;
		for (int i=0; i<n; i++)
			if (son[i] != 0)
				sum ++;
		cout << sum << endl ;
		cerr << "#2" << endl;
	}
	else
	{
		int sum = 0;
		for (int i=0; i<n; i++)
			if (son[i] > 0)
				sum += pow(son[i], m);
		cout << sum << endl ;
		cerr << "#3" << endl;
	}
	return 0;
}
