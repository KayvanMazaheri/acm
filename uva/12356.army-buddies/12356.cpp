#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 123;

bool dead[MAXN];
int rbuddy[MAXN];
int lbuddy[MAXN];



void init(int n)
{
	fill(dead, dead + MAXN, false);
	lbuddy[0] = -1;
	lbuddy[1] = -1;
	rbuddy[n] = -1;
	rbuddy[n+1] = -1;
	for (int i = 2; i <= n; ++i)
		lbuddy[i] = i-1;
	for (int i = 1; i <= n-1; ++i)
		rbuddy[i] = i+1;
	return;
}

void formatedPrint(int i){
	if(i == -1)
		cout << "*";
	else
		cout << i;
	return;
}


void kill(int l, int r)
{
	rbuddy[lbuddy[l]] = rbuddy[r];
	lbuddy[rbuddy[r]] = lbuddy[l];

	formatedPrint(lbuddy[l]);
	cout <<  " ";
	formatedPrint(rbuddy[r]);
	cout << endl;
}

int main()
{
	int n, q;
	while(cin >> n >> q)
	{
		if(!n && !q)
			break;
		init(n);
		for (int i = 0; i < q; ++i)
		{
			int l, r;
			cin >> l >> r;
			kill(l, r);

		}
		cout << "-" << endl;
	}
	return 0;
}

