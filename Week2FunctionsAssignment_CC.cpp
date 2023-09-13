/*
Clark Comstock
9/6/2023
GAME 2303
Professor Olive*/

#include <iostream>
#include <string>
using namespace std;

void DivisibleByTwo(int a, int b); //declaring function name
static string process(const string& s) //copied the code from the skills test, not entirely sure how it works but it does | Function 2
{
	string result;
	int len = s.length();
	for (int i = 0; i < len; i++)
		result = s[i] + result;
	return(result);
}
static void show(const string& s)//function 2
{
	cout << s << " -> " << process(s) << "\n";
}
static void RemoveVowels(string s) //function 3 || I don't want to talk about how long this took me to figure out
{
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
		{
			for (int j = i; j < len; j++)
			{
				s[j] = s[j + 1];
			}
			i--;
			len--;
		}
	}
	cout << s;
}

int main()
{
	//function 1
	cout << "Function 1: Enter two numbers and this function will tell you what" << endl;
	cout << "numbers between 0 and 1000 are divisible by both of those numbers\n" << endl;
	int num1;
	int num2;
	cout << "Please enter a positive integer between 1 and 1000: ";
	cin >> num1;
	cout << "Please enter a different possitive integer between 1 and 1000: ";
	cin >> num2;
	if (num1 == num2 || num1 < 1 || num2 < 1) //checks to see if the numbers input meet the requirements
	{
		while (num1 == num2 || num1 < 1 || num2 < 1) //numbers fail requirement check, user is asked to put new numbers in
		{
			cout << "You did not meet the requirements. Please enter a positive integer  between 1 and 1000: ";
			cin >> num1;
			cout << "Please enter a different possitive integer between 1 and 1000: ";
			cin >> num2;
		}
	}
	DivisibleByTwo(num1, num2);
	string temp; // I have no idea why, but without this right here
	getline(cin, temp); // the following getline func doesn't work properly and we skip right past function 2

	// function 2
	cout << "\nFunction 2: Reverse a string\n" << endl;
	string input;
	cout << "Please enter a string of text: ";
	getline(cin, input);
	show(input);

	// function 3 
	cout << "\nFunction 3: No more vowels\n" << endl;
	string func3Input;
	cout << "Please enter a string of text: ";
	getline(cin, func3Input); //getline took me almost an hour to figure out how to use. no where online did I find someone expressly say "use #include <string>"
	RemoveVowels(func3Input);
}

void DivisibleByTwo(int a, int b) //actual function 1
{
	int i;
	cout << "[";
	for (i = 1; i <= 1000; i++)
	{
		if (i % a == 0 && i % b == 0)
		{
			cout << " " << i;
		}
	}
	cout << " ] \n";
}