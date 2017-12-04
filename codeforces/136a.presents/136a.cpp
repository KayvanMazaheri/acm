#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <int> inp, result ;
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		int a;
		cin >> a;
		inp.push_back(a) ;
	}
	result.resize(inp.size());
	for (int i=0; i<inp.size(); i++)
		result[inp[i]-1] = i+1 ;
	for (int i=0; i<result.size()-1; i++)
		cout << result[i] << " ";
	cout << result[result.size()-1] ;
	cout << endl ;
	return 0;

}
