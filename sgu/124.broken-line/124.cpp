#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Line
{
    inline void get_ac()
		{
			if (x2 - x1)
				a = double(y2 - y1) / double(x2 - x1);
			else
				is_x_only = true;
			c = double(y2) - double(a * x2);
			return;
		}
public :
	int x1, x2;
	int y1, y2;
	double a, c;
	bool is_x_only;

	bool cross(Line &b)
	{
		double x_r, y_r, t;
		if (is_x_only)
		{
				x_r = x1;
				y_r = b.a * x_r + b.c;
				//cerr << "#1" << endl;
		}
		else
		{
		t = a - b.a;

		if (t == 0)
				return false;
		x_r = (b.c - c) / t;
		y_r = a * x_r + c;
		//cerr << x1 << " " << y1 << "   " << x2 << " " << y2 << " :  " << x_r << " " << y_r << endl;
		}
		if ( x1 <= x_r && x_r <= x2 && ((y1 <= y_r && y_r <= y2) || (y2 <= y_r && y_r <= y1)))
			if ( b.x1 <= x_r && x_r <= b.x2 && ((b.y1 <= y_r && y_r <= b.y2) || (b.y2 <= y_r && y_r <= b.y1)))
				return true;
		return false;
	}

	bool edge(int _x, int _y)
	{
		if (a * _x + c != _y)
			return false;
		if ( x1 <= _x && _x <= x2 && ((y1 <= _y && _y <= y2) || (y2 <= _y && _y <= y1)))
			return true;
		return false;
	}

	Line (int _x1 = -1000, int _y1 = -1000, int _x2 = -1000, int _y2 = -1000)
	{
		x1 = _x1;
		x2 = _x2;
		y1 = _y1;
		y2 = _y2;
		if (x1 > x2)
		{
			swap(x1, x2);
			swap(y1, y2);
		}
		is_x_only = false;
		get_ac();
	}
};

vector <Line> vec;
const int np = -165823;

int main()
{
	int k, X, Y, result = 0;
	cin >> k;
	for(int i=0; i<k; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2 ;
		Line l(x1, y1, x2, y2);
		vec.push_back(l);
	}
	cin >> X >> Y;
	Line tg (X, Y, np - 9263, np  + 1532 );
	for(int i=0; i<k; i++)
		if (vec[i].edge(X, Y))
		{
			cout << "BORDER" << endl;
			return 0;
		}
	for(int i=0; i<k; i++)
		if (vec[i].cross(tg))
			result ++;
	int edge_cross = 0;
	for(int i=0; i<k; i++)
	{
		if(tg.edge(vec[i].x1, vec[i].y1))
			edge_cross ++;

		if(tg.edge(vec[i].x2, vec[i].y2))
		edge_cross ++;
	}
	edge_cross /= 2;
	result -= edge_cross;
	if (result % 2)
		cout << "INSIDE";
	else
		cout << "OUTSIDE";
	cout << endl;
	return 0;

}
