#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
	int a, b;
	while(true){
		cin >> a >> b;
		if(a == -1 && b == -1)
			break;

		map<int, int> counta, countb;
		vector<int> veca, vecb;
		for (int i = 0; i < a; ++i)
		{
			int inp;
			cin >> inp;
			counta[inp]++;
			veca.push_back(inp);
		}
		
		for (int i = 0; i < b; ++i)
		{
			int inp;
			cin >> inp;
			countb[inp]++;
			vecb.push_back(inp);
		}

		bool problem = false;
		for (int i = 0; i < a; ++i)
		{
			if(veca[i] % 2 && counta[veca[i]] != countb[veca[i]])
				problem = true;
			else if(veca[i] % 2 == 0 && countb[veca[i]] <= 0 && countb[veca[i] / 2 - 1] <=0)
				problem = true;
		}
		for (int i = 0; i < b; ++i)
		{
			if(vecb[i] % 2 && countb[vecb[i]] != counta[vecb[i]])
				problem = true;
			else if(vecb[i] % 2 == 0 && counta[vecb[i]] <= 0 && counta[vecb[i] / 2 - 1] <=0)
				problem = true;
		}

		cout << (problem ? "N" : "Y") << endl;
	}
	return 0;
}