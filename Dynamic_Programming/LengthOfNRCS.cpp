/* Given a string, find the length of the longest substring without repeating characters. 
 * For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6. 
 * For “BBBB” the longest substring is “B”, with length 1. For “GEEKSFORGEEKS”, there are two longest substrings 
 * with length 7.
 */

#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>

using namespace std;

#define ALPHABET_SIZE 26
#define FOR(i,a,b) for( int i = (a); i < (b); ++i)
#define MAX(a, b) (a) > (b) ? (a):(b)
#define KEY(ch) (ch-'A')

typedef	vector< int > Vec;

void canInclude(const string& S, Vec& V, Vec& len, int curr)
{
	if(V[KEY(S[curr])] == -1 || (V[KEY(S[curr])] != -1 && V[KEY(S[curr])] < (curr - len[curr-1])))
	{
		len[curr] = len[curr-1] + 1;
	}
	else
		len[curr] = 1;
}

int getlongestUniqueSubStr(const string& S)
{
	int maxLen = 1;
	Vec V(ALPHABET_SIZE, -1);
	Vec len(S.size());
	len[0] = 1;
	V[ KEY(S[0])] = 0;

	FOR(i, 1, S.size())
	{
		canInclude(S, V, len, i);
		V[ KEY(S[i]) ] = i;
		maxLen = MAX(maxLen, len[i]);
	}

	return maxLen;
}


int main()
{
	string S = "GEEKSFORGEEKS";

	cout << getlongestUniqueSubStr(S) << endl;

	return 0;
}
