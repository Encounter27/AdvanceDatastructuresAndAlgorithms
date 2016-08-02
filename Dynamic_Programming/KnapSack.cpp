/*********************************************************************************
 * Given a set of items, each with a weight and a value, determine the number
 * of each item to include in a collection so that the total weight is less than 
 * or equal to a given limit and the total value is as large as possible.
 *
 * Recursive Formula:-
 * 
 * given weight w1, w2, w3, ......, wi
 * given value  v1, v2, v3,......., vi
 *
 * RES(i,j) = Max( RES(i-1, j) , vi + RES(i-1, j - wi) ; if( wi <= j) // we can include wi weight.
 *          = RES(i-1, j)                              ; if( wi > j ) // we can not include wi.
 *
 ********************************************************************************/
#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

#define DEBUG

#define FOR(i, a, b) for( int i = (a); i <= (b); ++i)
#define DFOR(i, a, b) for( int i = (a); i >= (b); --i)
#define MAX(a, b )   (a) > (b) ? (a):(b)

typedef vector< int > Vec;
typedef vector< Vec > Mat;

int getMaxValue(Mat& DP, int W[], int V[], int K, int n)
{
	FOR(i, 1, n)
	{
		FOR(j, 1, K)
		{
			DP[i][j] = W[i-1] > j ? DP[i-1][j] : ( MAX( DP[i-1][j] , V[i-1] + DP[i-1][j - W[i-1] ] ));
		}
	}

#ifdef DEBUG
	cout <<"DP TABLE\n";
	FOR(i,0,n)
	{
		FOR(j,0, K)
		{
			cout << DP[i][j]<<" ";
		}
		cout << endl;
	}
#endif

	return DP[n][K];
}	

void includedSet(const Mat& DP, int W[])
{
	int i = DP.size() - 1;
	int j = DP[0].size() -1;

	Vec Set;
	while( i > 0 && j > 0)
	{
		if(DP[i][j] == DP[i-1][j])
		{
			i --;
			continue;
		}

		Set.push_back(W[i-1]);
		j = j - W[i-1];
		i --;
	}

	DFOR(i , Set.size()-1, 0)
	{
		cout << Set[i] <<" ";
	}
	cout << endl;
}

int main()
{
	int W[] = {1, 3, 4, 5};
	int V[] = {1, 4, 5, 7};

	int n = sizeof(W)/sizeof(W[0]);
	int K = 7;
	Mat DP(n+1, Vec(K+1, 0));
	cout << "Max value = " << getMaxValue(DP, W, V, K, n) << endl;
	cout <<"Included weights in set:\n ";
	includedSet(DP, W);

	return 0;
}
