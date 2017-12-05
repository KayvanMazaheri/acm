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
const int MAXN = 40;
const int CONST_Val = 3 * 5 * 8;

double matrix[MAXN][MAXN];

void check_matrix(int m)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
            cerr << matrix[i][j] << " ";
        cerr << endl;
    }
    return;
}

void clear()
{
    for(int i = 0; i<MAXN; i++)
    {
        for(int j=0; j<MAXN; j++)
            matrix[i][j] = 0;
    }
    return;
}

long long solve_det(int n)
{
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //     {
    //         matrix[i][j] *= CONST_VAL ;
    //     }
    // }
    double result = 1;
	// check_matrix(n);
	// cerr << "-----------------------" << endl;
    for(int j=n-1; j>0; j--)
    {
        for(int i=j-1; i>=0; i--)
        {
             // int buff_u[MAXN];
             // int buff_l[MAXN];
             // for(int l=0; l<MAXN; l++)
             // {
             //    buff_u[l] = matrix[i][l] * matrix[j][j];
             //    buff_l[l] = matrix[j][l] * matrix[i][j];
             // }
             for(int l=0; l<MAXN; l++)
                matrix[i][l] -= matrix[j][l] * (matrix[i][j] / matrix[j][j]);
        }
        // check_matrix(n);
        // cerr << "////////////////" << endl;
    }
    for(int i=1; i<n; i++)
        result *= (double) matrix[i][i];


	// check_matrix(n);

    return (long long) (result + 0.95);
}

int main()
{

    int T;
    cin >> T;
    for(int test = 0; test < T; test ++)
    {
        clear();
        int m;
        cin >> m;

        for(int i=0; i<m*m; i++)
            for(int j=0; j<m*m; j++)
            {
              point vi = make_pair(i/m,i%m);
              point vj = make_pair(j/m,j%m);
              if(i == j)
              {

                if(vi.X == 0 && vi.Y == 0) matrix[i][j] = 3;
                else if(vi.X == m-1 && vi.Y == 0) matrix[i][j] = 3;
                else if(vi.X == m-1 && vi.Y == m-1) matrix[i][j] = 3;
                else if(vi.X == 0 && vi.Y == m-1) matrix[i][j] = 3;
                else if(vi.X == 0 || vi.X == m-1) matrix[i][j] = 5;
                else if(vi.Y == 0 || vi.Y == m-1) matrix[i][j] = 5;
                else matrix[i][j] = 8;

            }
            else
            {

                int dis = ((vi.X-vj.X) * (vi.X-vj.X)) + ((vi.Y-vj.Y) * (vi.Y-vj.Y));
                if(dis > 2) matrix[i][j] = 0;
                else matrix[i][j] = -1;
            }
        }
        //check_matrix(m);
        long long det = solve_det(m*m);
        cout << det << endl;

    }

    return 0;
}
