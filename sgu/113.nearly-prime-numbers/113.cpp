#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string isNearlyPrime(int n);
void makePrimes (int n);
bool isPrime(int n);

vector <int> primes ;

int main()
{
	primes.push_back(3) ;
	int n, inp;
	cin >> n;
	for(int t=0; t<n; t++)
	{
		cin >> inp ;
		cout << isNearlyPrime(inp) << endl;
	}
	return 0;
}

string isNearlyPrime(int n)
{
	/**
	if (n%2 == 0)
		if (isPrime(n/2))
			return "Yes" ;
		else
			return "No" ;
	if (n > primes[primes.size()-1])
		makePrimes (n/2);
	/**/
	for (int i = 0; i*i <= n; i++)
		if (isPrime(i))
			if (n % i == 0)
				if (isPrime(n/i))
					return "Yes" ;

	return "No" ;
}

void makePrimes(int n)
{
	for (long long i = primes[primes.size()-1] + 1; i <= n/2; i++)
	{
		if (isPrime(i))
			primes.push_back(i);
	}
	return ;
}

bool isPrime(int n)
{
	bool result = true ;
	for (long long i=2; i*i <= n; i++)
	{
		if (n % i == 0)
		{
			result = false ;
			break;
		}
	}
	if (n < 2)
		result = false;
	return result ;
}
