#include <iostream>

using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for(int i=2; i*i <= n; i++)
        if(!(n%i))
            return false;
    return true;
}

int nextPrime(int n)
{

    for(int i= n+1; ; i++)
        if (isPrime(i))
            return i;
}

int main()
{
    int n, m;
    cin >> n >> m;
    if (m == nextPrime(n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
