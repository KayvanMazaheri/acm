#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> cnt;

int main () {
	int t;
	cin >> t;
	for (int test = 0; test < t; ++test)
	{
		int n, m, k;
		cin >> n >> m >> k;
		cout << "Case " << test+1 << ": ";


		vector<int> seq;
		seq.push_back(1);
		seq.push_back(2);
		seq.push_back(3);
		int sum3 = 6;

		for (int i = 3; i < n; ++i)
		{
			seq.push_back(sum3 % m + 1);
			// cerr << " " << sum3 % m +1 ;
			sum3 += *seq.rbegin();
			sum3 -= seq[i-3];
		}
		// cerr << endl;

		int res = n * 2;

		cnt.clear();	
		int free = k;

		int start = 0;
		for (int i = 0; i < n; ++i)
		{
			int cur = seq[i];
			if (cur <= k && cnt[cur] == 0)
				free--;
			cnt[cur]++;

			while(free == 0) {
				int back = seq[start];
				if (back > k || cnt[back] > 1) {
					// cerr << "back is " << back << " at " << start << "  | current " << cur << " at " << i<< endl;
					start++;
					cnt[back]--;
				} else {
					res = min(res, i - start + 1);
					// cerr << "res in " << start << " " << i << endl;
					break;
				}
			}
			
		}

		if (res > n) {
			cout << "sequence nai" << endl;
		} else {
			cout << res << endl;
		}

	}
}