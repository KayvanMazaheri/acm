#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

class Bignum				// Fuck This Class !
{
public:					// just for test and debug
	string reverse(const string s)
	{
		string result = "";
		for(unsigned int i=0; i<s.size(); i++)
			result += s[s.size()-1-i];
		return result;
	}
	string int2str (long long n)
	{
		string result = "";
		do
		{
			result += (n%10 + '0');
		}while(n/=10);

		return reverse(result);
	}
	inline int char2int (char c)
	{
		return int(c-'0');
	}
	inline char int2char (int n)
	{
		return char(n+'0');
	}

	inline bool min_sign (string a, string b)
	{
		// returns the sign of result of a-b
		// true for + and false for -
		if (a == b)
			return true;
		return (a.size()==b.size())?(b<a):((a.size()<b.size())?false:true);
	}

	inline void str_sz_eq(string &a, string &b)
	{
		// this function changes strings to make their size equal
		// and may swap them to make a > b

		if (b.size() < a.size())
			swap(a, b);
		while(b.size()-a.size())
			a = "0" + a;
		if (a < b)
			swap(a, b);
		return ;
	}

	inline void str_zero_del(string &s)
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

	// operator functions here :
	inline string str_sum(string a, string b)
	{
		string result = "";
		str_sz_eq(a, b);
		//cerr << "a = " << a << endl << "b = " << b << endl ;
		int buffer = 0;
		for(int i=a.size()-1; i>=0; i--)
		{
			int plus = buffer/10;
			buffer = char2int(a[i]) + char2int(b[i]) + plus ;
			result += int2char(buffer%10);

		}
		int plus = buffer/10;
		if (plus != 0)
			result += int2char(plus);
		result = reverse(result);
		str_zero_del(result);

		return result;
	}

	inline string str_mines(string a, string b)
	{
		string result = "";
		str_sz_eq(a, b);
		int buffer = 0;
		for(int i=a.size()-1; i>=0; i--)
		{
			int mines = (buffer < 0)?-1:0;
			buffer = (char2int(a[i]) - char2int(b[i])) + mines ;
			result += int2char((buffer+10)%10);
		}
		result = reverse(result);
		str_zero_del(result);
		return result;
	}
	inline string str_mult(string a, string b)
	{
		string result = "0";
		//str_sz_eq(a, b);
		str_zero_del(a);
		str_zero_del(b);
		//cerr << "a = " << a << endl << "b = " << b << endl ;

		for(int i=b.size()-1; i>=0; i--)
		{
			int buffer = 0;
			string str_buffer = "";
			for(int j=a.size()-1; j>=0; j--)
			{
				int plus = buffer/10;
				buffer = char2int(a[j]) * char2int(b[i]) + plus ;
				str_buffer += int2char(buffer%10);
			}

			int plus = buffer/10;
			if (plus != 0)
				str_buffer += int2char(plus) ;
			reverse(str_buffer);
			result = str_sum(result, str_buffer);
			a += '0';
		}
		str_zero_del(result);
		return result;
	}

	inline string str_mult_int (string a, int b)
	{
		string result = a;
		for(int i=1; i<b; i++)
			result = str_sum(result, a);
		return result;
	}
	inline string str_pow(string a, string b)
	{
		str_zero_del(a);
		str_zero_del(b);
		if (b == "0")
			return "1";
		string result = a;
		while(b != "1")
		{
			result = str_mult(a, result);
			b = str_mines(b, "1");
		}
		str_zero_del(result);
		return result;

	}
	string str_pow_int(int a, int b)
	{
		string a_str = int2str(a);
		string result = "1";
		for(int i=0; i<b; i++)
			result = str_mult(a_str, result);
		return result;
	}
	string str_pow_int_2(int a, int b)
	{
		string a_str = int2str(a);
		string result = "1";
		for(int i=0; i<b; i++)
			result = str_mult_int(result, a);
		return result;
	}

	string value;
	bool sign;
	Bignum ()
	{
		value = "0";
		sign = true;
	}
	/**/
	Bignum (long long _value = 0)
	{
		value = int2str(int((_value)));
		sign = (_value < 0)?false:true;
	}
	/**/


};

int main()
{
	Bignum bn = 0;
	int a, b, k;
	//cerr << s3 << endl;
	cin >> a >> b >> k;
	int sum = a + b;
	string result =  bn.str_pow_int_2(sum, k);
	cout << result << endl;
	//cerr << (double)clock() / CLOCKS_PER_SEC << endl;
	return 0;
}
