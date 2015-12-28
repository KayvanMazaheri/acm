#include <iostream>
#include <string>

using namespace std;

int num[3];
int require[3];

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    string pass;
    cin >> pass;
    for(int i=0; i<pass.size(); i++)
        num[pass[i]-'0']++;

    require[0] = a - num[0];
    require[1] = b - num[1];

    if (a+b > pass.size() || n != pass.size() || a+b > n )
    {
        cout << -1 << endl;
        return 0;
    }
    if (require[0] == 0 && require[1] == 0)
    {
        cout << 0 << endl;
        cout << pass << endl;
        return 0;
    }
    string result = pass;
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if (result[i] == '0' && require[0] < 0)
        {
            if (require[1] > 0)
            {
                count++;
                result[i] = '1';
                require[1] --;
                require[0] ++;
            }
            else if (require[1] <= 0)
            {
                count++;
                result[i] = '2';
                require[0] ++;
            }
        }
	}
    for(int i=0; i<n; i++)
    {
        if (result[i] == '1' && require[1] < 0)
        {
            if (require[0] > 0)
            {
                count++;
                result[i] = '0';
                require[0] --;
                require[1] ++;
            }
            else if (require[0] <= 0)
            {
                count ++;
                result[i] = '2';
                require[1] ++;
            }
        }
    }
   for(int i=0; i<n; i++)
    {
	if (result[i] == '2')
        {
            if (require[0] > 0)
            {
                count ++;
                result[i] = '0';
                require[0] --;
            }
            else if (require[1] > 0)
            {
                count ++;
                result[i] = '1';
                require[1] --;
            }
        }
//		cerr << i << endl;
//		cerr << result << endl;
//		cerr << require[0] << "  " << require[1] << endl << endl;
    }
    if (!(require[0] == 0 && require[1] == 0))
    {
        cout << -1 << endl;
        return 0;
    }
    cout << count << endl;
    cout << result << endl;
    return 0;
}
