#include <iostream>
#include <string>
using namespace std;

const int MAXN = 25;
unsigned long long list [MAXN][12];


int main()
{

    int s;
    cin >> s;
    for (int i=0; i<10; i++)
    {
        list[1][i] = 1;
        list[0][i] = 1;
    }
    list[1][10] = 10;


    for(int i=2; i < MAXN ; i++)
    {
        list[i][0] = 1;
        for(int j=1; j<10; j++)
            list[i][j] = list[i][j-1] + list[i-1][j];

        for(int j=0; j<10; j++)
            list[i][10] += list[i][j];
        //cout << list[i][10] << ", " ;
    }
    unsigned long long result = 0;
    for(int i=0; i<s; i++)
        for(int k=0; k<10; k++)
            result += list[i+1][k] * list[s-i][k];
    unsigned long long _result = 0;
    for(int i=0; i<s-1; i++)
        for(int k=0; k<10; k++)
            _result += list[i+1][k] * list[s-i-1][k];
    cout <<  result - _result << endl;
}
