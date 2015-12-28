#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 123;

int n, m, k;

int weight     [MAXN];
int cost       [MAXN];
int dp_weight  [MAXN];
int dp_cost    [MAXN];

int total_weight = 0;
int total_cost   = 0;

int hang_weight = 0;
int final_head  = -1;
int final_tail  = -1;
int final_cost  = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
        cin >> weight[i] >> cost[i];

    reverse(weight, weight + n);
    reverse(cost, cost + n);

    for(int i = 0; i<n; i++)
    {
        dp_weight[i] =   (i?dp_weight[i-1]:0) + weight[i];
        dp_cost  [i] =   (i?dp_cost  [i-1]:0) + cost  [i];
    }

    total_weight = dp_weight[n-1];
    total_cost   = dp_cost  [n-1];

    for(int i=0; i<=n-m; i++)
    {
        int head = i;
        hang_weight = dp_weight[i+m-1] - dp_weight[i] + weight[i];
        int min_weight_need = (hang_weight + k - 1) / k;
        int val_to_search = min_weight_need + dp_weight[i+m-1];
        int tail = lower_bound(dp_weight, dp_weight + n, val_to_search) - dp_weight;

        if (tail == n) break;

        int val = ((total_cost - dp_cost[tail]) + dp_cost[head]) - cost[head];
        if(val > final_cost)
        {
            final_cost = val;
            final_head = head;
            final_tail = tail;
        }

    }

    if (final_cost == 0)
        cout << 0 << " " << 0 << endl;
    else
    {
        cout << n - (final_tail - final_head + 1) << " " << final_cost << endl;

        for(int i=0; i<final_head; i++) cout << "H";
        for(int i=0; i <n - final_tail - 1; i++ ) cout << "T" ;
        cout << endl;
    }
    return 0;
}
