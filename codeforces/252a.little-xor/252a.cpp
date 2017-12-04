#include <iostream>
using namespace std;

int arr[200];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int max_xor = -1;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            int buff = 0;
            for(int k=i; k<=j; k++)
                buff ^= arr[k];
            max_xor = max (max_xor, buff);
        }
    cout << max_xor << endl;
    return 0;
}
