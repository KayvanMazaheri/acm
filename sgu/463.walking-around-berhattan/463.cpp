#include <iostream>
#include <string>
using namespace std;

#define X first
#define Y second

const int MAXN = 100 + 125;

bool mark[MAXN][MAXN];
int map[MAXN][MAXN];
pair <int, int> cd =  make_pair(0, 0);
short pleasure = 0;
char face = 'R';
int m, n;
string moves;

void p(int x, int y)
{
    if (mark[x][y])
        pleasure += map[x][y] / 2;
    else
        pleasure += map[x][y];
    mark[x][y] = true;
    return;
}

int main()
{
    for (int i=0; i<MAXN; i++)
        for(int j=0; j<MAXN; j++)
            mark[i][j] = 0;

    cin >> m >> n;
    for(int j=0; j<m; j++)
        for (int i=0; i<n; i++)
        {
            char inp;
            cin >> inp;
            map[i][j] =  inp-'0';
        }

    cin >> moves;
    for(int i=0; i<moves.size(); i++)
    {
        //cerr << 1 << endl;
        if (moves[i] == 'M')
        {
            if (face == 'R')
            {
                p(cd.X, cd.Y);
                if (cd.Y)
                    p(cd.X, cd.Y - 1);
                cd.X ++;
            }
            else if (face == 'L')
            {
                cd.X --;
                p(cd.X, cd.Y);
                if (cd.Y)
                    p(cd.X, cd.Y -1);
            }
            else if (face == 'U')
            {

                cd.Y --;
                p(cd.X, cd.Y);
                if (cd.X)
                    p(cd.X -1, cd.Y);

            }
            else if (face == 'D')
            {
                p(cd.X, cd.Y);
                if (cd.X)
                    p(cd.X - 1, cd.Y);
                cd.Y ++;
            }
            else
                cerr << "Err #4" << endl;
        }
        else if (moves[i] == 'R')
        {
            if(face == 'R')
                face = 'D';
            else if (face == 'D')
                face = 'L';
            else if (face == 'L')
                face = 'U';
            else if(face == 'U')
                face = 'R';
            else
                cerr << "Err #1" << endl;
        }
        else if (moves[i] == 'L')
        {
            if(face == 'R')
                face = 'U';
            else if (face == 'D')
                face = 'R';
            else if (face == 'L')
                face = 'D';
            else if(face == 'U')
                face = 'L';
            else
                cerr << "Err #2" << endl;
        }
        else
            cerr << "Err #3" << endl;
        //cerr << i << " : " << pleasure  << endl;
    }
//    for (int j=0; j<m; j++)
//    {
//		for (int i=0; i<n; i++)
//			cerr << mark[i][j] << " ";
//	cerr <<  endl;
//	}
    cout << pleasure << endl;
    return 0;
}
