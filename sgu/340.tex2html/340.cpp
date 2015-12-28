#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> vec;

bool isChar(char c)
{
	return  ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int main()
{
	int n;
	string inp;

	//cin >> n;
	//for(int i=0; i<n; i++)
	while(getline (cin, inp))
	{
		//getline (cin, inp);
		string result;
		for(int i=0; i<inp.size(); i++)
		{
			if (inp[i] == ' ' || inp[i] == '$')
				continue;
			if (inp[i] == '+' || inp[i] == '-' || inp[i] == '*' || inp[i] == '/')
			{
				if (isChar(result[result.size()-1]))
					result += "</i>";
				result += "&nbsp;";
				result += inp[i];
				result += "&nbsp;";
			}
			else if (inp[i] == '^' && inp[i+1] != '{')
			{
								if (isChar(result[result.size()-1]))
					result += "</i>";
				i++;
				result += "<sup>" ;
				if (isChar(inp[i]) && !(isChar(result[result.size()-1])))
					result += "<i>";
				result += inp[i] ;
				if (isChar(inp[i]))
					result += "</i>";
				result += "</sup>";
			}
			else if (inp[i] == '^' && inp[i+1] == '{')
			{
				if (isChar(result[result.size()-1]))
					result += "</i>";
				i++;
				result += "<sup>";
				vec.push_back("</sup>");
			}
			else if (inp[i] == '_' && inp[i+1] != '{')
			{
				if (isChar(result[result.size()-1]))
					result += "</i>";
				i++;
				result += "<sub>" ;
				if (isChar(inp[i]) && !(isChar(result[result.size()-1])))
					result += "<i>";
				result += inp[i] ;
				if(isChar(inp[i]))
					result += "</i>";
				result += "</sub>";
			}
			else if (inp[i] == '_' && inp[i+1] == '{')
			{

				if (isChar(result[result.size()-1]))
					result += "</i>";
				i++;
				result += "<sub>";
				vec.push_back("</sub>");
			}
			else if (inp[i] == '}')
			{
				if (isChar(result[result.size()-1]))
					result += "</i>";
				result += vec[vec.size()-1];
				vec.pop_back();
			}
			else if (isChar(inp[i]))
			{
				if (!isChar(result[result.size()-1]))
					result += "<i>";
				result += inp[i];

			}
			else
			{
				if (isChar(result[result.size()-1]))
					result += "</i>";
				result += inp[i];
			}
		}
		if (isChar(result[result.size()-1]))
					result += "</i>";
		cout << result << endl;
	}
}
