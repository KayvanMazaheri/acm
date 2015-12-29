#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int seq1[3];
	int seq2[3];
	int seq3[3];
	int mseq[3];
	cin >> seq1[0] >> seq1[1] >> seq1[2] ;
	cin >> seq2[0] >> seq2[1] >> seq2[2] ;
	cin >> seq3[0] >> seq3[1] >> seq3[2] ;
	sort(seq1,seq1+3);
	sort(seq2,seq2+3);
	sort(seq3,seq3+3);
	mseq[0] = seq1[1] ;
	mseq[1] = seq2[1] ;
	mseq[2] = seq3[1] ;
	sort(mseq,mseq+3);
	cout << mseq[1] ;
	return 0;
}
