#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> vec;

bool check()
{
    if (vec[0] == 0)
        return false;
    unsigned long long result = 0;
    for(int i=0; i<vec.size(); i++)
        (result *= 10) += vec[i];
    if ((result % 17) == 0)
        return true;
    return false;
}

int main()
{
    string inp;
	cin >> inp;
    for(int i=0; i<inp.size(); i++)
        vec.push_back(inp[i] - '0');
    sort (vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    do
    {
        if (check())
        {
            for(int i=0; i<vec.size(); i++)
                cout << vec[i];
            cout << endl;
            return 0;
        }
    }
    while(prev_permutation(vec.begin(), vec.end()));
    cout << -1 << endl;
    return 0;
}
