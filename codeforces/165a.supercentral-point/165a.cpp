#include <iostream>
#include <algorithm>
#include <vector>

#define X first
#define Y second

using namespace std;

typedef pair <int, int> point;

vector <point> vec;

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        point inp;
        cin >> inp.X >> inp.Y;
        vec.push_back(inp);
    }
    int result = 0;
    for(int i=0; i<n; i++)
    {
        bool up = false, right = false, low = false, left = false;
        for(int j=0; j<n; j++)
        {
            left += vec[i].X > vec[j].X && vec[i].Y == vec[j].Y;
            right += vec[i].X < vec[j].X && vec[i].Y == vec[j].Y;
            low += vec[i].X == vec[j].X && vec[i].Y > vec[j].Y;
            up += vec[i].X == vec[j].X && vec[i].Y < vec[j].Y;
        }
        result += (up && right && low && left);
    }
    cout << result << endl;
    return 0;
}
