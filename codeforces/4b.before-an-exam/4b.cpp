#include <iostream>
#include <algorithm>

#define X first
#define Y second

using namespace std;

const int MAX_N = 30 + 3;

pair <int, int> day[MAX_N];

int main()
{
    int d, sumTime;
    cin >> d >> sumTime;
    for(int i=0; i<d; i++)
        cin >> day[i].X >> day[i].Y;
    int minSum = 0;
    int maxSum = 0;
    for(int i=0; i<d; i++)
    {
        minSum += day[i].X;
        maxSum += day[i].Y;
    }
    if (!(minSum <= sumTime && sumTime <= maxSum))
        cout << "NO";
    else
    {
        cout << "YES" << endl;
        for(int i=0; i<d; i++)
            for(int j=day[i].X; j<=day[i].Y; j++)
                if (minSum - day[i].X <= sumTime - j && sumTime - j <= maxSum - day[i].Y)
                {
                    minSum -= day[i].X;
                    maxSum -= day[i].Y;
                    sumTime -= j;
                    cout << j << " ";
                    break;
                }
    }
    cout << endl;
    return 0;
}
