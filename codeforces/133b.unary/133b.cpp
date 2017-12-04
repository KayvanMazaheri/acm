#include <iostream>
#include <string>

using namespace std;

string changeBase(string num, int in, int to);
long long dec(string num, int in);
string brainFuck(char c);

int main()
{
	string inp, result;
	cin >> inp;
	for(int i=0; i<inp.size(); i++)
		result += brainFuck(inp[i]);
	cout << dec(result, 2) % (1000003) << endl;
	return 0;
}

string brainFuck(char c)
{
    switch (c)
    {
    case '>' :
        return "1000";
    case '<' :
        return "1001";
    case '+' :
        return "1010";
    case '-' :
        return "1011";
    case '.' :
        return "1100";
    case ',' :
        return "1101";
    case '[' :
        return "1110";
    case ']' :
        return "1111";
    default :
		return "-1";
    }

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
    	result %=  (1000003);
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

