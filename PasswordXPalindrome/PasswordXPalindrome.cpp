#include "PasswordXPalindrome.h"

#define NUM_OF_ALPHABETS 26
#define for1i(n) for(int i=0; i<(int)n ; i++)
#define min(a, b, c) (a<b && a<c)? a: (b<a && b<c)? b:c

PasswordXPalindrome::PasswordXPalindrome()
{
	input_str="";
	for1i(NUM_OF_ALPHABETS)
	{
		occurrence[i]=0;
	}
}

PasswordXPalindrome::PasswordXPalindrome(string str)
{
	input_str.append(str);
	cout<<endl<<"String is: "<<input_str<<endl;
	for1i(NUM_OF_ALPHABETS)
	{
		occurrence[i]=0;
	}
}

int PasswordXPalindrome::minSwaps()
{
	if(!isPalindromePossible())
	{
		return -1;
	}

	if(isPalindrome())
	{
		return 0;
	}
	// handle non-palindrome case

	return -1 ;
}

int PasswordXPalindrome::palindromeDistance()
{
	int input_str_len = input_Str.length();

	// Find if first half has unique integers
	if(input_str_len%2)
	{ half_len = input_str_len>>1 + 1; }
	else
	{ half_len = input_str_len>>1; }
	
	string new_str("");
	while(1)
	{
		while
	}
}

bool PasswordXPalindrome::isPalindrome()
{
	int input_str_len = input_str.length();
	for1i(input_str_len)
	{
		if(input_str[i] != input_str[input_str_len-1-i])
		{
			return false;
		}
	}
	return true;
}

bool PasswordXPalindrome::isPalindromePossible()
{
	int occurrence1 = 0;
	// the string could be a palindrome, each alphabet in the
	// string should occur twice. For odd size of string only one alphabet
	// can occur once
	for1i(input_str.size())
	{
		occurrence[input_str[i] -'a'] += 1;
//		cout<<" "<<input_str[i]-'a'<<" ";
	}
	// print_occurrence();
	for1i(NUM_OF_ALPHABETS)
	{
		if(occurrence[i] > 2)
		{ return false;}
		else if(occurrence[i] == 1)
		{
			occurrence1 +=1;
			if(occurrence1>1)
			{ return false;}
		}
	}
	return true;
}

void PasswordXPalindrome::createPossiblePalindromes()
{

}
 
int PasswordXPalindrome::calculateMinSwaps(string palindrome)
{
	// Using Levenshtein Distance

	int matrix_size = input_str.length()+1;

	vector< vector<int> > distance_matrix;
	for1i(matrix_size)
	{
		vector<int> new_row;
		for(int j=0; j<matrix_size; j++)
		{
			new_row.push_back(INT_MAX);
		}
		distance_matrix.push_back(new_row);
	}

	// Populate the distance matrix
	
	for1i(matrix_size)
	{
		distance_matrix[0][i] = i;
		distance_matrix[i][0] = i;
	}
	int distance = 0;
	for(int i=1; i<matrix_size; i++)
	{
		for(int j=1; j<matrix_size; j++)
		{
			distance = min(distance_matrix[i-1][j],
					distance_matrix[i][j-1],
					distance_matrix[i-1][j-1]);
			if(input_str[i-1] == palindrome[j-1])
			{ distance_matrix[i][j] = distance; }
			else
			{ distance_matrix[i][j] = distance+1; }
		}
	}
	// print_distance_matrix(distance_matrix);
	return distance_matrix[matrix_size-1][matrix_size-1];
}

void PasswordXPalindrome::print_distance_matrix(vector< vector<int> > distance_matrix)
{
	int matrix_size = distance_matrix.size();

	for(int i=0; i<matrix_size; i++)
	{
		cout<<endl<<" | ";
		for(int j=0; j<matrix_size; j++)
		{
			cout<<distance_matrix[i][j]<< " ";
		}
		cout<<"| "<<endl;
	}
}

void PasswordXPalindrome::print_occurrence()
{
	cout<<endl<<" [ " ;
	for1i(NUM_OF_ALPHABETS)
	{
		cout<<occurrence[i]<< " ";
	}
	cout<<" ] "<<endl;
}

void PasswordXPalindrome::print_allPossiblePalindromes()
{
	vector<string>::iterator itr;
	cout<<endl<<"All Possible Strings "<<endl;
	for(itr =allPossiblePalindromes.begin();itr!=allPossiblePalindromes.end(); itr++ )
	{
		cout<<" [ "<<*itr<<" ] "<<endl;
	}
}
