#include <iostream>
#include <algorithm>
#include <map>
#include <set>

#define X first
#define Y second

using namespace std;

typedef pair<int, int> point;

const int MAXN = 1e5 + 123;

map <int, int> mp;
set <int> st;

int arr[MAXN];

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    for(int i=0; i<n; i++)
    {
        int inp = arr[i];
        mp[inp]++;
        if (i >= k)
        {
            mp[arr[i-k]]--;
            if (mp[arr[i-k]] == 1)
                st.insert(arr[i-k]);
            else
                st.erase(arr[i-k]);
        }
        if (mp[inp] == 1)
            st.insert(inp);
        else
            st.erase(inp);
        if (i +1 >= k)
        {
            if (st.empty())
                cout << "Nothing" << endl;
            else
                cout << *st.rbegin() << endl;
        }

    }
    return 0;
}
