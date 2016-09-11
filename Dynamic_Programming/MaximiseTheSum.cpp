/*****************************************************************************************************
Maximise the Sum

There is a matrix containing 2 rows and N columns. There are positive integers present in the matrix. 
You need to select certain cells in the matrix such that the sum of numbers in the selected cells are 
the maximum possible for the given matrix.

However, there are certain conditions that apply when you select a cell. If you select a cell you cannot
 select any cell adjacent to it. Adjacent would imply sideways, downwards,upwards and diagonally too.

In this problem, you need to print the maximum sum possible in a 2 x N matrix which satisfies the 
above-defined conditions.



Input

The First line contains T, the number of test cases.
Each test case starts with a single integer N, the number of columns in the matrix.
Next line contains N space-separated integers, i.e. numbers present in N columns of the first row.
The last line also contains N space-separated integers, i.e. numbers present in N columns of the second row.


Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) 
and y is the maximum sum possible in 2 x N matrix, according to the rules described in the above statement.



Constraints

1 <= T <= 1000

1 <= N <= 105

1 <= Matrixij <= 109



Sample test cases


Input

1
6
12 2 4 16 9 1
3 8 9 5 21 19
Output

Case #1: 47
Explanation
In the above example, if you were to select the cell 12, you cannot select 2, 3 or 8. If you were to select the cell 21,
 you cannot select cells 5, 16, 9, 1, 19.
***********************************************************************************************************************/
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i,n)   for(int i = (0); i < (n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define MAX( a, b) (a) > (b) ? (a):(b)

typedef long long ll;

inline void getInt(int& r)
{
	r = 0;
	char ch = getchar_unlocked();

	while(ch < '0' || ch > '9')
	{
		ch = getchar_unlocked();
	}

	while(ch >= '0' && ch <= '9')
	{
		r = (r << 3) + (r << 1) + (ch - '0');
		ch = getchar_unlocked();
	}
}


ll getMaxSum(int A[], int N)
{
	ll F2 = 0;
	ll F1 = A[0];
	ll Res;

	FOR(i, 1, N)
	{
		Res = MAX(F2+A[i], F1);
		F2 = F1;
		F1 = Res; 
	}

	return F1;
}

int main()
{
	int T;
	getInt(T);

	FOR(t, 1, T+1)
	{
		int N;
		getInt(N);

		int A[N];

		FOR(i,0,N)
		{
			getInt(A[i]);
		}
		FOR(i,0,N)
		{
			int a;
			getInt(a);
			A[i] = MAX(A[i], a);
		}

		printf("Case #%d: %lld\n", t, getMaxSum(A, N));
	}

	return 0;
}
