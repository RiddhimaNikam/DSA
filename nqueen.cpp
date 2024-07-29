#include<iostream>
using namespace std;
int grid[10][10];

void print(int n) 
{
	for (int i = 0;i <= n-1; i++) 
	{
	for (int j = 0;j <= n-1; j++) 
		{
			cout <<grid[i][j]<< " ";
		}
	cout<<endl;
	}
	cout<<endl;
	cout<<endl;
}
bool isSafe(int col, int row, int n) 
{
	// Loop 1: Check if there is any queen in the same column above the current position.
	for (int i = 0; i < row; i++) 
	{
		if (grid[i][col]) 
		{
			return false;
		}
	}
	// Loop 2: Check if there is any queen in the upper-left diagonal.
	for (int i = row,j = col;i >= 0 && j >= 0; i--,j--) 
	{
		if (grid[i][j]) 
		{
			return false;
		}
	}
	// Loop 3: Check if there is any queen in the upper-right diagonal.
	for (int i = row, j = col; i< n && j >= 0; j--, i++) 
	{
		if (grid[i][j]) 
		{
			return false;
		}
	}
	return true;
}
bool solve (int n, int row) 
{
		if (n == row) 
		{
			//all queens have been successfully placed on the board
			print(n);
			return true;
		}

		bool res = false;
		for (int i = 0; i<n ;i++) 
		{
			if (isSafe(i, row, n)) 
			{
				grid[row][i] = 1;
				res = solve(n, row+1) || res;//to check if solution is found or not
				grid[row][i] = 0;
			}
		}
	return res;
}
int main()
{
	int n;
	char ch;
	
	do
	{
	
	cout<<"Enter the number of queen"<<endl;
	cin >> n;
	for (int i = 0;i < n;i++) 
	{
		for (int j = 0;j < n;j++) 
		{
			grid[i][j] = 0;
		}
	}
	bool res = solve(n, 0);
	if(res == false) 
	{
		cout << "Not possible" << endl; 
	} 
	else 
	{
		cout << endl;
	}
	cout<<"Do you want to Continue:";
	cin>>ch;
}while(ch=='Y'||ch=='y');
	return 0;
}