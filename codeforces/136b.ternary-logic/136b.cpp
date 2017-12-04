// In the name of God
// :)

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string changeBase(string num, int in, int to);
long long dec(string num, int in);

int main()
{
	string a, c, ta, tc;
	cin >> a >> c;
	ta = changeBase(a, 10, 3);
	tc = changeBase(c, 10, 3);
	int diff = ta.size() - tc.size();
	if (diff < 0)
		for(int i=0; i<abs(diff); i++)
			ta = "0"  + ta;
	if (diff > 0)
		for(int i=0; i<diff; i++)
			tc = "0" + tc ;
	string result;
	result.resize(ta.size());
	for(int i=0; i<ta.size(); i++)
		result[i] =  ((((tc[i] - '0') - (ta[i] - '0')) + 3 ) % 3 ) + '0';
	cout <<dec(result, 3) << endl;

	return 0;
}

string reverse(string inp)
{
	for (int i=0; i<inp.size()/2; i++)
		swap (inp[i], inp[inp.size()-i-1]);
	return inp ;
}

long long dec(string num, int in)
{
	long long result = 0;
	for (int i=0; i<num.size(); i++)
	{
		result *= in ;
		if (num[i] >= 'A' && num[i] <= 'Z')
			result += int (num[i] - 'A' + 10);
		else
			result += int (num[i] - '0') ;
	}
	return result ;
}

string changeBase(string num, int in, int to)
{
	long long decimal = dec (num, in) ;
	//cerr << "dec: " << decimal << endl ;
	string result="";
	char buff ;
	while (decimal > 0)
	{
		int r = decimal % to ;
		if (r < 10)
			buff = char (r + '0') ;
		else
			buff = char(r + 'A' - 10) ;
		result += buff ;
		decimal /= to ;
	}
	//cerr << result << endl ;
	return reverse(result) ;
}
