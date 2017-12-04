// In the name of God
// :)

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define ll long long
#define point pair <int, int>
#define X first
#define Y second
#define EPS 1e-8
#define MAXN int(1e4)

using namespace std;

struct message
{
    string from;
    string to;
    int time;
};

bool mark[MAXN];
message msg[MAXN];
int n, d, result;
vector <pair <string, string> > friends;

int main()
{
    cin >> n >> d;
    for(int i=0; i<n; i++)
    {
        string from, to;
        int time;
        cin >> from >> to >> time;
        msg[i].from = from;
        msg[i].to = to;
        msg[i].time = time;
    }
	for(int i=0; i<n; i++)
	{
		if (mark[i])
			continue;
		for(int j=i; j>=0; j--)
		{
			if (mark[j])
				continue;
			if (msg[i].from == msg[j].to && msg[i].to == msg[j].from){
				if ((0 < abs(msg[i].time - msg[j].time)) && (abs(msg[i].time - msg[j].time) <= d))
				{
					result ++;
					friends.push_back(make_pair(msg[i].from, msg[i].to));
					for(int k=0; k<n; k++)
						if ((msg[i].from == msg[k].from && msg[i].to == msg[k].to) || (msg[j].from == msg[k].from && msg[j].to == msg[k].to))
							mark[k] = true;
					break;

				}
			}
		}
	}
	cout << result << endl;
	for(int i=0; i<friends.size(); i++)
		cout << friends[i].X << " " << friends[i].Y << endl;
	return 0;
}

