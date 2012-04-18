#include "MatrixMultiplier.h"





int main()
{

	cout<<"Hello"<<endl;
	//int matrix_dim[]={10, 20, 50, 1, 100};
	int matrix_dim[]={30, 35, 15, 5, 10, 20, 25};
	MatrixMultiplier MM(matrix_dim, sizeof(matrix_dim)/sizeof(int));
	MM.getMinCost();
	return 0;
}


