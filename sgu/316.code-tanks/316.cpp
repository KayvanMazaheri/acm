#include <iostream>
#include <vector>
using namespace std;

struct tank
{
	long long hitPoint;
	long long score ;
};
int main()
{
	int N, M;
	cin >> N >> M ;
	tank t[N];
	for (int i=0; i<N; i++)
	{
		t[i].hitPoint = 100;
		t[i].score = 0;
	}

	for (int i=0; i<M; i++)
	{
		int fired, hited;
		cin >> fired >> hited;
		fired -- ;
		hited -- ;
		if (t[fired].hitPoint > 0)
		{
			if (t[hited].hitPoint > 0)
			{
				t[hited].hitPoint -= 8;
				t[fired].score += 3;
			}
			else
			{
				t[hited].hitPoint -= 8;
			}
		}
	}
	for (int i=0; i<N; i++)
		if (t[i].hitPoint > 0)
			cout << t[i].hitPoint << " " << (t[i].score) + (t[i].hitPoint /2) << endl ;
		else
			cout << t[i].hitPoint << " " << (t[i].score) << endl;

	return 0;
}
