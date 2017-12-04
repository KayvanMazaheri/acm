#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <pair<int, int> > card;


int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int a, b;
		cin >> a >> b;
		card.push_back(make_pair(b, a));
	}
	sort(card.begin(), card.end());
	long long move = 1;
	long long point = 0;
	for(int i=n-1; move && i >= 0 ; i--)
	{
		move -- ;
		point += card[i].second ;
		move += card[i].first ;
	}

	cout << point << endl;
	return 0;
}
