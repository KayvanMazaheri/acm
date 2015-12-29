#include <iostream>
#include <vector>
using namespace std;

vector <int> pairs ;
vector <int> primes ;

bool isPrime(int x)
{
	if (x==1)
		return 0;
	for (int i=0;(i < primes.size())&&(primes[i]*primes[i] <=x); i++)
		if (x%primes[i] == 0)
			return false ;
	return true ;

}
void makePrime(int n)
{
	for(int i=2; i<n; i++)
	{
		if (isPrime(i)==1)
		{
			primes.push_back(i);
			if (i>5)
				i+=1;

		}

	}
	return ;
}

int main()
{
	int n;
	cin >> n;
	n++;
	if (n<5)
	{
		cout << 0;
		return 0;
	}
	int counter = 0;
	makePrime(n);
	for (int a=0; a<primes.size()-1 ;a++ )
	{
		///cerr << primes[a] << endl ;
		if(primes[a]+2==primes[a+1])
		{
			pairs.push_back(primes[a]);
			counter++;
		}
	}
	cout << counter << endl ;
	for (int i=0; i<counter; i++)
		cout << "2" << " " << pairs[i] << endl ;

	return 0;
}
