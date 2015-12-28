#include <iostream>
#include <map>

using namespace std;

map <long long, long long> my_map;


int main()
{
    long long x, y;
    cin >>  x >> y;
    x %= y;
    long long len = 0;
    while (1)
    {
        if (!x)
        {
            cout << len << " 0" << endl;
            break;
        }
        if (my_map.find(x) != my_map.end())
        {
            cout << my_map[x]  << " " << len - my_map[x] << endl;
            break;
        }

        my_map[x] = len;
        x *= 10;
        len ++;
        if (x / y == 0)
            continue;
        x %= y;

    }
    return 0;
}
