#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 2e2;

int arr[MAXN];
pair <int, int> minimum;
int minVal = 1e9;

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    for(int i=0; i<n; i++)
        if (abs(arr[i] - arr[(i+1)%n]) < minVal)
        {
            minVal = abs(arr[i] - arr[(i+1)%n]);
            minimum = make_pair(i, (i+1)%n);
        }
    cout << minimum.first + 1 << " " << minimum.second + 1 << endl;
    return 0;
}
