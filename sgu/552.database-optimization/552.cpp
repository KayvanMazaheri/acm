// K1
// :)

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
#include <cmath>
#include <iomanip>
#include <map>

#define MAXN (int(1e7 + 123))
#define EPS 1e-8
#define PI 3.141592653589793
#define point pair <int , int>
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;

map <string, int> mip;


int make_hash(string str)	// returns an integer between 0 and Q for each string
{
        int Q = 1000000 + 3;
        int P = 33;
        int result = 0;
        int curP = 1;
        for (int i=0; i<str.size(); i++)
        {
                long long buffer = 0;
                buffer = (((((str[i] - 'a')+1) % Q) * curP) % Q);
                curP = (((long long) curP) * P) % Q ;
                (result += buffer) %= Q;
        }
        return ((result + Q)+1) % Q + Q ;
}

short int table[MAXN];	// how many objects added to table with same set of properties

void make_sub_string(string s, int h, int MAX_H, vector <string> &vec)	// to make all subsets from a set
{
        if (h == MAX_H)
        {
		vec.push_back(s);
                return;
        }
	make_sub_string(s+"1", h+1, MAX_H, vec);
        make_sub_string(s+"0", h+1, MAX_H, vec);
        return;
}

void get_input()
{
	int n;
        cin >> n;
        for(int i=0; i<n; i++)
        {
                int k;
                cin >> k;
                vector <string> properties;
                for(int j=0; j<k; j++)
                {
                        string inp;
                        cin >> inp;
                        inp = "*" + inp;
                        properties.push_back(inp);
                }
                sort(properties.begin(), properties.end());
		vector <string> buff;
		make_sub_string("", 0, k, buff);
		for(int j=0; j<buff.size(); j++)
		{
			string q;
			for(int l=0; l<k; l++)
				if (buff[j][l] == '1')
					q += properties[l] + "~";
                        //cerr << "%%%" << endl;
                        //cerr << make_hash(q, 0) << endl;
			mip[q]++;
		}
        }
        return;
}

int main()
{
        get_input();
        int m;
        cin >> m;
        for(int i=0; i<m; i++)
        {
                int k;
                cin >> k;
                vector <string> query;
                for(int j=0; j<k; j++)
                {
                        string inp;
                        cin >> inp;
                        inp = "*" + inp;
                        query.push_back(inp);
                }
                sort(query.begin(), query.end());
                string q;
                for(int j=0; j<k; j++)
			q+= query[j] + "~";
		cout << mip[q] << endl;
        }
	return 0;
}
