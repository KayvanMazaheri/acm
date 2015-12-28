#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 123;
const int INF = 5000 + 123;
int arr[MAXN][MAXN];
int dp[MAXN][MAXN];
bool update[MAXN][MAXN];

int main()
{
    int f, v;
    int dp_u, dp_l;
    cin >> f >> v ;
    for(int i=0; i<MAXN; i++)
        for(int j=0; j<MAXN; j++){
            arr[i][j] = -INF;
            dp[i][j] = -INF;
        }
	for(int j=0; j<MAXN; j++)
		dp[0][j] = 0;
    for(int i=1; i<=f; i++)
        for(int j=1; j<=v; j++)
            cin >> arr[i][j];
	//dp[1][1] = arr[1][1];
    for(int i=1; i<=f; i++)
    {
        for(int j=1; j<=v; j++)
        {
//        	if (i==1 && j==1)
//				continue;
        	dp_u = dp[i-1][j-1] + arr[i][j];
        	dp_l = dp[i][j-1];
        	if (dp_u > dp_l)
        	{
        		update[i][j] = true;
        		dp[i][j] = dp_u;
        	}
        	else
        	{
        		update[i][j] = false;
        		dp[i][j] = dp_l;
        	}
        	//dp[i][j] = max(dp_u, arr_u);
        }
    }

    vector <int> ans;
    int i = f;
    int j = v;
    while(i)
    {
    	while(!update[i][j])
			j--;
		ans.push_back(j);
		i--;
		j--;
    }
    cout << dp[f][v] << endl;

    for(int k = ans.size()-1; k>=0; k--)
		cout << ans[k] << " " ;
cout << endl;

//	for(int i=1; i<=f; i++)
//    {
//        for(int j=1; j<=v; j++)
//        {
//        	cerr << update[i][j] << " ";
//        }
//        cerr << endl;
//    }
    return 0;
}
