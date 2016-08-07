/* Given a 2D array, find the maximum sum subarray in it. For example, in the following 2D array, 
 * the maximum sum of subarray is 29.
 * 
 * {1,   2, -1, -4, -20},
 * {-8, -3,  4,  2,   1},
 * { 3,  8, 10,  1,   3},
 * {-4, -1,  1,  7,  -6}
 *
 */
#include<iostream>
#include<vector>
#include<stdio.h>
#include<limits.h>

using namespace std;

#define FOR( i , a, b) for( int i = (a); i < (b); ++i)
#define MAX(a, b )     (a) > (b)? (a):(b)

typedef vector< int > Vec;
typedef vector< Vec > Mat;

int kadaneAlgo(const Vec& T, int& maxU, int& maxD)
{
	int sum = T[0],  maxSum = T[0];
	maxU = 0;
	maxD = 0;

	FOR(i, 1, T.size())
	{
		//maxCurrEnd = MAX(T[i], maxCurrEnd + T[i]);
		//maxEndSofar = MAX(maxEndSofar, maxCurrEnd);

		if( T[i] > sum + T[i])
		{
			maxU = i;
			sum = T[i];
		}
		else
			sum += T[i];

		if(maxSum < sum)
		{
			maxSum = sum;
			maxD = i;
		}
	}

	return maxSum;
}

int getBiggestRect(const Mat& m, int& maxL, int& maxR, int& maxU, int& maxD)
{
	int ROW = m.size();
	int COL = m[0].size();
	Vec T;
	int maxSum = INT_MIN;
	int up , down;

	// Fix left
	FOR(left,0, COL)
	{
		int currSum = INT_MIN;
		T.clear();
		T.resize(ROW, 0);

		// Fix right
		FOR(right, left, COL)
		{
			FOR(row, 0, ROW)
			{
				T[row] += m[row][right];
			}

			// calculate for range left <---> right
			currSum = kadaneAlgo(T, up, down);

			if(currSum > maxSum)
			{
				maxL = left;
				maxR = right;
				maxU = up;
				maxD = down;
				maxSum = currSum;	
			}
		}
	}

	return maxSum;
}	

int main()
{
	int R, C;
	cin >> R >> C;

	Mat m(R, Vec(C));

	FOR(i, 0, R)
		FOR(j, 0, C)
		cin >> m[i][j];

	int left = -1, right = -1, up = -1, down = -1;
	cout << "Area of biggest rectangle sum = " << getBiggestRect(m, left, right, up, down) << endl;
	printf("Area left=%d right=%d up=%d down=%d \n", left, right, up, down);	

	return 0;
}
