#include <iostream>
#include <vector>

using namespace std;
#define NUM_OF_MATRICES 5

class MatrixMultiplier
{
private:
	int row, col;
	vector<vector<int> > matrix_result;
	
	int createMatrixHash(int matrix_dim[], int len);
	int min_cost(int l, int h, int matrix_dim[], int len);
public:
	// initializes matrix_result;
	MatrixMultiplier();
	MatrixMultiplier(int matrix_dim[], int n);
	void print2Dvector( vector<vector<int> > matrix_result);
	int getMinCost();	
};
