#include <iostream>
using namespace std;

int main()
{
	int N,M;
	cin >> N >> M ;
	int buffer = 0 ;
	int sum = 0;
	for (int i=0; i<M; i++)
	{
		cin >> buffer ;
		sum += buffer;
	}
	cout << sum%N ;
	return 0;
}
