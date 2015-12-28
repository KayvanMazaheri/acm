#include <iostream>
using namespace std;

const int MAXN = 1e4 + 123;

int arr[MAXN];
int percent[MAXN];
bool mark[MAXN];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    long long sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];
    for(int i=0; i<n; i++)
    {
        percent[i] = (100 * arr[i] ) / (sum);
        if((100 * arr[i]) % sum == 0) mark[i] = true;
    }
    int res_sum = 0;
    for(int i=0; i<n; i++)
        res_sum += percent[i];
	for(int i=0; i<n && res_sum < 100 ; i++)
		if(!mark[i])
		{
			mark[i] = true;
			percent[i]++;
			res_sum++;
		}
	if(res_sum != 100)
		cout << "No solution";
	else
		for(int i=0; i<n; i++)
			cout << percent[i] << " " ;
	cout << endl;

    return 0;
}
