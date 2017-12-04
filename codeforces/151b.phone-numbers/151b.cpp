#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector <string> names;
vector <pair<int, int> > girls ;
vector <pair<int, int> > pizza ;
vector <pair<int, int> > taxi ;

bool isTaxi(string s)
{
	for(int i=1; i<s.size(); i++)
		if(i != 2 && i!=5 && s[i] != s[0])
			return false;
	return true ;
}

bool isPizza(string s)
{
	bool mark[10+2] ;
	fill (mark, mark+10, false);

	mark[s[0]-'0']=true;
	int lastDigit = int(s[0]-'0');

	for(int i=1; i<s.size(); i++)
	{
		//cerr << lastDigit << endl ;
		if((i != 2 && i!=5) && (mark[s[i]-'0']))
			return false ;
		if((i != 2 && i!=5) && (int(s[i]-'0') >= lastDigit))
			return false ;
		mark[s[i]-'0'] = true ;
		if(i != 2 && i!=5)
			lastDigit = int(s[i]-'0');

	}
	//cerr << endl << endl ;
	return true ;
}


int main()
{

	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int t;
		string name ;
		cin >> t >> name ;
		names.push_back(name);

		int pTaxi = 0, pPizza = 0, pGirl = 0;
		for (int j=0; j<t; j++)
		{
			string num ;
			cin >> num ;
			if (isTaxi(num))
				pTaxi++;
			else if (isPizza(num))
				pPizza++;
			else
				pGirl++;
		}
		girls.push_back(make_pair(pGirl, i));
		taxi.push_back(make_pair(pTaxi, i));
		pizza.push_back(make_pair(pPizza, i));
		//cerr << endl << names[i] << " :  " << taxi[i].first << " " << pizza[i].first << " " << girls[i].first << endl;
	}

	sort(pizza.begin(), pizza.end());
	sort(girls.begin(), girls.end());
	sort(taxi.begin(), taxi.end());


	vector <pair<int, int> > taxiResult ;
	vector <pair<int, int> > pizzaResult ;
	vector <pair<int, int> > girlsResult ;

	for (int i=0; i<n && taxi[taxi.size()-1].first == taxi[(taxi.size()-1)-i].first; i++)
		taxiResult.push_back(make_pair(taxi[taxi.size()-1-i].second, taxi[taxi.size()-1-i].first)) ;

	for (int i=0; i<n && pizza[pizza.size()-1].first == pizza[pizza.size()-1-i].first; i++)
		pizzaResult.push_back(make_pair(pizza[pizza.size()-1-i].second, pizza[pizza.size()-1-i].first)) ;

	for (int i=0; i<n && girls[girls.size()-1].first == girls[(girls.size()-1)-i].first; i++)
		girlsResult.push_back(make_pair(girls[girls.size()-1-i].second, girls[girls.size()-1-i].first)) ;

	sort(taxiResult.begin(), taxiResult.end());
	sort(pizzaResult.begin(), pizzaResult.end());
	sort(girlsResult.begin(), girlsResult.end());

	cout << "If you want to call a taxi, you should call:";
	for (int i=0; i<taxiResult.size(); i++)
	{
		if (i != 0)
			cout << ',';
		cout << " " << names[taxiResult[i].first] ;
	}
	cout << '.' << endl;


	cout << "If you want to order a pizza, you should call:";
	for (int i=0; i<pizzaResult.size(); i++)
	{
		if (i != 0)
			cout << ',';
		cout << " " << names[pizzaResult[i].first] ;
	}
	cout << '.' << endl;



	cout << "If you want to go to a cafe with a wonderful girl, you should call:";
	for (int i=0; i<girlsResult.size(); i++)
	{
		if (i != 0)
			cout << ',';
		cout << " " << names[girlsResult[i].first] ;
	}
	cout << '.' << endl;

	return 0;
}
