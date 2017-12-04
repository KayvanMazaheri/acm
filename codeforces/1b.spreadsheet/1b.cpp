#include <iostream>
#include <string>

using namespace std;

const int MAXN = 1e6 + 123;


int sys(string s);
int char_num (char c);
string reverse(string inp);
string convert(string s, int in);
string to10 (string s);
string to27 (string num);
string int2str(long long num);

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        string s;
        cin >> s;
        //cout << changeBase(s, 10, 26) << endl;
        cout << convert(s, sys(s)) << endl;
    }
    return 0;
}

string to10 (string s)
{
    long long result = 0 ;
    for(int i=0; i<s.size(); i++)
        (result *= 26) += ((s[i] - 'A') + 1);
    return int2str(result) ;
}


string int2str(long long num)
{
    string result;
    while(num)
    {
        result = char((num%10) + '0') + result;
        num /= 10;
    }
    return result;
}
long long str2int(string s)
{
    s = reverse(s);
    long long result = 0;
    for(int i=s.size()-1; i>=0; i--)
        (result *= 10) += s[i] - '0' ;
    return result;
}

string convert(string s, int in)
{
    if (in == 1)
    {
        string r, c;
        int i;
        for (i=1; s[i] != 'C'; i++);
        r = s.substr(1, i-1);
        for(i=0; i<s.size(); i++);
        c = s.substr(r.size()+2, i);
        string result ;
        result += to27(c);
        result += r;
        return result;
    }
    else if (in == 2)
    {
        string r, c;
        int i;
        for(i=0; char_num(s[i]) != 2; i++);
        r = s.substr(i, s.size()-1);
        c = s.substr(0, i);
        string result;
        result = 'R' + r +'C' + to10(c);
        return result;
    }
    else
        return "err";
}

string to27(string num)
{
    int to = 26;
    long long decimal = str2int (num);
    //cerr << decimal << endl;
    string result= "";
    char buff ;
    while (decimal)
    {
        int r = (decimal % to)  ;
        buff = char((r + 'A' )- 1);
        if (r == 0)
        {
            buff = 'Z';
            decimal -= to;
            if (decimal < 0)
                decimal += to;
        }
//		if (r < 10)
//			buff = char (r + '0') ;
//		else
//			buff = char(r + 'A' - 10) ;
        result += buff ;
        decimal /= to ;
    }
    //cerr << result << endl ;
    result = reverse(result) ;
//	for(int i=0; i<result.size(); i++)
//		result[i] += 'A' - '0';
    return result;
}

string reverse(string inp)
{
    for (int i=0; i<inp.size()/2; i++)
        swap (inp[i], inp[inp.size()-i-1]);
    return inp ;
}

int sys(string s)
{
    int changes = 1;
    int pre = char_num(s[0]);
    int cur;
    for(int i=1; i<s.size(); i++)
    {
        cur = char_num(s[i]);
        if (cur != pre)
            changes ++;
        pre = cur;
    }
    if (changes == 4 )
        return 1;
    if (changes == 2)
        return 2;
    return -1;
}

int char_num (char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= '0' && c <= '9')
        return 2;
    return -1;

}
