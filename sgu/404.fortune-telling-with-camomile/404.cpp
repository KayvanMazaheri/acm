#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string> phrase;
int main()
{
	int N, M;
	cin >> N >> M;
	for(int i=0; i<M; i++)
	{
		string inp;
		cin >> inp;
		phrase.push_back(inp);
	}
	if (N%M==0)
		cout << phrase[M-1] ;
	else
		cout << phrase[(N%M)-1];
	return 0;
}
