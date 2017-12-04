#include <iostream>
#include <string>
#include <vector>

using namespace std;

string add (string a, string b);

int main()
{
	string a, b, r, a_0, b_0, r_0;
	cin >> a >> b;
	for(int i=0; i<a.size(); i++)
		if(a[i] != '0')
			a_0 += a[i];
	for(int i=0; i<b.size(); i++)
		if(b[i] != '0')
			b_0 += b[i];

	r = add(a, b);

	for(int i=0; i<r.size(); i++)
		if(r[i] != '0')
			r_0 += r[i];
	if (add(a_0, b_0) == r_0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}

string add (string a, string b)
{
    string result ;
    if (b.size() > a.size())
        swap (a, b);
    int extra = a.size() - b.size() ;
    string buffer;
    for (int i=0; i<extra; i++)
        buffer += "0" ;
    buffer += b;
    b = buffer ;
    int r = 0;
    //cerr << a << endl << b<< endl ;
    for (int i=a.size()-1; i>=0; i--)
    {
        int num = (int(a[i]-'0') + int(b[i]-'0')) ;
        result = char (( num + r ) %10 +'0') + result;
        r = (r+num)/ 10 ;
    }
    if (r)
        result = char(r + '0') + result ;
    return result;
}
