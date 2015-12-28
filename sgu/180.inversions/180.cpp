#include <iostream>
#include <set>
using namespace std;

const int MAXN = 1e5;

long long result = 0;
int arr[MAXN];

void merge_sort(int start, int end)
{
    if(end - start == 1)
        return;
    int mid = (end + start) / 2;
    merge_sort(start, mid);
    merge_sort(mid, end);
    int buff[end - start + 3];
    int pointer = 0;
    int p1 = start, p2 = mid;
    while(1)
    {
        if(p1 < mid && p2 < end && arr[p1] <= arr[p2])
        {
            buff[pointer] = arr[p1];
            p1++;
        }
        else if(p1 <= mid && p2 < end && arr[p2] < arr[p1])
        {
            result += mid - p1 ;
            buff[pointer] = arr[p2];
//            cerr << start << " " << mid << " " << end << endl;
            p2++;
        }
        else if(p1 < mid)
        {
            buff[pointer] = arr[p1];
            p1++;
        }
        else if (p2 < end)
        {
            buff[pointer] = arr[p2];
            p2++;
        }
        else
            break;
        pointer++;
    }
    for(int i=start; i<end; i++)
        arr[i] = buff[i-start];
    return;

}

int main()
{
	ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    merge_sort(0, n);
    cout << result << endl;
    return 0;
}
