#include <iostream>
#include <string>
using namespace std;

bool isLetter (char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

string isValid(string s)
{
	string prefix, suffix;
	int at_pos = s.find('@');
	if (at_pos == string::npos)
		return "NO";
	prefix = s.substr(0, at_pos);
	suffix = s.substr(at_pos+1, s.size()-at_pos);
	for(int i=0; i<prefix.size(); i++)
		if (!(isLetter(prefix[i]) || (prefix[i] >= '0' && prefix[i] <= '9') || prefix[i] == '-' || prefix[i] == '_' || prefix[i] == '.'))
			return "NO";
	if (prefix.find("..") != string::npos || prefix[0] == '.' || prefix[prefix.size()-1] == '.')
		return "NO";
	int s_end = suffix.size()-1;
	if (suffix.size() < 4)
		return "NO";
	if (!((isLetter(suffix[s_end])) && (isLetter(suffix[s_end-1])) && (suffix[s_end -2] == '.' || ( suffix[s_end-3] == '.' && isLetter(suffix[s_end-2])))))
		return "NO";
	for(int i=0; i<suffix.size(); i++)
		if (!((suffix[i] >= 'a' && suffix[i] <= 'z') ||(suffix[i] >= 'A' && suffix[i] <= 'Z') || (suffix[i] >= '0' && suffix[i] <= '9') || suffix[i] == '-' || suffix[i] == '_' || suffix[i] == '.'))
			return "NO";
	if (suffix.find("..") != string::npos || suffix[0] == '.' || suffix[suffix.size()-1] == '.')
		return "NO";


	return "YES";
}

int main()
{
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	for(int i=0; i<n; i++)
	{
		string address ;
		getline(cin, address);
		cout << isValid(address) << endl;
	}
	return 0;
}
