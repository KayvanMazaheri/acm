#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string> lexemes;

int main()
{
	string inp;
	getline(cin, inp);
	bool in_qut = false;
	string buffer = "";
	for(int i=0; i<inp.size(); i++)
	{
		if (inp[i] == '"')
		{
			in_qut = !in_qut;
			if (in_qut == false || buffer.size() )
			{
				lexemes.push_back(buffer);
				buffer = "";
				continue;
			}
		}
		else if (inp[i] == ' ')
		{
			if (buffer.size() == 0 && !in_qut) continue;
			if (in_qut == false)
			{
				if (i && inp[i-1] != ' ')
				{
					lexemes.push_back(buffer);
					buffer = "";
					continue;
				}
			}
			buffer += " ";
		}
		else
			buffer += inp[i];
	}
	if (buffer.size()) lexemes.push_back(buffer);
	for(int i=0; i<lexemes.size(); i++)
		cout << "<" << lexemes[i] << ">" << endl;
	return 0;

}
