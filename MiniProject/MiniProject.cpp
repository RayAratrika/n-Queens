#include"pch.h"
#include<stdio.h>
#include<math.h>

int board[20], count;

void printBoard(int n)
{
	int i, j; 
	printf("\n\nSOLUTION %d:\n\n", ++count);

	/*for (i = 1; i <= n; ++i)
		printf("\t%d", i);*/

	for (i = 1; i <= n; ++i)
	{
		printf("\n");
		for (j = 1; j <= n; ++j)
		{
			if (board[i] == j)
				printf("\tQ");
			else
				printf("\t."); 
		}
	}
}

int placeQueen(int row, int column)		//BACKTRACKING
{
	int i;
	for (i = 1; i <= row - 1; ++i)
	{
		if (board[i] == column)
			return 0;
		else
			if (abs(board[i] - column) == abs(i - row))
				return 0;
	}

	return 1; 
}

void solveBoard(int row, int n)
{
	int column;
	for (column = 1; column <= n; ++column)
	{
		if (placeQueen(row, column))
		{
			board[row] = column; 
			if (row == n) 
				printBoard(n); 
			else
				solveBoard(row + 1, n);
		}
	}
}
int main()
{
	int n;
	printf(" - N Queens Problem Using Backtracking -");
	printf("\n\nEnter number of Queens:"); scanf_s("%d", &n);
	solveBoard(1, n);
	printf("\n\n");
	return 0;
}