#include <iostream>
#include <algorithm>
#include <vector>

#define X first
#define Y second

using namespace std;

typedef pair <int, int> point;
vector <string> vec;

int main()
{
    point s, t;
    char x, y;
    cin >> x >> y;
    s.X = x - 'a' + 1;
    s.Y = y - '0';
    cin >> x >> y;
    t.X = x - 'a' + 1;
    t.Y = y - '0';
    while(s != t)
    {
        if (s.X < t.X )
        {
            s.X ++;
            if ( s.Y < t.Y)
            {
                s.Y ++;
                vec.push_back("RU");
            }
            else if (s.Y > t.Y)
            {
                s.Y --;
                vec.push_back("RD");
            }
            else
                vec.push_back("R");
        }
        else if (s.X > t.X)
        {
            s.X --;
            if (s.Y < t.Y)
            {
            	s.Y ++;
            	vec.push_back("LU");
            }
            else if (s.Y > t.Y)
            {
            	s.Y --;
            	vec.push_back("LD");
            }
            else
				vec.push_back("L");
        }
        else
        {
        	if (s.Y < t.Y)
        	{
        		s.Y++;
        		vec.push_back("U");
        	}
        	else
        	{
        		s.Y--;
        		vec.push_back("D");
        	}
        }
    }
    cout << vec.size() << endl;
    for(int i=0; i<vec.size(); i++)
		cout << vec[i] << endl;
	return 0;

}
