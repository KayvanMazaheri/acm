#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

const int MAXN = 1e7 + 123;
bitset <MAXN> mark;
vector <pair<int, int> > list;
vector <pair<int, int> > ans;
int n;
int counter = 0;

int d(int k)
{
    int result = k;
    while(k)
    {
        result += k%10;
        k/=10;
    }
    return result;
}

int main()
{
    for(int i=0; i<MAXN; i++)
        mark[i] = 0;
    int k;
    n = 1e7;
    cin >> n >> k;
    for(int i=1; i<=n; i++)
        mark[d(i)] = true;
	for(int i=1; i<=n; i++)
		if (!mark[i])
			counter ++;
	cout << counter << endl;
    for(int i=0; i<k; i++)
    {
        int sk;
        cin >> sk;
        list.push_back(make_pair(sk, i));
    }
    sort(list.begin(), list.end());
    int pt = 1;
    int pk = 0;
    int sn = 1;
    while(pk < k)
    {
        while(sn != list[pk].first)
        {
        	pt++;
            while(mark[pt])
                pt++;
            sn ++;
        }
        ans.push_back(make_pair(list[pk].second, pt));
        pk++;

    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++)
        cout << ans[i].second << " ";
    cout << endl;
//	for(int i=1; i<MAXN && list.size() < 5e3; i++)
//		if (!mark[i])
//			list.push_back(i);
//	cout << list.size() << endl;
//	cin >> k;

    cout << endl;
    return 0;
}
