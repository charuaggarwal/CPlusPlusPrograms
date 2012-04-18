#include "MatrixMultiplier.h"
#include<climits>

#define for1i(n) for(int i=0; i<(int)n; i++)
#define min(a, b) a<b? a:b

MatrixMultiplier::MatrixMultiplier()
{

}

MatrixMultiplier::MatrixMultiplier( int matrix_dim[], int n)
{

	for(int i=0; i<n-1; i++)
	{
		//create empty row
		vector<int> new_row;
		for(int j=0; j<n-1; j++)
		{ // initiaze each row
			new_row.push_back(INT_MAX);
		}
		matrix_result.push_back(new_row);
	}
//	print2Dvector(matrix_result);
	createMatrixHash(matrix_dim, n);
	
}

void MatrixMultiplier::print2Dvector( vector<vector<int> > matrix_result)
{
	cout<<endl;
	for(int r=0; r<matrix_result.size();r++)
	{	cout<<" | ";
		for(int c = 0;c<matrix_result[r].size(); c++)
			cout<<matrix_result[r][c]<<" ";
		cout<<"| "<<endl;
	}
}

// fills in the matrix_result array with matrix multiplication costs
int MatrixMultiplier::createMatrixHash(int matrix_dim[], int len)
{
	 // Set left to write diagonal to min cost 00
 	 for1i(len-1)
	 {
	 	matrix_result[i][i] = 0;
	 }
	 //print2Dvector(matrix_result);
	
	// Set the cost of multiplying i, i+1 matrices
	for(int sz=1; sz<=len-2; sz++)
	{
		for(int i=0; i+sz<=len-2; i++)
		{
			matrix_result[i][i+sz]=min_cost(i, i+sz, matrix_dim, len); 
		}
	}
	print2Dvector(matrix_result);

}

int MatrixMultiplier::min_cost(int l, int h, int matrix_dim[], int len)
{
	int cost = INT_MAX;
	int temp = 0;

	for(int i=l; i<h; i++)
	{	
		temp = matrix_result[l][i] + matrix_result[i+1][h] + matrix_dim[l] *matrix_dim[i+1] *matrix_dim[h+1];
		cost = min(cost, temp);
	}
	return cost;
}

int MatrixMultiplier::getMinCost()
{
	cout<<"Min Cost: "<<matrix_result[0][matrix_result[0].size()-1]<<endl;
	return matrix_result[0][matrix_result[0].size()-1];
}
