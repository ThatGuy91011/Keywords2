#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
using namespace std;



int main()
{
	//String to hold the user's name
	string name;

	//string to check if the player wants to play again or not
	string wantToPlayAgain;
	
	// Display Title of the program to the user
	cout << "-----Welcome to Keywords II: Electric Boogaloo-----" << endl << endl;
	
	// Ask the recruit to log in using their name
	cout << "Please log in with your first name: ";
	getline(cin, name);
	cout << endl << "Welcome " << name << endl << endl;

	// Display an overview of what Keywords II is to the recruit 
	cout << "This simulation is to train you in the upcoming Keyword War. The other side is tricky, and their keywords are unknown to us." << endl;
	cout << "However, through a program such as the one you are about to use, we can guess what that word is letter by letter." << endl;

	// Display directions to the recruit on how to use Keywords
	cout << "This program is similar to the childhood game of Hangman. Guess a letter and the program will tell you whether it is in the word or not." << endl;
	cout << "Good luck, " << name << endl << endl;

	// Create an int var to count the number of simulations being run starting at 1
	int simulationNumber = 1;
	do
	{
		// Display the simulation # is starting to the recruit.
		cout << endl <<  "Simulation #" << simulationNumber << " starting..." << endl << endl << endl;


		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
		for (int x = 0; x < 3; x++)
		{

			//A variable to hold the maximum number of wrong answers a player can give before they lose
			const int MAX_WRONG = 8;

			// Create a collection of 10 words you had written down manually
			vector<string> words;
			words.push_back("UNKNOWN");
			words.push_back("ENEMY");
			words.push_back("WATCHTOWER");
			words.push_back("RENDEZVOUS");
			words.push_back("TONIGHT");
			words.push_back("TRAPWORD");
			words.push_back("COMPUTER");
			words.push_back("MISSION");
			words.push_back("TARGET");
			words.push_back("IMPOSSIBLE");

			//Randomizes the word choice
			srand(static_cast<unsigned int>(time(0)));
			random_shuffle(words.begin(), words.end());

			//String variable to hold the word itself in an array
			const string THE_WORD = words[0];

			//Variable to hold how many wrong guesses the player has given
			int wrong = 0;

			//String variable to hold the word with the letters the player has already guessed
			string soFar(THE_WORD.size(), '-');

			//String variable to hold the letters the player has already guessed
			string used = "";


			// While recruit hasn�t made too many incorrect guesses and hasn�t guessed the secret word
			while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
			{
				// Tell recruit how many incorrect guesses he or she has left
				cout << "You have " << (MAX_WRONG - wrong) << " wrong guesses left" << endl;
				
				// Show recruit the letters he or she has guessed
				cout << "You've already guessed: " << endl << used << endl;
				
				// Show player how much of the secret word he or she has guessed
				cout << "The word so far: " << endl << soFar << endl << endl;

				//Variable to hold the player's guess
				char guess;

				// Get recruit's next guess
				cout << name << ", enter your guess: ";
				cin >> guess;

				//Changes any lowercase letter the player inputs to be uppercase
				guess = toupper(guess);

				// While recruit has entered a letter that he or she has already guessed
				while (used.find(guess) != string::npos)
				{
					cout << "You've already guessed " << guess << endl;
					//  Get recruit �s guess
					cout << name << ", enter your guess: ";
					cin >> guess;
					guess = toupper(guess);
				}

				// Add the new guess to the group of used letters
				used += guess;

				// If the guess is in the secret word
				if (THE_WORD.find(guess) != string::npos)
				{
					//  Tell the recruit the guess is correct
					cout << "Correct " << name << ". " << guess << " is in the answer!" << endl;

					//  Update the word guessed so far with the new letter
					for (int i = 0; i < THE_WORD.length(); ++i)
					{
						if (THE_WORD[i] == guess)
						{
							soFar[i] = guess;
						}
					}
				}
				// Otherwise
				else
				{
					//  Tell the recruit the guess is incorrect
					cout << "Sorry, " << guess << " is not in the answer." << endl << endl;
					//  Increment the number of incorrect guesses the recruit has made
					++wrong;
				}


			}
			// If the recruit has made too many incorrect guesses
			if (wrong == MAX_WRONG)
			{
				// Tell the recruit that he or she has failed the Keywords II course.
				cout << "You have failed this time, " << name << ", but don't let it discourage you" << endl << endl;
			}
			// Otherwise
			else
			{
				// Congratulate the recruit on guessing the secret words
				cout << "You got it!" << endl << endl;
			}

			cout << "The word was " << THE_WORD << endl << endl;
		}
		// Ask the recruit if they would like to run the simulation again
		cout << "Want to play again?(Y/N) ";
		cin >> wantToPlayAgain;

		// If the recruit wants to run the simulation again
		if (wantToPlayAgain == "y" || wantToPlayAgain == "Y")
		{
			simulationNumber++;
		}

	} while (wantToPlayAgain == "y" || wantToPlayAgain == "Y");

	// Display End of Simulations to the recruit

	cout << "So long, " << name << endl;

	// Pause the Simulation with press any key to continue
	system("pause");
	return 0;
}