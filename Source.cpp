#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
using namespace std;

int main()
{
	const int MAX_WRONG = 8;

	vector<string> words;
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());

	const string THE_WORD = words[0];
	int wrong = 0;
	string soFar(THE_WORD.size(), '-');
	string used = "";

	cout << "-----Welcome to Hangman!-----" << endl;

	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		cout << "You have " << (MAX_WRONG - wrong) << " wrong guesses left" << endl;
		cout << "You've already guessed: " << endl << used << endl;
		cout << "The word so far: " << endl << soFar << endl;

		char guess;
		cout << "Enter your guess: ";
		cin >> guess;
		guess = toupper(guess);
		while (used.find(guess) != string::npos)
		{
			
		}
	}
	return 0;
}