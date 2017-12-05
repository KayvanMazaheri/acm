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

#define EPS 1e-8
#define PI 3.141592653589793
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;

typedef pair<int, int> point;
typedef set<int>::iterator ITR;
const int MAXN = 2e5 + 123;

map<string, string> user_pass;
map<string, int> user_stat;

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		string cmd, user, pass;
		cin >> cmd >> user;
		if(cmd != "logout")
			cin >> pass;
		if(cmd == "register")
		{
			if(user_stat[user] == 0)
			{
				user_stat[user] = 1;
				user_pass[user] = pass;
				cout << "success: new user added" << endl;

			}
			else
				cout << "fail: user already exists" << endl;
		}
		else if (cmd == "login")
		{
			if(user_stat[user] == 0)
				cout << "fail: no such user" << endl;
			else if(pass != user_pass[user])
				cout << "fail: incorrect password" << endl;
			else if(user_stat[user] == 2)
				cout << "fail: already logged in" << endl;
			else
			{
				user_stat[user] = 2;
				cout << "success: user logged in" << endl;
			}
		}
		else if(cmd == "logout")
		{
			if(user_stat[user] == 0)
				cout << "fail: no such user" << endl;
			else if(user_stat[user] == 1)
				cout << "fail: already logged out" << endl;
			else
			{
				user_stat[user] = 1;
				cout << "success: user logged out" << endl;
			}
		}

	}

	return 0;
}
