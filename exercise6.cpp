/*
    Redo the "Bulls and Cows" game from exercise 12 in Chapter 4 to use four letters rather than 
    four digits.
*/


#include <iostream>
#include <vector> 
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Function to create a vector of 4 random uppercase letters ranging from A-Z
vector<char> generateRandLetters()
{
    vector<char> v;

    for (int i = 0; i < 4; i++) {
        // Generate a random number in the range of 0-25 (for A-Z)
        int randomIndex = rand() % 26;
        // Convert the random index to an uppercase letter
        char randomLetter = 'A' + randomIndex;

        // Check if the letter is already in the vector
        bool isDuplicate = false;
        for (char c : v) {
            if (c == randomLetter) {
                isDuplicate = true;
                break;
            }
        }

        // If the letter is not a duplicate, add it to the vector
        if (!isDuplicate) {
            v.push_back(randomLetter);
        }
    }

    return v;
}


int main() 
{
    // Seed the random number generator with the current time once at the start of the game
    srand(time(0));

    // Declare and initialize a boolean to play the game or not
    bool wantsPlay = true;

    // Declare and initialize a guess counter
    int guessCounter = 0;

    // Play the game so long as the bool is true
    while (wantsPlay){
        // Ask the user if they want to play and save in a string
        cout << "Do you want to play a letters guessing game? (y/n)" << endl;
        string response;
        cin >> response;

        if (response == "y")
        {
            // Reset guess counter for each game
            guessCounter = 0;
            
            // Generate a vector of 4 random letters
            vector<char> letterVec = generateRandLetters();

            // Declare a vector to store guess letters
            vector<char> guessVec;

            // Declare and initialize bull and cow counts
            int bulls = 0;
            int cows = 0;

            // Use a while loop to play the game until all 4 letters are guessed in the correct order
            while (bulls != 4){
                // Clear the vector of guesses for each iteration
                guessVec.clear();
                // Reset bull and cow counts for each iteration
                bulls = 0; 
                cows = 0;

                // Prompt the user for a guess of 4 letters and put those values in a string
                cout << "Please guess 4 letters A-Z (ex: ABCD): " << endl;
                string guess;
                cin >> guess;
                
                // Populate guessVec with the user's input letters
                for (int i = 0; i < 4; i++) {
                    guessVec.push_back(guess[i]);
                }

                for (int i = 0; i < guessVec.size(); i++ )
                {
                    // Check if each guess letter matches the letter at the same position in the vector
                    if (guessVec[i] == letterVec[i])
                    {
                        // If match is found, incrememt bulls by 1
                        bulls++;
                    }
                    // Check if each guess letter is found somewhere in the letter vector, but not at the same position
                    for (int j = 0; j < letterVec.size(); j++ )
                    {
                        if (guessVec[i] == letterVec[j] && i != j )
                        {
                            // If the same letter is found but in a different position in the vector, increment cows by 1
                            cows++;
                        }
                    }
                }

                // Increment the guess counter by 1 each loop
                guessCounter++;

                // Output based on number of bulls found in guessVec
                if (bulls == 4){
                    cout << "Correct! The letters are: " << guess << endl;
                    cout << "Guess counter: " << guessCounter << endl;
                } else {
                    cout << bulls << " bulls and " << cows << " cows" << endl;
                }

            } 
        } else if (response == "n")
        {
            cout << "Thanks for playing!" << endl;
            // Set the bool to false to terminate the while loop
            wantsPlay = false;
        } else
        {
            cerr << "Error: Invalid Input." << endl;
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}