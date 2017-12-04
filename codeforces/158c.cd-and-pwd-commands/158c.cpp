#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector <string> dir;

int main()
{
    int n;
    cin >> n;
	//dir.push_back("/");
    for(int t=0; t<n; t++)
    {
        string inp, path;
        cin >> inp ;
        if (inp == "pwd")
        {
        	cout << "/";
			for(int i=0; i<dir.size(); i++)
				cout << dir[i] << "/";
			cout << endl;
			continue;
        }
        cin >> path;
        if (path[0] == '/')
			while(dir.size())
				dir.pop_back();
        if (path[path.size()-1] == '/')
			path = path.substr(0, path.size()-1);
		string buffer = path;
		while (buffer.size())
		{
			int address = buffer.find("/");
			if (address == string::npos)
			{
				if (buffer == ".." && dir.size())
					dir.pop_back();
				else if (buffer.size() && buffer != "..")
					dir.push_back(buffer);
				break;
			}

			string one = buffer.substr(0, address);
			if (one == ".." && dir.size())
				dir.pop_back();
			else if (one.size() && one != "..")
				dir.push_back(one);

			if (address < buffer.size() - 1)
				buffer = buffer.substr(address +1 , buffer.size() - address);
		}

    }
//	cout<< (double)clock() / CLOCKS_PER_SEC << endl;
	return 0;

}
