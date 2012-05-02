#include <iostream>
#include <climits>
#include <string>
#include <vector>

using namespace std;
#define STRING_LEN 20

class PasswordXPalindrome
{

private:
	string input_str;
	int occurrence[26];
	vector<string> allPossiblePalindromes;

	bool isPalindrome();
	bool isPalindromePossible();
	void createPossiblePalindromes();
	int calculateMinSwaps(string str);
	void print_distance_matrix(vector< vector<int> >);
	void print_occurrence();
	void print_allPossiblePalindromes();
public:
	PasswordXPalindrome();
	PasswordXPalindrome(string str);
	int minSwaps();

};

