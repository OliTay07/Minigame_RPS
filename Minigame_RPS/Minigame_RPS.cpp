// Minigame_RPS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//Include a new header
#include <ctime>

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);
char askToPlayAgain();


int main()
{
    //This is us 
    char player;
    //This is the opponent
    char computer;
    // Stores the users choice to play again
    char playAgain;

    do {


        //Retrieving & showing the players choice
        player = getUserChoice();
        std::cout << "Your choice: ";
        showChoice(player);

        //Retrieving & showing the computers choice
        computer = getComputerChoice();
        std::cout << "Opponents choice: ";
        showChoice(computer);

        //Chooses the winner
        chooseWinner(player, computer);

        playAgain = askToPlayAgain();
    }

    //Start the game again if the user clicks 'Y'
    while (playAgain == 'Y');

    //State the following message if the user clicks 'N'
    std::cout << "Thanks for playing! Goodbye.\n";

    return 0;

}

//Obtain the Users choice
char getUserChoice() {

    char player;
    std::cout << "Rock, Paper, Scissors Shoot!\n";

    do {
        std::cout << "Choose one of the following: \n";

        //Line of code used to underline the above text - aesthetic purposes
        std::cout << "****************************\n";
        std::cout << "'R' for Rock \n";
        std::cout << "'P' for Paper \n";
        std::cout << "'S' for Scissors \n";
        std::cin >> player;

        //Conver to uppercase incase user inputs lowercase
        player = toupper(player);

        //Prompt the user to choose an option again if the players input does not equal R, P, S - cant move forward unless the player chooses an option
    } while (player != 'R' && player != 'P' && player != 'S');

    return player;
}

//Obtain the Computers choice - will be chosen at random
char getComputerChoice() {
    
    //Generate a random seed
    srand(time(0));

    //Generating a random number 1 - 3 
    int num = rand() % 3 + 1;
    
    switch (num) {

        //If the number generated = 1 then return 'R' - the computer will choose Rock
        case 1: return 'R';

        //If the number generated = 2 then return 'P' - the computer will choose Paper
        case 2: return 'S';

        //If the number generated = 3 then return 'S' - the computer will choose Scissors
        case 3: return 'S';
    }
    
    return 0;
}
void showChoice(char choice) {
   
    switch (choice) {

    case 'R': std::cout << "Rock \n";
        break;

    case 'P': std::cout << "Paper \n";
        break;

    case 'S': std::cout << "Scissors \n";
            break;
    }
}

void chooseWinner(char player, char computer) 
{

    switch (player) {
        // If the player picks Rock & the computer picks Rock the game is a tie
    case 'R': if (computer == 'R') {
        std::cout << "It's a tie! \n";
    }
            // If the player picks Rock & the computer picks Paper the computer wins
            else if (computer == 'P') {
        std::cout << "You lose! \n";
    }
            // If the player picks Rock & the computer picks anything else - Scissors - the player wins
            else {
        std::cout << "You Win! \n";
    }
            break;

            // If the player picks Paper & the computer picks Paper the game is a tie
    case 'P': if (computer == 'P') {
        std::cout << "It's a tie! \n";
    }
            // If the player picks Paper & the computer picks Scissors the computer wins
            else if (computer == 'S') {
        std::cout << "You lose! \n";
    }
            // If the player picks Paper & the computer picks anything else - Rock - the player wins
            else {
        std::cout << "You Win! \n";
    }
            break;

            // If the player picks Scissors & the computer picks Scissors the game is a tie
    case 'S': if (computer == 'S') {
        std::cout << "It's a tie! \n";
    }
            // If the player picks Scissors & the computer picks Rock the computer wins
            else if (computer == 'R') {
        std::cout << "You lose! \n";
    }
            // If the player picks Scissors & the computer picks anything else - Paper - the player wins
            else {
        std::cout << "You Win! \n";
    }
            break;


    }


}

char askToPlayAgain()
{
    char choice;
    do {
        //Ask the user if they want to play again
        std::cout << " \n";
        std::cout << "Do you want to play again? \n";
        std::cout << "*************************** \n";
        std::cout << "'Y' for Yes \n";
        std::cout << "'N' for No \n";
        std::cin >> choice;
        
        //Conver to uppercase incase user inputs lowercase
        choice = toupper(choice);
        //Prompt the user to choose an option again if the players input does not equal Y, N, Q - cant move forward unless the player chooses an option
    } while (choice != 'Y' && choice != 'N');
    


    return choice;


}








// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
