/* Given a string, find the length of the longest substring without repeating characters. 
 * For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6. 
 * For “BBBB” the longest substring is “B”, with length 1. For “GEEKSFORGEEKS”, there are two longest substrings 
 * with length 7.
 **/

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

void canInclude(const string& S, Vec& V, int& currLen, int i)
{
	int prevIdxOfIthChar = V[KEY(S[i])];
	if(prevIdxOfIthChar == -1 || prevIdxOfIthChar < (i - currLen))
	{
		currLen ++;
	}
	else
		currLen = i-prevIdxOfIthChar;

	V[ KEY(S[i]) ] = i;
}

int getlongestUniqueSubStr(const string& S)
{
	int maxLen = 1;
	Vec V(ALPHABET_SIZE, -1);
	int currLen = 1;
	V[ KEY(S[0])] = 0;

	FOR(i, 1, S.size())
	{
		canInclude(S, V, currLen, i);
		maxLen = MAX(maxLen, currLen);
	}

	return maxLen;
}


int main()
{
	string S = "GEEKSFORGEEKS";

	cout << getlongestUniqueSubStr(S) << endl;

	return 0;
}
