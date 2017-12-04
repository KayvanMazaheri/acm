#include <iostream>
using namespace std;

const int MAXN = 1e5 + 123;

int seq[MAXN];

int main()
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> seq[i];
	int jump = 0;
	int jump_pos = 0;
	for(int i=1; i<n; i++)
		if(seq[i] < seq[i-1])
		{
			jump++;
			jump_pos = i;
		}
	if(jump && seq[n-1] > seq[0]) jump++;
	if(jump > 1) cout << -1 << endl;
	else if (jump) cout << n - jump_pos << endl;
	else cout << 0 << endl;
	return 0;


}
