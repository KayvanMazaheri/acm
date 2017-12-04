#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;

bool adj[MAXN][MAXN];
int num[MAXN];

vector <int> vec;

int main()
{
    int n;
    cin >> n;
    int inp_size = (n * (n-1))/2;
    inp_size --;
    for(int i=0; i<inp_size; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        num[a] ++;
        num[b] ++;
        adj[a][b] = true;
    }
    for(int i=0; i<n; i++)
        if (num[i] == n-2)
            vec.push_back(i);
    for(int i=0; i<n; i++)
    {
        if (i == vec[0] || i == vec[1])
            continue;
        if (adj[vec[0]][i] == 1 && adj[vec[1]][i] == 0)
        {
            cout << vec[0] + 1 << " " << vec[1] + 1 << endl;
            return 0;
        }
        else if (adj[vec[0]][i] == 0 && adj[vec[1]][i] == 1)
        {
            cout << vec[1] + 1 << " " << vec[0] + 1 << endl;
            return 0;
        }
    }
    cout << vec[0] + 1 << " " << vec[1] + 1 << endl;
    return 0;

}
