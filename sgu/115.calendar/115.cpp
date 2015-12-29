#include <iostream>
using namespace std;

int main()
{
	int N,M,days=0;
	cin >> N >> M;

	if ((M==2)&&(N>28))
		{
			cout << "Impossible" ;
			return 0;
		}
		else if (((M== 1)||(M== 3)||(M== 5)||(M== 7)||(M== 8)||(M== 10)||(M== 12))&&(N>31))
		{
			cout << "Impossible" ;
			return 0;
		}
		else if (((M==4)||(M==6)||(M==9)||(M==11))&&(N>30))
		{
			cout << "Impossible" ;
			return 0;
		}


	if ((M > 12)||(N < 1))
	{
		cout << "Impossible";
		return 0;
	}
	for(int i=1; i<M; i++)
	{
		if (i==2)
		{
			days +=28 ;
		}
		else if ((i== 1)||(i== 3)||(i== 5)||(i== 7)||(i== 8)||(i== 10)||(i== 12))
		{
			days+=31;
		}
		else
		{
			days+=30;
		}
	}
	days+= N;
	if (days%7 ==0)
	{
		cout << 7;
		return 0;
	}
	else
	{
		cout << days%7 ;
		return 0;
	}

}
