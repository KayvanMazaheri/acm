#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i=0; i<min(n, m); i++)
		cout << ((n < m) ? "GB" : "BG") ;
	for(int i=0; i<max(n, m) - min(n, m); i++)
		cout << ((n < m) ? "G" : "B");
	cout << endl;
	return 0;

}
