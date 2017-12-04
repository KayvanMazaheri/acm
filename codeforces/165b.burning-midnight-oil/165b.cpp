#include <iostream>
using namespace std;

bool check(int v, int k, int n)
{
	long long _k = k;
	long long result = v;
	while(result <= n && (v/_k))
	{
		result += v/_k;
		_k *= k;
	}
	return result >= n;
}

int binary_search(int n, int k, int head, int tail)
{
	if  (tail - head < 5)
	{
		for(int i=head ; i <= tail; i++)
			if (check(i, k, n))
				return i;
	}
	int mid = (head + tail) / 2;
	if(check(mid, k, n))
		return binary_search(n, k, head, mid + 1);
	return binary_search(n, k, mid - 1, tail);
}

int main()
{

	int n, k;
	int v;
	cin >> n >> k;
	cout << binary_search(n, k, 1, 1e9) << endl;
	return 0;
}
