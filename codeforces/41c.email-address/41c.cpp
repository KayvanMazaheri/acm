#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    for(int i= str.find("dot"); i != string::npos; i=str.find("dot"))
        str = str.substr(0, i) + '.' + str.substr(i+3, str.size()-i-3);
    for(int i= str.find("at"); i != string::npos; i=string::npos)
        str = str.substr(0, i) + '@' + str.substr(i+2, str.size()-i-2);
    if (str[0] == '@')
    {
		for(int i= str.find("at"); i != string::npos; i=string::npos)
            str = str.substr(0, i) + '@' + str.substr(i+2, str.size()-i-2);
        str = "at" + str.substr(1, str.size()-1);
    }
    if (str[0] == '.')
        str = "dot" + str.substr(1, str.size()-1);
    if (str[str.size()-1] == '@')
        str = str.substr(0, str.size()-1) + "at";
    if (str[str.size()-1] == '.')
        str = str.substr(0, str.size()-1) + "dot";
    cout << str << endl;
    return 0;

}
