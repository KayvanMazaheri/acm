#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e9 + 123;
int arr[200];

int make_bonacci(int k)
{
    arr[0] = 1;
    int sum = 1;
    int sz;
    for(int i = 1; sum < MAXN; i++)
    {
        sum -= ((i-k > 0)?arr[i-k-1]:0);
        arr[i] = sum;
        sum += arr[i];
        //cerr << i << " : " << arr[i] << endl;
        sz = i;
    }
    //cerr << sz << endl;
    return sz;
}

vector <int> vec;

int main()
{
    int s, k;
    cin >> s >> k;
    int tail = make_bonacci(k);
    for(; tail > 0 && s; tail --)
    {
        if (arr[tail] <= s)
        {
            s -= arr[tail];
            vec.push_back(arr[tail]);
        }
    }
    vec.push_back(0);
    cout << vec.size();
    for(int i=0; i<vec.size(); i++)
        cout << " " << vec[i];
    cout << endl;
    return 0;
}
