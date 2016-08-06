/* *************************************************************************************************
 * Given n non-negative integers representing the histogram's bar height where the 
 * width of each bar is 1, find the area of largest rectangle in the histogram.
 * For example, consider the following histogram with 7 bars of heights {6, 2, 5, 4, 5, 2, 6}.
 * The largest possible rectangle possible is 12.
 ***************************************************************************************************/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>

using namespace std;


#define FOR(i,a,b)  for(int i = (a); i < (b); ++i)
#define DFOR(i,a,b) for(int i = (a); i > (b); --i)
#define MAX(a, b)   (a) > (b) ? (a):(b)

#define AREA(a,b)   (a*b);

typedef stack< int > Stack;
typedef vector< int > Vec;
typedef vector< Vec > Mat;

int getLargestRectForEachRow(const Vec& A, const int n )
{
	Stack st;

	st.push(0);
	int maxArea = A[0];

	FOR(i,1,n)
	{
		while(!st.empty() && A[st.top()] < A[i])
		{
			st.pop();
		}
		maxArea = MAX(maxArea, A[i]*st.size());
		st.push(i);
	}

	while(!st.empty())
	{
		maxArea = MAX(maxArea, A[st.top()]*st.size());
		st.pop();
	}

	return maxArea;
}

int getAreaOfLargestRect(const Mat& mat, int row, int col)
{
	int maxArea = 0;
	Vec hist(col, 0);
	FOR(i, 0, row)
	{
		FOR(j, 0, col)
		{
			hist[j] += (mat[i][j]? 1 : 0);
		}

		maxArea = MAX(maxArea, getLargestRectForEachRow(hist, col));
	}

	return maxArea;
}

int main()
{
	int R, C;
	cin >> R >> C;
	Mat mat(R, Vec( C, 0));

	FOR(i, 0 , R)
	{
		FOR(j, 0, C)
		{
			cin >> mat[i][j]; 
		}
	}

	cout << "Area of biggest Rectangle with all 1s := " << getAreaOfLargestRect(mat, R, C) << endl;

	return 0;
}
