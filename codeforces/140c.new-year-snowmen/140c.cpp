#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second

using namespace std;

map <int, int> mp;

struct CMP
{
    bool operator () (const int &a, const int &b) const
    {
        if (mp[a] == mp[b])
            return (a > b);
        return (mp[a] > mp[b]);
    }
};

typedef set<int, CMP>::iterator ITR;

set <int, CMP> my_set;
vector <int> result;

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int inp;
        cin >> inp;
        my_set.erase(inp);
        mp[inp] ++;
        my_set.insert(inp);
    }
//    for (ITR i = my_set.begin(); i != my_set.end(); i++)
//		cerr << *i << " ";
//	cerr << endl;
//	return 0;

    while (my_set.size() > 2)
    {
        int buff[3];
        for(int i=0; i<3; i++)
        {
            ITR it = my_set.begin();
            buff[i] = *(it);

//             cerr << buff[i] << "   :   " << mp[buff[i]] << endl;
            my_set.erase(it);
            mp[*it] --;
        }
        for(int i=0; i<3; i++)
            if (mp[buff[i]] > 0)
                my_set.insert(buff[i]);
        sort(buff, buff+3);
        result.push_back(buff[2]);
        result.push_back(buff[1]);
        result.push_back(buff[0]);
//        cerr << "Err : " << buff[2] << " " << buff[1] << " " << buff[0] << endl;
    }

    cout << result.size() / 3 << endl;
    for(int i=0; i<result.size(); i+=3)
        cout << result[i] << " " << result[i+1] << " " << result[i+2] << endl;
    return 0;
}
