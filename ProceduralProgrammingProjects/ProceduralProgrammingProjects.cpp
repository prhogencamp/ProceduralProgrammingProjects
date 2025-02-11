// ProceduralProgrammingProjects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
using namespace std;

int getPlayerChoice();
int getComputerChoice();
int chooseWinner(int player, int computer);
void showChoice(int choice);
void declareWinner(int playerScore, int computerScore);
void updateScores(char winner, int& playerScore, int& computerScore);


int main()
{
    int playerScore = 0;
    int computerScore = 0;
    int playerChoice;
    int computerChoice;
    char winner;

    while (true) {
        playerChoice = getPlayerChoice();
        if (playerChoice == 4) {
            break;
        }
        cout << "Your Choice: " << endl;
        showChoice(playerChoice);

        computerChoice = getComputerChoice();
        cout << "Computer's Choice: " << endl;
        showChoice(computerChoice);

        winner = chooseWinner(playerChoice, computerChoice);
        updateScores(winner, playerScore, computerScore);
    }
    declareWinner(playerScore, computerScore);

    return 0;


}





int getPlayerChoice() {
    int player;
    while (true) {
        cout << "Make your choice:\n";
        cout << "1: Rock" << endl;
        cout << "2: Paper" << endl;
        cout << "3: Scissors" << endl;
        cout << "4: Quit" << endl;
        cin >> player;
        if (cin.fail() || player < 1 || player > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "That is not a valid input. Try again." << endl;
        }

        else {
            break;
        }

    }
    return player;
}
int getComputerChoice() {

    random_device engine;
    uniform_int_distribution<int>computerThrow(1, 3);

    // switch (computerThrow(engine)) {
   //  case 1: return 1;
    // case 2: return 2;
    // case 3: return 3;
     //}

    return computerThrow(engine);

}





int chooseWinner(int player, int computer) {
    if (player == computer) {
        return 'd'; //Draw
    }
    else if ((player == 1 && computer == 3) ||
        (player == 2 && computer == 1) ||
        (player == 3 && computer == 2)) {
        return 'p'; // Player win

    }
    else {
        return 'c'; // Computer win
    }

    return 0;
}

void updateScores(char winner, int& playerScore, int& computerScore) {
    if (winner == 'p') {
        cout << "You win this round!" << endl;
        playerScore++;
    }
    else if (winner == 'c') {
        cout << "Computer wins this round!" << endl;
        computerScore++;
    }
    else {
        cout << "It's a draw!" << endl;
    }
    cout << "Scores are Player: " << playerScore << ", Computer: " << computerScore << endl;
}

void declareWinner(int playerScore, int computerScore) {
    cout << "Final scores are Player: " << playerScore << ", Computer: " << computerScore << endl;
    if (playerScore > computerScore) {
        cout << "Congratulations! You've won the tournament!" << endl;
    }
    else if (computerScore > playerScore) {
        cout << "The computer has won the tournament. Better luck in the next tournament." << endl;
    }
    else {
        cout << "The tournament has ended in a tie!" << endl;
    }
}

void showChoice(int choice) {

    switch (choice) {
    case 1: cout << "Rock" << endl;
        break;
    case 2: cout << "Paper" << endl;
        break;
    case 3: cout << "Scissors" << endl;
        break;
    }
}

