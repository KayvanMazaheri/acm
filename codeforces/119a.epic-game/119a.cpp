#include <iostream>
using namespace std;

int GCD(int x,int y)
{
   if ( y>x )
      swap(x,y);
   while ( y!=0 )
   {
      int temp=y;
      y=x-y;
      x=temp;
      if ( y>x )
         swap(x,y);
   }
   return x;
}

int main()
{
	int a, b, n, i;
	cin >> a >> b >> n;
	for (i=0; n>=0; i++)
	{
		if (i%2 == 0)
			n-= GCD(a, n);
		else
			n-= GCD(b, n);
	}
	cout << i%2 << endl ;
	return 0;
}
