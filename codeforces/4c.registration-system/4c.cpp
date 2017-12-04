#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map <string, int> db;

string int2str(int n)
{
	string s;
	while(n)
	{
		s += n % 10 + '0';
		n /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

string add(string name)
{
	db[name]++;
	if (db[name] == 1)
		return "OK";
	int num = db[name] - 1;
	string new_name = name + int2str(num);
	db[new_name] ++;
	return new_name;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		string query;
		cin >> query;
		cout << add(query) << endl;
	}
	return 0;
}
