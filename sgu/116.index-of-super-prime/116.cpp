#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> primes;
vector <int> super_primes;
vector <int> result;

const int MAXN = 1e4 + 12;

int dp[MAXN];
int update[MAXN];

bool isPrime(int n)
{
	if (n < 2)
		return false;
	for(int i=2; i*i <=n; i++)
		if (!(n%i))
			return false;
	//cerr << n << " ";
	return true;
}

void route(int n)
{
	if (dp[n]== 0)
		cerr << "Error" << endl;
	if(dp[n] == 1)
		result.push_back(n);
	else
	{
		route(update[n]);
		route(n - update[n]);
	}
	return;
}

int main()
{
	int n = 1e4;
	cin >> n;
	for(int i=2; i<=n; i++)
		if (isPrime(i))
			primes.push_back(i);
	for(int i=0; i<primes.size(); i++)
		if (isPrime(i+1))
			super_primes.push_back(primes[i]);
	//cerr << super_primes.size() << endl;


	for(int i=0; i<MAXN; i++)
		dp[i] = 0;
	for(int i=0; i<super_primes.size(); i++)
		dp[super_primes[i]] = 1;

	for(int i=3; i<=n; i++)
	{
		if (dp[i] == 1)
			continue;
		int min = MAXN;
		for(int j=1; j<=i/2; j++)
		{
			int sum = dp[j] + dp[i-j];
			if (!(dp[j] == 0 || dp[i-j] == 0) && sum < min)
			{
				min = sum;
				update[i] = j;
			}

		}
		if (min == MAXN)
			min = 0;
		dp[i] = min;
	}
	cout << dp[n] << endl;
	if (dp[n] == 0)
		return 0;
	route(n);
	sort(result.begin(), result.end(), std::greater<int>());
	for(int i=0; i<result.size(); i++)
		cout << result[i] << " ";
	cout << endl;
//	for(int i=0; i<super_primes.size(); i++)
//		cout << super_primes[i] << " " ;
//		cout << endl;
	return 0;

}
