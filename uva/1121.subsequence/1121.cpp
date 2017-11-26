#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n, s;
	while(cin >> n >> s) {
		int start = 0;
		vector<int> seq;
		int res = 1e5 + 123;
		int total = 0;

		for (int i = 0; i < n; ++i)
		{
			int num;
			cin >> num;
			seq.push_back(num);
			total += num;
			while(total >= s) {
				if (total - seq[start] >= s)
					total -= seq[start++];
				else {
					res = min(res, i - start + 1);
					break;
				}
			}

		}

		cout << (res > 1e5 + 111 ? 0 : res) << endl;
	}

}