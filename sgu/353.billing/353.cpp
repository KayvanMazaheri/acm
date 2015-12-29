#include <iostream>

using namespace std;

int main()
{
    int  n, k1, k2, p1, p2, p3, sec = 0;
    cin >> n >> k1 >> k2 >> p1 >> p2 >> p3;
    if (n >= p1)
    {
        n-=p1;
        sec += k1;
        for(int i=0; i<k2 && n >0; i++)
        {
            sec ++;
            n-=p2;
        }
        while(n > 0)
        {
            n-=p3;
            sec ++;
        }
    }
    cout << sec << endl;
    return 0;
}
