#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e4;

class Vertex
{
	public:
	vector <int> in;
	vector <int> out;

	int in_size()
	{
		return in.size();
	}
	int out_size()
	{
		return out.size();
	}
};

Vertex v[MAXN];
bool mark[MAXN];
vector <int> result;

int main()
{
	int n, m;
	cin >> n >> m;
	int remain = n;
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		v[a].out.push_back(b);
		v[b].in.push_back(a);
	}
	while(remain)
	{
		int object_vertex = -1;
		for(int i=0; i<n; i++)
			if (v[i].in_size() == 0 && !mark[i])
			{
				object_vertex = i;
				break;
			}
		if (object_vertex == -1)
		{
			cout << "No solution" << endl;
			return 0;
		}
		remain --;
		//cerr << object_vertex + 1<< endl;
		result.push_back(object_vertex);
		mark[object_vertex] = true;
		for(int i=0; i<v[object_vertex].out_size(); i++)
		{
			int nb = v[object_vertex].out[i];
			if (nb == -1)
				break;
			for(int j=0; j<v[nb].in_size(); j++)
				if (v[nb].in[j] == object_vertex)
					v[nb].in.erase(v[nb].in.begin()+j);
		}

	}
	for(int i=0; i<n; i++)
		for(int j=0; j<result.size(); j++)
			if (result[j] == i)
			{
				cout << j+1 << " ";
				break;
			}
		cout << endl;
	return 0;
}
