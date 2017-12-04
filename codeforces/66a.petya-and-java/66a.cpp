#include <iostream>
#include <string>
using namespace std;

string pos[4] = {"128", "32768",  "2147483648", "9223372036854775808"};
string neg[4] = {"129", "32769",  "2147483649", "9223372036854775809"};

int main()
{
    for(int i=0; i<4; i++)
        while(pos[i].size() < 100)
        {
            pos[i] = "0" + pos[i];
            neg[i] = "0" + neg[i];
        }
    string inp;
    cin >> inp;
    bool flag = (inp[0] == '-');
    if (inp[0] == '-') inp = inp.substr(1);

    while(inp.size() < 100 )
        inp = "0" + inp;
    if (inp < (flag ? neg[0] : pos[0]))
        cout << "byte" << endl;
    else if (inp < (flag ? neg[1] : pos[1]))
        cout << "short" << endl;
    else if (inp < (flag ? neg[2] : pos[2]))
        cout << "int" << endl;
    else if (inp < (flag ? neg[3] : pos[3]))
        cout << "long" << endl;
    else
        cout << "BigInteger" << endl;
	return 0;
}
