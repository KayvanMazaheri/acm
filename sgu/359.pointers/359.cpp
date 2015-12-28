#include <iostream>
#include <string>
using namespace std;

int arr[4] = {0, 0, 0, 0};
int pt[4] = {0, 1, 2, 3};

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		string query;
		cin >> query;
		if (query.find("writeln") != string::npos)
		{
			cout << arr[pt[query[8] - 'a']] << endl;
			continue;
		}
		if (query[query.size()-2] == '^')
			arr[pt[query[0] - 'a']] = arr[pt[query[4] - 'a']];
		else if ((query[query.size()-2] >= '0') && (query[query.size()-2] <= '9'))
			arr[pt[query[0] - 'a']] = query[query.size()-2] - '0';
		else
			pt[query[0] - 'a'] = pt[query[3] - 'a'];

//		cerr << endl ;
//		cerr << "a : " << pt[0] << "   a^ : " << arr[pt[0]] << endl;
//		cerr << "b : " << pt[1] << "   b^ : " << arr[pt[1]] << endl;
//		cerr << "c : " << pt[2] << "   c^ : " << arr[pt[2]] << endl;
//		cerr << "d : " << pt[3] << "   d^ : " << arr[pt[3]] << endl;
//		cerr << endl;
	}
	return 0;
}
