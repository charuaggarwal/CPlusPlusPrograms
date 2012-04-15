#include<iostream>


using namespace std;

void printarr(int *s, int n);
void sortArray(int *s, int n);
void smallestUnsortedArray(int *, int *, int n);

void getSmallestUnsorted(int *s, int *result, int n)
{
	printarr(s, n);
	sortArray(s, n);
	printarr(s, n);
	smallestUnsortedArray(s, result, n);
	printarr(s, n);

}

void smallestUnsortedArray(int *s, int *, int n)
{
	int i=n-1;
	while(i>0 && *(s+i)==*(s+i-1))
	{
		i--;
	}

	if(i==0)
	return;
	else
	{
		int temp = 0;
		temp = *(s+i-1);
		*(s+i-1) = *(s+i);
		*(s+i)=temp;
		return;
	}

}

void sortArray(int *s, int n)
{
	if(n==0 || n==1)
	 return;

	// do insertion sort
	int temp = 0;
	int j = 0, val=0;
	for(int i=0;i<n-1;i++)
	{	val = *(s + i + 1);
		j = i+1;
		while(j>0 && val<*(s+j-1))
		{
			*(s+j) = *(s+j-1);
			j--;
		}
		if(j!=i+1)
		*(s+j) = val;
	}
	return;
}

void printarr(int *s, int n)
{
	cout << endl<<"{ "<<*s;
	for(int i=1; i<n; i++)
	{
		cout<<", "<<*(s+i);
	}
	cout<<" }"<<endl;
	return;
}


int main()
{

	int s[] = {4, 3, 2, 1};
	int *result = new int[4];
	int n = sizeof(s)/ sizeof(int);
	getSmallestUnsorted(s, result, n);
	return 1;
}
