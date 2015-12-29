#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n ;
	string word[10];
	int i = 0;
	for(; i < n; i ++)
	{
		cin >> word[i];
		int s = word[i].size() - 1 ;
		if ((word[i][s]=='o')||(word[i][s]=='s')||(word[i][s]=='x')||((word[i][s]=='h')&&(word[i][s-1]=='c')))
			word[i]+="es";
		else if (word[i][s]=='f')
			word[i] = word[i].substr(0,s) + "ves" ;
		else if ((word[i][s]=='e')&&(word[i][s-1]=='f'))
			word[i] = word[i].substr(0,s-1) + "ves" ;
		else if (word[i][s]=='y')
			word[i] = word[i].substr(0,s) + "ies" ;
		else
			word[i] += 's';
	}
	for (int c=0; c<i; c++)
		cout << word[c] << endl ;

	return 0;
}
