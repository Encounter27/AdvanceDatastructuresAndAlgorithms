/*******************************************************************************************************
Given an array that contains both positive and negative integers, find the product of the maximum product
subarray. Expected Time complexity is O(n) and only O(1) extra space can be used.

Examples:

Input: arr[] = {6, -3, -10, 0, 2}
Output:   180  // The subarray is {6, -3, -10}

Input: arr[] = {-1, -3, -10, 0, 60}
Output:   60  // The subarray is {60}

Input: arr[] = {-2, -3, 0, -2, -40}
Output:   80  // The subarray is {-2, -40}
******************************************************************************************************/

#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

#define SIZE(arr) sizeof(arr)/sizeof(arr[0])

void maxProdcut(int arr[], int n) 
{
	int max_so_far = INT_MIN;
	int maxEndingHere = arr[0];
	int minEndingHere = arr[0];

	for ( int i = 1; i < n ; i++)	
	{
		if(arr[i] == 0) // Till i-1 pos if the result is negative then definately at i th pos zero would be the result, as zero is greater.
		{
			max_so_far = max(max_so_far, 0);
			continue;
		}
		if(arr[i-1] == 0) // start a new sequence
		{
			maxEndingHere = minEndingHere = arr[i];
			max_so_far = maxEndingHere > max_so_far ? maxEndingHere : max_so_far;
			continue;
		}

		int temp = maxEndingHere;
		maxEndingHere = max(maxEndingHere * arr[i], minEndingHere * arr[i]);
		minEndingHere = min( temp * arr[i] , minEndingHere * arr[i]);

		max_so_far = maxEndingHere > max_so_far ? maxEndingHere : max_so_far;
	}

	cout<< max_so_far<<endl; 

}

// Driver program
int main()
{
	// try all bellow test cases
	int arr[] = {-1,-3,-4}; // expectde 3
	int n =  SIZE(arr);
	cout << "res = ";
	maxProdcut(arr, n);

	int arr1[] = {1, -2, -3, 0, 7, -8, -2}; // expected 112
	n =  SIZE(arr1);
	cout << "res = ";
	maxProdcut(arr1, n);

	int arr2[] = {0,0,0,0,0}; // expected 0
	n =  SIZE(arr2);
	cout << "res = ";
	maxProdcut(arr2, n);

	int arr3[] = {0,0,-3,0,0}; // expected 0
	n =  SIZE(arr3);
	cout << "res = ";
	maxProdcut(arr3, n);

	return 0;
}
