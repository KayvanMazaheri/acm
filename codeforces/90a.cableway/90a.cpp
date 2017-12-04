#include <iostream>

using namespace std;

int main()
{
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	int notArrived = arr[0] + arr[1] + arr[2];
	int time = 29;
	for(int i=0; notArrived; i++)
	{
		time ++;
		if(arr[i%3] > 0)
		{
			arr[i%3] -=2;
			if (arr[i%3] > -1)
				notArrived -=2;
			else
				notArrived -=1;
		}
	}

	cout << time << endl;
	return 0;
}
