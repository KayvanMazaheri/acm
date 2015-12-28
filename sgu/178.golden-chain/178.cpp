#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long k = 0;
    long long next = k + 1;
    long long sum = next + k;
    while(sum < n)
    {
        k += 1;
        next = k + 1;
        sum = next + k;
        for(int i=0; i<k; i++)
        {
            next *=2;
            sum += next;
        }
        //cerr << sum << endl;
    }
    cout << k << endl;
    return 0;
}
