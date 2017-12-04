#include <iostream>
#include <string>
#include <map>
using namespace std;

map <string, bool> pos;
int score[2];

int main()
{
    pos["SP"] = true;
    pos["RS"] = true;
    pos["PR"] = true;
    int n;
    string a, b;
    cin >> n >> a >> b;
    int til = int(a.size() * b.size());
    for(int i=0; i<til; i++)
    {
        string p1, p2;
        p1 = a[i%a.size()];
        p2 = b[i%b.size()];
        score[0] += pos[p1+p2];
        score[1] += pos[p2+p1];
    }
    score[0] *= n / til;
    score[1] *= n / til;
	for(int i=n - n%til; i<n; i++)
    {
        string p1, p2;
        p1 = a[i%a.size()];
        p2 = b[i%b.size()];
        score[0] += pos[p1+p2];
        score[1] += pos[p2+p1];
    }
    cout << score[1] << " " << score[0] << endl;
    return 0;
}
