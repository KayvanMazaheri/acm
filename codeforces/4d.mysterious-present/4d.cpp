#include <iostream>
#include <algorithm>
#include <vector>

#define X first
#define Y second

using namespace std;

const int MAX_N = 5e3 + 123;

typedef pair <int, int> point;
typedef pair <point, int> tp;
vector <tp> vec;
point dp[MAX_N];
vector <int> result;

bool CMP(tp a, tp b)
{
	if ((long long) a.X.X * (long long) a.X.Y == (long long) b.X.X * (long long) b.X.Y)
		return a.X.X < b.X.X;
	return (long long) a.X.X * (long long) a.X.Y < (long long) b.X.X * (long long) b.X.Y;
}



int main()
{
	int n, x0, y0;
	cin >> n >> x0 >> y0;
	for(int i=0; i<n; i++)
	{
		point inp;
		cin >> inp.X >> inp.Y;
		if (inp.X > x0 && inp.Y > y0)
			vec.push_back(make_pair(inp, i));
	}
	sort(vec.begin(), vec.end(), CMP);
	for(int i=0; i<vec.size(); i++)
	{
		dp[vec[i].Y] = make_pair (1, -1);
		for(int j=0; j<i; j++)
		{
			if (vec[j].X.X < vec[i].X.X && vec[j].X.Y < vec[i].X.Y)
				if (dp[vec[j].Y].X + 1 > dp[vec[i].Y].X)
					dp[vec[i].Y] = make_pair (dp[vec[j].Y].X + 1, vec[j].Y);
		}
	}

//	cerr << endl << "\t Test data :" << endl;
//	for(int i=0; i<vec.size(); i++)
//		cerr << i << ": " << vec[i].Y << "  " << vec[i].X.X << " " << vec[i].X.Y << "    sz : " << dp[vec[i].Y].X << "  par : " << dp[vec[i].Y].Y << endl;

	int _mx = max_element(dp, dp+MAX_N) - dp;
	int pos = _mx;
	while(pos != -1 && dp[_mx].X)
	{
		result.push_back(pos + 1);
		pos = dp[pos].Y;
	}
	reverse(result.begin(), result.end());
	cout << result.size() << endl;
	for(int i=0; i<result.size(); i++)
		cout << result[i] << " ";
	cout << endl;
	return 0;

}
