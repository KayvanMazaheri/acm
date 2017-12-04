#include <iostream>
#include <map>
using namespace std;

const int MAXN = 1e5 + 123;

int arr[MAXN];
map <int, int> my_map;

int main()
{
    int n, k;
    cin >> n >> k;
    int count = 0;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        my_map[arr[i]] ++;
        if (my_map[arr[i]] == 1)
            count ++;
    }
    int head = 0, tail = n-1;
    while(!(count == k && my_map[arr[head]] == 1) && head != tail)
    {
        my_map[arr[head]] --;
        if (my_map[arr[head]] == 0)
            count --;
        head ++;
    }
    while(!(count == k && my_map[arr[tail]] == 1) && head != tail)
    {
        my_map[arr[tail]] --;
        if (my_map[arr[tail]] == 0)
            count --;
        tail --;
    }
    if (count == k)
        cout << head + 1 << " " << tail + 1 << endl;
    else
        cout << -1 << " " << -1 << endl;
	return 0;
}
