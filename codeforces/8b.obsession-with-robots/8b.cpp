#include <iostream>
#include <algorithm>

#define X first
#define Y second

using namespace std;

typedef pair <int, int> point;
bool mark[300][300];

int main()
{
    string inp;
    point pos = make_pair(150, 150);
    cin >> inp;
    bool flag =  true;
    mark[pos.X][pos.Y] = true;
    for(int i=0; i<inp.size(); i++)
    {
    	mark[pos.X][pos.Y] = true;
        if (inp[i] == 'R')
            pos.X ++;
        else if (inp[i] == 'L')
            pos.X --;
        else if (inp[i] == 'U')
            pos.Y ++;
        else if (inp[i] == 'D')
            pos.Y --;
        flag *= !(mark[pos.X][pos.Y]);
        if (inp[i] != 'R') flag *= !(mark[pos.X - 1][pos.Y]);
        if (inp[i] != 'L') flag *= !(mark[pos.X + 1][pos.Y]);
        if (inp[i] != 'U') flag *= !(mark[pos.X][pos.Y - 1]);
        if (inp[i] != 'D') flag *= !(mark[pos.X][pos.Y + 1]);

    }
    cout << (flag ? "OK" : "BUG") << endl;
    return 0;
}
