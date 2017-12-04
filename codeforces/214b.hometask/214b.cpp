#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> vec;
int sum = 0;

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int inp;
        cin >> inp;
        vec.push_back(inp);
        sum += inp;
    }
    sort(vec.begin(), vec.end());
    //cerr << sum % 3 << endl;

    if (sum % 3)
        for(int i=0; i<n; i++)
            if (vec[i] % 3 == sum % 3)
            {
                //cerr << vec[i] << endl;
                sum -= vec[i];
                vec.erase(vec.begin()+i);
                break;
            }
    int t = 0;
    if (sum % 3 == 1)
    {
        for(int i=0; i<vec.size(); i++)
        {
            if (vec[i] % 3 == 2)
            {
                sum -= vec[i];
                vec.erase(vec.begin()+i);
                i--;
                t ++;
                if (t == 2)
                    break;
            }
        }
    }
    t = 0;
    if (sum % 3 == 2)
    {
        for(int i=0; i<vec.size(); i++)
        {
            if (vec[i] % 3 == 1)
            {
                sum -= vec[i];
                vec.erase(vec.begin()+i);
                i--;
                t ++;
                if (t == 2)
                    break;
            }
        }
    }
    if (vec[0] != 0 || sum % 3)
    {
        cout << -1 << endl;
        return 0;
    }
	reverse (vec.begin(), vec.end());
    if (vec[0] == 0 && vec.size() > 1)
    {
    	cout << 0 << endl;
    	return 0;
    }

    for(int i=0; i<vec.size(); i++)
        cout << vec[i] ;
    cout << endl;
    return 0;

}
