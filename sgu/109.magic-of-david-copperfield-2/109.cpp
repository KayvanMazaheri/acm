#include <iostream>
using namespace std;

void solve(int a1, int a2, int a3, int fx)
{
	int len = a2 - a1 + 1;
	int step = a3 - a1;
	if (len == 2)
	{
		if(fx % 2 == 0) fx ++;
		cout << fx << " " << a3 + 1 << endl;
		cout << fx + 2 << " " << a2 << " " << a3 << endl;
	}
	else if (len == 3)
	{
		if (fx % 2 == 0) fx ++;
		cout << fx << " " << a1 << " " << a2 << " " << a3 + step << " " << a3 + step + 2 << endl;
		cout << fx + 2 << " " << a1 + 1 << " " << a3 << " " << a3 + 2 << " " << a3 + step + 1 << endl;
	}
	else if (len % 2 == 0)
	{
		if (fx % 2) fx ++;
		cout << fx ;
		for(int i=a2; i <= (len - 3) * step + a2; i+= 2 * step) cout << " " << i;
		for(int i = (len - 1) * step + a1; i <= (len -1) * step + a2; i+= 2) cout << " " << i;
		cout << endl;
		fx ++;
		cout << fx ;
		for(int i=a2 + step; i < (len -1) * step + a2; i+= 2 * step) cout << " " << i;
		for(int i = (len - 1) * step + a1 + 1; i <= (len -1) * step + a2; i+= 2) cout << " " << i;
		cout << endl;
		fx+=2;
		cout << fx << " " << (len - 2) * step + a2 << endl;
		solve(a1, a2-1, a3, fx + 1);
	}
	else
	{
		if (fx % 2 == 0) fx ++;
		cout << fx ;
		for(int i = a1; i < a2; i+=2) cout << " " << i;
		for(int i=a2; i < (len -1) * step + a2; i+= 2 * step) cout << " " << i;
		for(int i = (len - 1) * step + a1 ; i <= (len -1) * step + a2; i+= 2) cout << " " << i;
		for(int i = a1 + step * 2; i < (len - 1) * step + a1; i+= 2 * step) cout << " " << i;
		cout << endl;
		fx += 2;
		cout << fx;
		for(int i = a1 + 1; i < a2; i+=2) cout << " " << i;
		for(int i=a2+step; i < (len -1) * step + a2; i+= 2 * step) cout << " " << i;
		for(int i = (len - 1) * step + a1 + 1; i <= (len -1) * step + a2; i+= 2) cout << " " << i;
		for(int i = a1 + step; i < (len - 1) * step + a1; i+= 2 * step) cout << " " << i;
		cout << endl;
		solve(a1 + step + 1, a2 + step - 1, a3 + step + 1, fx + 1);
	}
	return;
}

int main()
{
	int n;
	cin >> n;
	solve(1, n, n+1, n);
	return 0;
}
