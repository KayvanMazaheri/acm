#include <iostream>
using namespace std;

const int MAXN = 20;

int key[MAXN];

int main()
{
	int m, n;
	while(true)
	{
		cin >> m >> n;
		if(!m && !n)
			break;
		for (int i = 0; i < m; ++i)
			cin >> key[i];

		int result = 0;

		for (int i = 0; i < n; ++i)
		{
			bool ok = true;
			for (int j = 0; j < m; ++j)
			{
				int inp;
				cin >> inp;
				if(inp > key[j])
					ok = false;
			}
			if(ok)
				result ++;
		}

		cout << result << endl;

	}
	return 0;
}