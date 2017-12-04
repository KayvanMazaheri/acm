// K1
// :)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

    vector <int> f_vec;
    int dis[20000];
    int f[20000];
    int time = 0, av_f = 0;
    long long result = 0, max_fuel = 0, req = 0;;
    int m, k;
    cin >> m >> k;
    for (int i=0; i<m; i++)
        cin >> dis[i];

    for(int i=0; i<m; i++)
    {
        int fuel;
        cin >> f[i];
        max_fuel+= f[i];
    }

    for(int i=0; i<m; i++)
    {
        req += dis[i];
        time += dis[i];
        av_f += f[i];
        f_vec.push_back(f[i]);
        sort(f_vec.begin(), f_vec.end());
        while (req > av_f)
        {
            time += k;
            av_f += f_vec[f_vec.size()-1];
        }
    }

    cout << time << endl;
    return 0;
}
