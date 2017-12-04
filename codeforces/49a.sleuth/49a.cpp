#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c)
{
	if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'y' || c == 'Y')
		return true;
	return false ;
}

int main()
{
	string question;
	getline(cin, question);
	int i;
	for(i = question.size()-1; i>=0; i--)
		if(question[i] != ' ' &&  question[i] != '?')
			break;
	if(isVowel(question[i]))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
