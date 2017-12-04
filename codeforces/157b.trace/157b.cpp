#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>

#define MAXN 1e9
#define EPS 1e-8
#define PI 3.141592653589793
#define point pair <int , int>
#define X first
#define Y second

using namespace std;

vector <int> circle ;
vector <int> c;
bool mark[100000];

int main()
{
	int n;
	cin >> n;
	int inp;
	double result = 0;
	for(int i=0; i<n; i++)
	{
		cin >> inp;
		circle.push_back(inp);
	}

	sort(circle.begin(), circle.end());
	for(int i=0; i<circle.size(); i++)
	{
		if(!mark[circle[i]])
		{
			mark[circle[i]] = true;
			c.push_back(circle[i]);
		}
	}
	double area = c[c.size()-1] * c[c.size()-1] * PI ;
	result += area ;
	//mark[circle.size()-1] = true;
	for (int i=c.size()-2; i>=0; i--)
	{
		double area = c[i] * c[i] * PI ;
		if (n%2 == (i+1)%2)
			result += area ;
		else
			result -= area;
	}
	cout << fixed << setprecision(15) << result << endl;
	return 0;
}
