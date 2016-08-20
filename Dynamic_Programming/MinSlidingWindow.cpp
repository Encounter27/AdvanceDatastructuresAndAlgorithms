/***********************************************************************************
 * Given a set T of characters and a string S, find the minimum window in S 
 * which will contain all the characters in T in complexity O(n).
 *
 * eg,
 * S = “ADOBECODEBANC”
 * T = “ABC”
 *
 * Minimum window is “BANC”. 
 **********************************************************************************/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<limits.h>

using namespace std;

#define SIZE 256
#define FOR(i, a, b) for( int i = (a); i <= (b); ++i)

typedef vector< int > vec;

void minSlidingWindow(const string& T, const string& S)
{
	int tLen = T.size();
	int sLen = S.size();
	vec NF(SIZE, 0);

	FOR(i,0, sLen-1)
		NF[S[i]]++;

	vec HF(SIZE, 0);

	int count = 0;
	int L = 0, R = INT_MAX;

	for(int l = 0, r = 0; r < tLen; ++r)
	{
		if(NF[T[r]] == 0)
			continue;

		HF[T[r]]++;
		if(NF[T[r]] >= HF[T[r]])
		{
			count++;
		}

		if(count == sLen)
		{
			while(NF[T[l]] == 0 || NF[T[l]] < HF[T[l]])
			{
				if(HF[T[l]] > NF[T[l]])
					HF[T[l]] --;
				l++;
			}

			if((R-L) > (r-l))
			{
				R = r;
				L = l;
			}	
		}
	}

	if(R != INT_MAX)
	{
		FOR(i,L,R)
			cout<< T[i];
	}
	else
		cout << "All char set is not present !!" ;

	cout << endl;
}


int main()
{
	string T = "acbbaca";
	string S = "aba";

	minSlidingWindow(T, S);


	return 0;
}
