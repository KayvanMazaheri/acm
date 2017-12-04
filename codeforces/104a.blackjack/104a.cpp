#include <iostream>

using namespace std;

int arr[16] = {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 15, 4, 0, 0, 0, 0};

int main()
{
	int n;
	cin >> n;
	cout << arr[n-10] << endl;
	return 0;
}
