#include <iostream>

using namespace std;

bool hand(int g, int b);

int main()
{
	int a_r, b_r, a_l, b_l;
	cin >> a_r >> a_l >> b_r >> b_l ;
	if (hand(a_r, b_l) || hand(a_l, b_r))
		cout << "YES" << endl ;
	else
		cout << "NO" << endl;
	return 0;
}

bool hand(int g, int b)
{
	if (b < g-1)
		return false ;
	if (b > 2*(g+1))
		return false ;
	return true ;
}
