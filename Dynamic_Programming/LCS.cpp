#include<iostream>
#include<vector>
#include<string>

using namespace std;

#define DEBUG

#define FOR(i,a,b) for( int i = (a); i <= (b); ++i)
#define DFOR(i,a,b) for( int i = (a); i >= (b); --i)
#define MAX(a, b)   (a) > (b) ? (a):(b)



typedef vector< int > Vec;
typedef vector< Vec > Mat;


int getMaxLength(Mat& dp, const string& s1, const string& s2)
{	
	FOR(i,1,s1.size())
	{
		FOR(j,1,s2.size())
		{
			dp[i][j] = s1[i-1] == s2[j-1] ? dp[i-1][j-1]+1 : (MAX(dp[i-1][j], dp[i][j-1]));
		}
	}

#ifdef DEBUG
	cout << "DP table for LCS :\n";
	FOR(i,0,s1.size())
	{
		FOR(j,0,s2.size())
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
#endif


	return dp[s1.size()][s2.size()];
}

void includedCharInLCS(Mat& dp, const string& s1, const string& s2)
{
	vector< char > Set;

	int i = s1.size();
	int j = s2.size();

	while(i > 0 && j > 0)
	{
		if( dp[i][j] == dp[i-1][j] || dp[i][j] == dp[i][j-1])
		{
			dp[i-1][j] > dp[i][j-1] ?(i--):(j--);

			continue;
		}

		Set.push_back(s1[i-1]);
		i --;
		j --;
	}

	DFOR(i, Set.size(), 0)
		cout << Set[i] <<" ";

	cout <<endl;
}

int main()
{
	string S1="ABCDAF";
	string S2="ACBCF";

	Mat dp( S1.size() +1, Vec(S2.size() + 1, 0));

	cout << "Lengith of lcs = "<< getMaxLength(dp, S1, S2) << endl;
	cout << "Included charecters in LCS:\n";
	includedCharInLCS(dp, S1, S2);

	return 0;
}
