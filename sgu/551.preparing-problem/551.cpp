#include <iostream>

using namespace std;

int main()
{
	int n, t1, t2;
	cin >> n >> t1 >> t2;
	int solutions = 0;
	long long  time = 0;
	while ((time)/t1 + (time)/t2 < n)
		time++;
	solutions = (time+t1-1)/t1 + (time+t2-1)/t2;
	long long last_p1 = (time+t1-1) / t1;
	long long last_p2 = (time+t2-1) / t2;
	last_p1 *= t1;
	last_p2 *= t2;
	cout << solutions << " " << max(last_p1, last_p2) << endl;
	return 0;
}
