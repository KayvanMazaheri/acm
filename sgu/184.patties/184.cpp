#include <iostream>
using namespace std;

int main()
{
	int P,M,C,K,R,V ;
	cin >> P >> M >> C;
	cin >> K >> R >> V;
	P /= K ;
	M /= R ;
	C /= V ;
	int min ;
	min = P ;
	if (M < min)
		min = M;
	if (C < min)
		min = C ;

	cout << min ;
	return 0;

}
