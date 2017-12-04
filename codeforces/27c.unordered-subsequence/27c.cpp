#include <iostream>
using namespace std;

const int MAXN = 1e5 + 123;

int arr[MAXN];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int mn = 0, mx = 0;
    for(int i=0; i<n; i++)
    {
    	if ((mn < mx && arr[i] < arr[mx]) || (mx < mn && arr[i] > arr[mn]))
    	{
    		cout << 3 << endl << mn + 1 << " " << mx + 1 << " " << i + 1 << endl;
    		return 0;
    	}
    	if (arr[mx] < arr[i])
			mx = i;
		if (arr[mn] > arr[i])
			mn = i;
    }
    cout << 0 << endl;
	return 0;
}
