#include <iostream>
#include <algorithm>

#define X first
#define Y second

using namespace std;

const int MAXN = 1e3 + 123;

int n;
int arr[MAXN][MAXN];

typedef pair<short int, short int> point;
typedef pair<short int, char> cell;

point find_zero()
{
	point result = make_pair(-1, -1);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if (arr[j][i] == 0)
				result = make_pair(j, i);
	return result;
}


point get_val(int a)
{
    int buff = a;
    point result = make_pair(0, 0);
    while(buff && buff % 5 == 0)
    {
        buff /= 5;
        result.Y ++;
    }
    buff = a;
    while(buff && buff % 2 == 0)
    {
        buff /= 2;
        result.X ++;
    }
    return result;
}

cell dp_2[MAXN][MAXN];
cell dp_5[MAXN][MAXN];

int main()
{

    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[j][i];


//	cerr << endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
        {
            point f = get_val(arr[j][i]);
//            cerr << f.X << " ";
            if (!i && !j)
            {
                dp_2[j][i].Y = '*';
                dp_2[j][i].X = f.X;
            }
            else if (!j)
            {
                dp_2[j][i].Y = 'R';
                dp_2[j][i].X = f.X + dp_2[j][i-1].X;
            }
            else if(!i)
            {
                dp_2[j][i].Y = 'D';
                dp_2[j][i].X = f.X + dp_2[j-1][i].X;
            }
            else
            {
                if (dp_2[j][i-1].X < dp_2[j-1][i].X)
                {
                    dp_2[j][i].Y = 'R';
                    dp_2[j][i].X = f.X + dp_2[j][i-1].X;
                }
                else
                {
                    dp_2[j][i].Y = 'D';
                    dp_2[j][i].X = f.X + dp_2[j-1][i].X;
                }
            }
//            cerr << dp_2[j][i].X << " ";
        }
//        cerr << endl;
    }

//	cerr << endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
        {
            point f = get_val(arr[j][i]);
//            cerr << f.Y << " ";
            if (!i && !j)
            {
                dp_5[j][i].Y = '*';
                dp_5[j][i].X = f.Y;
            }
            else if (!j)
            {
                dp_5[j][i].Y = 'R';
                dp_5[j][i].X = f.Y + dp_5[j][i-1].X;
            }
            else if(!i)
            {
                dp_5[j][i].Y = 'D';
                dp_5[j][i].X = f.Y + dp_5[j-1][i].X;
            }
            else
            {
                if (dp_5[j][i-1].X < dp_5[j-1][i].X)
                {
                    dp_5[j][i].Y = 'R';
                    dp_5[j][i].X = f.Y + dp_5[j][i-1].X;
                }
                else
                {
                    dp_5[j][i].Y = 'D';
                    dp_5[j][i].X = f.Y + dp_5[j-1][i].X;
                }
            }
//            cerr << dp_5[j][i].X << " ";
        }
//        cerr << endl;
    }

	point zero_pos = find_zero();
	if ((dp_2[n-1][n-1].X  && dp_5[n-1][n-1].X ) && zero_pos.X != -1)
	{
		cout << 1 << endl;
		for(int i=0; i<zero_pos.X; i++)
			cout << "R";
		for(int i=0; i<zero_pos.Y; i++)
			cout << "D";
		for(int i=zero_pos.X + 1; i<n; i++)
			cout << "R";
		for(int i=zero_pos.Y + 1; i<n; i++)
			cout << "D";
		cout << endl;
	}
    else if (dp_2[n-1][n-1].X < dp_5[n-1][n-1].X)
    {
        cout << dp_2[n-1][n-1].X << endl;
        string path;
        point pos = make_pair(n-1, n-1);
        while(dp_2[pos.Y][pos.X].Y != '*')
        {
            if (dp_2[pos.Y][pos.X].Y == 'D')
            {
                path += 'R';
                pos.Y--;
                continue;
            }
            path += 'D';
            pos.X --;
        }
        reverse(path.begin(), path.end());
        cout << path << endl;
    }
    else
    {
        cout << dp_5[n-1][n-1].X << endl;
        string path;
        point pos = make_pair(n-1, n-1);
        while(dp_5[pos.Y][pos.X].Y != '*')
        {
            if (dp_5[pos.Y][pos.X].Y == 'D')
            {
                path += 'R';
                pos.Y--;
                continue;
            }
            path += 'D';
            pos.X --;
        }
        reverse(path.begin(), path.end());
        cout << path << endl;
    }

    return 0;
}
