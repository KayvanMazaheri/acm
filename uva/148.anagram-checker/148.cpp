#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map <string, vector <int> > wc;
map <string, vector <int> > phrase_wc;
vector <string> dictionary;
map <string, bool> usedBefore;

void word_count(const string &str, map <string, vector <int> > &my_wc)
{
	my_wc[str] = vector <int> (26, 0);
	for (int i = 0; i < str.size(); ++i)
		if(str[i] != ' ')
			my_wc[str][str[i] - 'A']++;
	return;
}

vector <string> breakPhrase(string phrase)
{
	std::vector<string> res;
	string buff;
	for (int i = 0; i < phrase.size(); ++i)
	{
		if(phrase[i] == ' ')
		{
			res.push_back(buff);
			buff = "";
		}
		else
			buff += phrase[i];
	}
	if(buff.size())
		res.push_back(buff);
	return res;
}

void calcAnagram(const string&, const string&, vector <int>, vector<string>, int);

int main()
{
	string word;
	while(cin >> word && word != "#")
	{
		if(usedBefore[word]) continue;
		usedBefore[word] = true;
		dictionary.push_back(word);
		// word_count(word, wc);
	}
	sort(dictionary.begin(), dictionary.end());

	// cerr << "HI" << endl;
	string phrase;
	getline(cin, phrase);
	while(getline(cin, phrase) && phrase != "#")
	{
		// cerr << "new" << endl;
		word_count(phrase, phrase_wc);
		// map <string, bool> isUsed;

		for (int i = 0; i < dictionary.size(); ++i)
			calcAnagram(phrase, dictionary[i], phrase_wc[phrase], vector <string> (), i);
	}
}

void printAnagram(const string& target, vector<string> usedWords)
{
	vector <string> old = breakPhrase(target);
	sort(old.begin(), old.end());
	if(old == usedWords) return;
	cout << target << " =" ;
	string anagram;
	for (int i = 0; i < usedWords.size(); ++i)
		anagram += " " + usedWords[i];
	cout << anagram << endl;
	return;
}

void calcAnagram(const string& target, const string& usingWord, vector <int> left_wc, vector<string> usedWords, int st)
{
	usedWords.push_back(usingWord);

	// if(isUsed[usingWord]) return;
		// isUsed[usingWord] = true;

	for (int i = 0; i < usingWord.size(); ++i)
		if((--left_wc[usingWord[i] - 'A']) < 0) return;

	bool finished = true;
	// cerr << "NEW RULE" << endl;
	for (char i = 0; i < 26; ++i)
		if(left_wc[i])
		{
			finished = false;
			break;
		}

	if(finished)
	{
		sort(usedWords.begin(), usedWords.end());
		// if(mark[usedWords]) return;
		// mark[usedWords] = true;
		printAnagram(target, usedWords);
		return;
	}

	for (int i = st; i < dictionary.size(); ++i)
			calcAnagram(target, dictionary[i], left_wc, usedWords, i+1);
	return;
}
