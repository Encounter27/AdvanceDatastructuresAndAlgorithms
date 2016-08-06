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

int getLargestRect(int A[], int n)
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


int main()
{
	int arr[] = {6, 2, 5, 4, 5, 2, 6};
	cout <<"Area of largest rectangle = "<< getLargestRect(arr, sizeof(arr)/sizeof(arr[0])) << endl;

	return 0;
}
