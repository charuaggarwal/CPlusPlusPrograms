#include<iostream>
#include<string>
#include<list>


using namespace std;

class Palindrome
{

public:

static int find(string str)
{
	list<char> result1, result2;
	list<char>::iterator itr;
	if(str.length()<=1)
	{
		return str.length();
	}
	
	int start=0;
	int end=str.size()-1;
	

	while((start<end) && (start < end))
	{
		while( (start<end) && (str.at(start) == str.at(end)) )
		{
			result1.push_back(str.at(start)); 
			result2.push_front(str.at(end));
			start++;end--;
		}
		if(start < end)
		{
			result1.push_back(str.at(start));
			result2.push_front(str.at(start));
			start++;
		}
	}
	if(end >= start)
	{
		result2.push_front(str.at(end));
	}
	int count = result1.size() + result2.size();
	itr = result1.end();
	result1.insert(itr, result2.begin(), result2.end());
	printlist(result1);
	return count;
}

static void printlist(list<char> &result)
{
	list<char>::iterator itr;
	cout<<endl;
	for(itr = result.begin(); itr!=result.end(); itr++)
	{
		cout<<" "<<*itr;
	}
	cout<< "Count: "<< result.size()<<endl;
}

};

int main()
{
	//string s="abab";
	//cout<<s<<endl;
	//int cnt = Palindrome::find(s);
	//cout<<"Count: "<<cnt<<endl;
	//string s="`abdfhdyrbdbsdfghjkllkjhgfds";
	string s="abd";
	cout<<s<<endl;
	int cnt = Palindrome::find(s);
	cout<<"Count: "<<cnt<<endl;
	return 1;
}
