#include <iostream>
#include <vector>
using namespace std;


int mark[1000+123];
long long M, alpha, beta, gamma, A, k;
int arr[2];
vector <long long> vec;


long long f(int n)
{
    if (n == 0)
		return A;
	long long f_1 = f(n-1);
	return ((alpha * f_1 * f_1)%M + (beta * f_1)%M + gamma)%M ;
}

int main()
{
	fill(mark, mark+1000 + 123, -1);
    cin >> A >> alpha >> beta >> gamma >> M >> k;
    alpha %= M;
    beta %= M;
    gamma %= M;
    if (!k)
    {
    	cout << A << endl;
    	return 0;
    }
    A %= M ;
    vec.push_back(A);

    long long result, x_1, t_1 = -1 , t_2 = -1;
    for(int i=0; i<k; i++)
    {

        result = 0;
        //cerr << vec[i] << endl;
        x_1 = vec[i];
        x_1 *= x_1;
        x_1 %= M;
        x_1 *= alpha;
        x_1 %= M;
        result += x_1;
        x_1 = vec[i];
        x_1 *= beta;
        x_1 %= M;
        result += x_1 + gamma;
        result %= M;
        vec.push_back(result);
       if (mark[result] != -1)
       {
       	 t_1 = mark[result];
       	 t_2 = i;
       	 break;
       }
		mark[result] = i;
    }
    if (t_1 == t_2 || vec.size() == k+1)
    {
    	cout << vec[vec.size()-1] << endl;
    }
    else
    {
    	cout << vec[1+ ((k-t_1-1)%(t_2 - t_1) + t_1)] << endl;
    }
    //cerr << vec[vec.size()-1] << endl;
	//cerr << f(k) << endl;
    //cout << arr[0] << endl;
    return 0;
}
