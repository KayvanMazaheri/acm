#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1e2 + 123;

vector <int> queue;
vector <int> sorted;
vector <int> result;
vector <int> buffer;
bool mark[MAXN];

int main()
{
	int n, f;
	cin >> n >> f;
	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		queue.push_back(inp);
		sorted.push_back(inp);
	}
	sort(sorted.begin(), sorted.end());
	mark[f] = true;
	for(int i=0; i<queue.size(); i++)
	{
		if (mark[queue[i]])
			continue;
		for(int j=0; j<n; j++)
			if (sorted[j] < max(queue[i], f) && sorted[j] > min(queue[i], f) && !mark[sorted[j]])
			{
				buffer.push_back(sorted[j]);
				mark[sorted[j]] = true;
			}
		if (f - queue[i] > 0)
			for(int j=buffer.size()-1; j>=0; j--)
				result.push_back(buffer[j]);
		else
			for(int j=0; j<buffer.size(); j++)
				result.push_back(buffer[j]);
		while(buffer.size())
			buffer.pop_back();
		f = queue[i];
		mark[f] = true;
		result.push_back(f);
	}
	for(int i=0; i<n; i++)
		cout << result[i] << " ";
	cout << endl;
	return 0;
}
