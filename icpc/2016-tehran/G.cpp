#include <iostream>
#include <iomanip>
using namespace std;

#define FX(x) fixed << setprecision((x))

const int MAXN = 1000 + 123;
const int MAXVOTE = 2000 + 12;

double p[MAXN];
int votes[MAXN];

double save[MAXN][MAXVOTE];

bool mark[MAXN][MAXVOTE];

double f(int state, int need){
	if(need <= 0)
		return 1.0;
	if(state < 0)
		return 0;
	if(mark[state][need])
		return save[state][need];

	double a = f(state-1, need);
	double b = f(state-1, need - votes[state]);

	mark[state][need] = true;

	return save[state][need] = (a * (1.0-p[state])) + (b * p[state]);
}

int main()
{
	int n;
	while(true)
	{
		cin >> n;
		if(!n)
			break;

		for (int i = 0; i < MAXN; ++i)
			fill(mark[i], mark[i]+MAXVOTE, false);

		int total_votes = 0;
		
		for (int i = 0; i < n; ++i){
			cin >> p[i] >> votes[i];
			total_votes += votes[i];
		}

		int need = total_votes / 2 + 1;
		cout << FX(4) << f(n-1, need) << endl;

	}
	return 0;
}