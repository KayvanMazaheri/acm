#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector <string> vec;

int main()
{
//    freopen("input.txt", "r", stdin);
    string line;
    while(getline(cin, line))
        vec.push_back(line);
    int _mx = -1;
    for(int i=0; i<vec.size(); i++)
        _mx = max (_mx, int(vec[i].size()));
	bool flag = false;
    for(int i=0; i<vec.size(); i++)
	{
		int sz = (_mx - vec[i].size()) / 2;
			for(int j=0; j<sz; j++)
				vec[i] += " ";
			for(int j=0; j<sz; j++)
				vec[i] = " " + vec[i];
			if ((_mx - vec[i].size()) && !flag)
			{
				flag = true;
				vec[i] += " ";
			}
			else if ((_mx - vec[i].size()) && flag)
			{
				flag = false;
				vec[i] = " " + vec[i];
			}
	}
    for(int i=0; i< 2 + _mx; i++)
        cout << "*";
    cout << endl;
    for(int i=0; i<vec.size(); i++)
        cout << "*" << vec[i] << "*" << endl;
    for(int i=0; i< 2 + _mx; i++)
        cout << "*";
    cout << endl;
    return 0;
}
