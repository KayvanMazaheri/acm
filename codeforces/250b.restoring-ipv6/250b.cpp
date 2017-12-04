// K1
// :)

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>

#define MAXN (int(1e9))
#define EPS 1e-8
#define PI 3.141592653589793
#define point pair <int , int>
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		string short_inp;
		cin >> short_inp;
		//short_inp += ":";
		string sec[8];
		if (short_inp.find("::") != string::npos)
		{
			int pos =short_inp.find("::");
			string s1 = short_inp.substr(0, pos) + ":";
			string s2 = ":" + short_inp.substr(pos + 2);

			int sec_num =0;
			while(s1.find(":") != string::npos)
			{
				//cerr << short_inp << endl;
				int pos = s1.find(":");
				sec[sec_num] = s1.substr(0, pos);
				//cerr << sec[sec_num] << endl;
				s1 = s1.substr(pos+1);
				sec_num ++;
			}
			//cerr << sec_num << endl;
			//cerr << endl;
			sec_num = 7;
			//reverse(s2.begin(), s2.end());
			while(s2.rfind(":") != string::npos)
			{
				//cerr << short_inp << endl;
				int pos = s2.rfind(":");
				sec[sec_num] = s2.substr(pos+1);
				//reverse(sec[sec_num].begin(), sec[sec_num].end());
				//cerr << sec[sec_num] << endl;
				s2 = s2.substr(0, pos);
				sec_num --;
			}
			//cerr << sec_num << endl;
			for(int i=0; i<8; i++)
			{
				while (sec[i].size() < 4)
					sec[i] = "0" + sec[i];
				cout << sec[i];
				if (i < 7)
				cout << ":";

			}
			cout << endl;

		}
		else
		{
			short_inp += ":";
			int sec_num =0;
			while(short_inp.find(":") != string::npos)
			{
				//cerr << short_inp << endl;
				int pos = short_inp.find(":");
				sec[sec_num] = short_inp.substr(0, pos);
				//cerr << sec[sec_num] << endl;
				short_inp = short_inp.substr(pos+1);
				sec_num ++;
			}
			for(int i=0; i<8; i++)
			{
				while (sec[i].size() < 4)
					sec[i] = "0" + sec[i];
				cout << sec[i];
				if (i < 7)
				cout << ":";

			}
			cout << endl;
		}
	}
}
