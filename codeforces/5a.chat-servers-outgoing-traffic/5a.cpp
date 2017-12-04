#include <iostream>
#include <set>
#include <string>

using namespace std;

set <string> db;

int main()
{
	string query;
	long long traffic = 0;
	while(getline(cin, query))
	{
		if (query[0] == '+')
			db.insert(query.substr(1));
		else if (query[0] == '-')
			db.erase(query.substr(1));
		else
		{
			string msg = query.substr(query.find(":")+1);
			traffic += msg.size() * db.size();
		}
	}
	cout << traffic << endl;
	return 0;
}
