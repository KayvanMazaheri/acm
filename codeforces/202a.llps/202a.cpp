#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector <string> all_subseq;
vector <string> result;

void mk_subseq(string pre, string &org, int end)
{
	if (end > org.size())
		return;
	all_subseq.push_back(pre);
	mk_subseq(pre+org[end], org, end+1);
	mk_subseq(pre, org, end+1);
	return;
}

bool is_pal(string s)
{
	for(int i=0; i<s.size(); i++)
		if (s[i] != s[s.size()-1-i])
			return false;
	return true;
}

int main()
{
	string s;
	cin >> s;
	mk_subseq("", s, 0);
	for(int i=0; i<all_subseq.size(); i++)
		if (is_pal(all_subseq[i]))
			result.push_back(all_subseq[i]);
	sort(result.begin(), result.end());
	cout << *(result.rbegin()) << endl;
	return 0;
}
