#include <iostream>
using namespace std;


bool isPrime(int n)
{
    for(int i=2; i*i<=n; i++){
        if (!(n%i))
            return false;
    	if (i>2)
			i++;
    }
    return true;
}

int key(int a)
{
    int max_prime = -1;
    int sum = 0;
    for(int i=2; i<=a; i++)
        if (isPrime(i))
            if (a%i==0)
            {
                sum+=i;
                max_prime = i;
            }
    sum -= max_prime;
    int result = max_prime - sum;
    return result;
}

int main()
{
    int a, b;
    cin >> a >> b;
	cout << ((key(a) > key (b))?'a':'b') << endl;
    return 0;
}
