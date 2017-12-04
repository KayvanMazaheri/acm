#include <iostream>
#include <algorithm>
#include <vector>

#define X first
#define Y second
#define EPS ((double)1e-8)


using namespace std;

struct player
{
	string name;
	int point;
	int better, not_worse;
};

vector <player> vec;
vector <pair <string, string> > result;

int is_in_vec(string name)
{
	for(int i=0; i<vec.size(); i++)
		if (vec[i].name == name)
			return i;
	return -1;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		string name;
		int point;
		cin >> name >> point;
		if (is_in_vec(name) == -1)
		{
			player buff;
			buff.name = name;
			buff.point = point;
			buff.not_worse = 0;
			buff.better = 0;
			vec.push_back(buff);
		}
		else
			vec[is_in_vec(name)].point = max (point, vec[is_in_vec(name)].point);
	}
	n = vec.size();
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			((vec[j].point > vec[i].point)? vec[i].better : vec[i].not_worse ) ++;
	for(int i=0; i<n; i++)
	{
		//swap(vec[i].not_worse, vec[i].better);
		pair <string, string> buff;
		buff.Y = vec[i].name ;
		if (50 * n < 100 * vec[i].better)
			buff.X = "noob";
		else if ((50 * n <= 100 * vec[i].not_worse)&&(20 * n < 100 * vec[i].better))
			buff.X = "random";
		else if ((80 * n <= 100 * vec[i].not_worse)&&(10 * n < 100 * vec[i].better))
			buff.X = "average";
		else if ((90 * n <= 100 * vec[i].not_worse)&&(1 * n < 100 * vec[i].better))
			buff.X = "hardcore";
		else if (99 * n <= 100 * vec[i].not_worse)
			buff.X = "pro";
		result.push_back(buff);
	}
	sort (result.begin(), result.end());
	cout << n << endl;
	for(int i=0; i<n; i++)
		cout << result[i].Y << " " << result[i].X << endl;
	cout << endl;

}
