/*********************************************************************************************
Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.

Examples:

Input :
arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}
k = 3
Output :
3 3 4 5 5 5 6

Input :
arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}
k = 4
Output :
10 10 10 15 15 90 90
**********************************************************************************************/

#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b) ; ++i)

void slidingMAX(int A[], int K, int N)
{
	deque< int > DQ;

	DQ.push_back( 0);
	FOR(i,1,N)
	{
		while(!DQ.empty() && DQ.front() < (i-K+1))
		{
			DQ.pop_front();
		}

		while(!DQ.empty() && A[DQ.back()] < A[i])
		{
			DQ.pop_back();
		}

		DQ.push_back(i);


		if(i > K-2)
			cout << A[DQ.front()] <<" ";
	}

	cout << endl;
}

int main()
{
	int k = 4, n = 10;
	int arr[] = {9,6, 11, 8, 10, 5,4, 13, 93, 14};

	slidingMAX(arr, k, n);

	return 0;
}
