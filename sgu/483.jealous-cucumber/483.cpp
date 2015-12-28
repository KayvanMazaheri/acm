#include <iostream>
#include <vector>
using namespace std;

vector <int> right_vec;
vector <int> left_vec;

int main()
{
	int n, h;
	cin >> n >> h;
	h++;
	int center = h * h;
	int now = center;
	for(int i=h; now <= n; i++)
	{
		left_vec.push_back(now + i);
		right_vec.push_back(now + 2*i);
		now = now + 2* i;
	}
	for(int i=left_vec.size()-1; i>=0; i--)
		if (left_vec[i] <= n)
			cout << left_vec[i] << " ";
	cout << center << " ";
	for(int i=0; i<right_vec.size(); i++)
		if (right_vec[i] <= n )
			cout << right_vec[i] << " ";
	cout << endl;

	return 0;
}
