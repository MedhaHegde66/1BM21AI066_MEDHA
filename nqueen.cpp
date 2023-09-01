

#include <bits/stdc++.h>
#define N 4
using namespace std;


void Solution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		if(board[i][j])
			cout << "Q ";
		else cout<<". ";
		printf("\n");
	}
}


bool isSafe(int board[N][N], int row, int col)
{
	int i, j;


	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;


	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;


	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}


bool NQUtil(int board[N][N], int col)
{

	if (col >= N)
		return true;


	for (int i = 0; i < N; i++) {


		if (isSafe(board, i, col)) {


			board[i][col] = 1;


			if (NQUtil(board, col + 1))
				return true;


			board[i][col] = 0;
		}
	}


	return false;
}


bool NQueen()
{
	int board[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };

	if (NQUtil(board, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}

	Solution(board);
	return true;
}

int main()
{
	NQueen();
	return 0;
}

