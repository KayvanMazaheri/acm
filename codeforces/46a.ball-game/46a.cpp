#include <iostream>

using namespace std;

int main()
{
	int n, current = 1;
	cin >> n;
	for(int i=1; i<n; i++)
	{
		current += i;
		current %= n;
		if (!current)
			current = n;
		cout << current << " ";

	}
	cout << endl;
	return 0;

}
