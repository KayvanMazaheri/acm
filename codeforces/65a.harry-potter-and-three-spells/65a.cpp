#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	float finalGold = 0;
	if (e && c)
		finalGold = float (f * b * d) / float(e * c) ;
	{
		if ((!e && f && b && d) || (!c && d) || (!a && b && d))
			finalGold = a + 1;
	}
	//cerr << finalGold << endl;
	if(finalGold > a)
		cout << "Ron" << endl;
	else
		cout << "Hermione" << endl;
	return 0;
}
