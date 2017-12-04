#include <iostream>
#include <string>
using namespace std;

string remove_wub(string s)
{
	string result;
	int a = s.find("WUB");
	if (a == string::npos)
		return "#-1#";
	else
	result = s.substr(0, a);
	result += " ";
	result += s.substr(a+3, s.size());
	return result;
}

string space_remove(string s)
{
	string result;
	int i=0;
	while(s[i] == ' ')
		i++;
	int j = s.size() -1;
	while(s[j] == ' ')
		j --;
	return s.substr(i, s.size()- (i + (s.size()-j)) + 1);
}

int main()
{
	string inp;
	cin >> inp;
	string buff = remove_wub(inp);
	while(buff != "#-1#")
	{
			inp = buff;
			buff = remove_wub(inp);
	}
	inp = space_remove(inp);
	cout << inp << endl;
	return 0;

}
