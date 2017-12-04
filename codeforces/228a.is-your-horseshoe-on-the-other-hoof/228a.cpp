#include <iostream>
using namespace std;

int inp[4];
bool mark[4];
int result = 0;

int main()
{
    for(int i=0; i<4; i++)
        cin >> inp[i];
    for(int i=0; i<4; i++)
    {
        if (!mark[i])
        {
            for(int j=i+1; j<4; j++)
                if (inp[j] == inp[i])
                    mark[j] = true;
        }
        else
            result ++;
    }
    cout << result << endl;

    return 0;
}
