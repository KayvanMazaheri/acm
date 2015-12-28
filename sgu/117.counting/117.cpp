#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10001;
const int MAX_P = 9973 + 132;

int k_el[MAX_P];
int el[MAX_P];
vector <int> primes;

bool isPrime(int n)
{
    for(int i=0; i<primes.size(); i++)
		if (!(n%primes[i]))
			return false;
	return true;
}
void make_prime()
{
	for(int i=2; i<=MAX_P; i++)
		if (isPrime(i))
			primes.push_back(i);
	return;
}

bool db(int m)
{
	for(int i=0; i<MAX_P; i++)
		if (el[i] * m < k_el[i])
			return false;
	return true;
}



int main()
{
	int n, m, k, result = 0;
	primes.push_back(2);
	make_prime();
	//cout << primes[primes.size()-1] << endl;
	cin >> n >> m >> k;
	int _k = k;
	for(int i=0; i<primes.size(); i++)
	{
		while(_k%primes[i] == 0)
		{
			_k/=primes[i];
			k_el[primes[i]]++;
		}
	}
	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		for(int j=0; j<MAX_P; j++)
			el[j] = 0;
		for(int j=0; j<primes.size() ; j++)
		{
			while(inp%primes[j] == 0)
			{
				inp/=primes[j];
				el[primes[j]]++;
			}
		}
		if(db( m))
			result ++;
	}
	cout << result << endl;

}
