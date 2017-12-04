#include <iostream>
#include <set>
using namespace std;

set <int> result;

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int inp;
        cin >> inp;
        result.insert(inp);
    }
    result.erase (result.begin());
    if (result.empty())
		cout << "NO" << endl;
	else
		cout << *(result.begin()) << endl;
    return 0;
}
