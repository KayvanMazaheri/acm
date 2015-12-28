#include <iostream>
using namespace std;

string inp;

int c2i(char c)
{
    return int(c - '0' );
}

char i2c(int n)
{
    return char(n+'0');
}

void str_zero_del(string &s)
{
		// this function removes useless zeros from starting of string s
		int zero_num = 0;
		for(unsigned int i=0; i<s.size() && s[i] == '0'; i++)
			zero_num ++;
		s = s.substr(zero_num, s.size()-zero_num);
		if (s == "")
			s = "0";
		return ;
}

string d2(string s)
{
    string result = "";
    int buffer = 0;
    for(int i=0; i<s.size(); i++)
    {
        (buffer *= 10 ) += c2i(s[i]);
        result += i2c(buffer/2);
        buffer %= 2;
    }
    return result;
}

string m1(string buffer)
{
	int point = buffer.size()-1;
	while(buffer[point] == '0')
	{
		buffer[point] = '9';
		point --;
	}
	buffer[point] --;
	return buffer;
}

int main()
{
    cin >> inp;
    string result = d2(inp);
    str_zero_del(result);
    cerr << "n/2    =>    " << result << endl;
    if (inp.size() == 1 && c2i(inp[0]) < 7)
    {
        if (c2i(inp[0]) == 5)
            result = "2";
        else
            result = "1";
    }
    else
    {

        string buffer = result;
        if (c2i(inp[inp.size()-1])%2 == 0)
		{
			if (c2i(result[result.size()-1])%2 == 0)
			{
				result = m1(result);
			}
			else
			{
				result = m1(result);
				result = m1(result);
			}
		}
    }
    str_zero_del(result);
    cerr << "K      =>    " ;
    cout << result << endl;
    return 0;
}
