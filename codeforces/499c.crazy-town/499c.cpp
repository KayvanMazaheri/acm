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


#define PI 3.141592653589793
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;

typedef pair<int, int> point;
typedef set<int>::iterator ITR;
const int MAXN = 2e5 + 123;

double INF = 1e100;
double EPS = 1e-12;

double val1 = 1000006;
double val2 = -1000004;

struct PT { 
	long double x, y; 
	PT() {};
	PT(long double x, long double y) : x(x), y(y) {}
	PT(const PT &p) : x(p.x), y(p.y)    {}
	PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
	PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
	PT operator * (long double c)     const { return PT(x*c,   y*c  ); }
	PT operator / (long double c)     const { return PT(x/c,   y/c  ); }
};

long double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
long double dist2(PT p, PT q)   { return dot(p-q,p-q); }
long double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
	os << "(" << p.x << "," << p.y << ")"; 
}
bool LinesParallel(PT a, PT b, PT c, PT d) { 
	return fabs(cross(b-a, c-d)) < EPS; 
}

bool LinesCollinear(PT a, PT b, PT c, PT d) { 
	return LinesParallel(a, b, c, d)
	&& fabs(cross(a-b, a-c)) < EPS
	&& fabs(cross(c-d, c-a)) < EPS; 
}
bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
	if (LinesCollinear(a, b, c, d)) {
		if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
			dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
			if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
				return false;
			return true;
		}
		if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
		if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
		return true;
	}


	int main()
	{
		PT s,t;
		cin >> s.x >> s.y;
		cin >> t.x >> t.y;
		int n;
		cin >> n;
		int result = 0;
		for (int i = 0; i < n; ++i)
		{
			long double a, b, c;
			cin >> a >> b >> c;
			PT bigx, bigy;
			if(b != 0)
			{
				bigx.x = val1;
				bigx.y= (-(a * val1 + c)) / (b);
				bigy.x = val2;
				bigy.y = (-(a * val2 + c)) / (b);
			}
			else
			{
				bigx.y = val1;
				bigx.x= (-(b * val1 + c)) / (a);
				bigy.y = val2;
				bigy.x = (-(b * val2 + c)) / (a);
			}
			// cout << bigx << endl << bigy << endl;	
		// PT bigy(-(b * INF + c) / a,INF);
			if(SegmentsIntersect(s, t, bigx, bigy)) result ++;
			
			if(LinesCollinear(s, t, bigx, bigy)) result ++;
		}
		cout << result << endl;

		return 0;
	}