#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

#define DEBUG

#define FOR(i,a,b) for( int i = (a); i <= (b); ++i)
#define DFOR(i,a,b) for( int i = (a); i >= (b); --i)
#define MAX(a, b)   (a) > (b) ? (a):(b)



typedef vector< bool > Vec;
typedef vector< Vec > Mat;


int isSumKPossible(Mat& dp, int A[], int n, int K)
{	
	FOR(i,1,n)
	{
		FOR(j,1,K)
		{
			dp[i][j] = A[i-1] > j ? dp[i-1][j] : (dp[i-1][j] || dp[i-1][j - A[i-1]] );
		}
	}

#ifdef DEBUG
	cout << "DP table for subset sum :\n";
	FOR(i, 0, n)
	{
		FOR(j,0,K)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
#endif


	return dp[n][K];
}

void includedSubSet(Mat& dp, int A[])
{
	vector< int > Set;

	int i = dp.size()-1;
	int j = dp[0].size()-1;

	while(i > 0 && j > 0)
	{
		if( dp[i][j] == dp[i-1][j])
		{
			i --;

			continue;
		}

		Set.push_back(A[i-1]);
		j = j - A[i-1];
		i --;
	}

	DFOR(i, Set.size()-1, 0)
		cout << Set[i] <<" ";

	cout <<endl;
}

int main()
{
	int A[] = {2, 3, 7, 8, 10};
	int K = 11;
	int n = sizeof(A)/sizeof(A[0]);

	Mat dp( n+1, Vec(K+1));

	FOR(i, 1, n)
		dp[i][0] = true;

	isSumKPossible(dp,A, n, K) ? printf("There exists a subset whose sum is %d\n", K):printf("There is no subset whose sum is %d\n", K);
	cout << "Included elements in the subset:\n";
	includedSubSet(dp, A);

	return 0;
}
