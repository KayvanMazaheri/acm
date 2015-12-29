#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string secret, guess;

int main()
{

	cin >> secret >> guess ;
	int bulls = 0;
	int cows = 0;
	for (int i = 0; i<4; i++)
	{
		long long address = guess.find(secret[i]);
		//cerr << address << endl ;
		if (address > -1 && address < 4);
		{
			if (address == i)
				bulls ++;
			else if (address < 4 && address > -1)
				cows ++;
		}
	}
	int bulls_2 = 0;
	int cows_2 = 0;
	for (int i = 0; i<4; i++)
	{
		long long address = secret.find(guess[i]);
		//cerr << address << endl ;
		if (address > -1 && address < 4);
		{
			if (address == i)
				bulls_2 ++;
			else if (address < 4 && address > -1)
				cows_2 ++;
		}
	}
	bulls = min(bulls, bulls_2);
	cows = min(cows, cows_2);
	cout << bulls << " " << cows << endl;
	return 0;
}
