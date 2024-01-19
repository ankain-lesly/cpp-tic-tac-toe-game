#include <iostream>
#include "dec.h"

// Globally Defined
using namespace std;

// Board
string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};

// Player
int player = 1;
int position = 0;

void introduction()
{
  cout << "Press [Enter] to begin: \n\n";

  getchar();
  cout << "\n\n";

  cout << "***********\n";
  cout << "Tic-Tac-Toe\n";
  cout << "***********\n";

  cout << "Player 1: X\n";
  cout << "Player 2: O\n";

  cout << "The 3x3 grid is show below:\n\n";

  cout << "     |     |      \n";
  cout << "  1  |  2  |  3   \n";
  cout << "_____|_____|_____ \n";
  cout << "     |     |      \n";
  cout << "  4  |  5  |  6   \n";
  cout << "_____|_____|_____ \n";
  cout << "     |     |      \n";
  cout << "  7  |  8  |  9   \n";
  cout << "_____|_____|_____ \n\n";
}

// Winner
bool is_winner()
{
  bool winner = false;
  // Checking rows
  if (board[0] == board[1] && board[1] == board[2] && board[0] != " ")
  {
    winner = true;
  }
  else if (board[3] == board[4] && board[4] == board[5] && board[3] != " ")
  {
    winner = true;
  }
  else if (board[6] == board[7] && board[7] == board[8] && board[7] != " ")
  {
    winner = true;
  }

  // Checking columns
  if (board[0] == board[3] && board[3] == board[6] && board[0] != " ")
  {
    winner = true;
  }
  else if (board[1] == board[4] && board[4] == board[7] && board[1] != " ")
  {
    winner = true;
  }
  else if (board[2] == board[5] && board[5] == board[8] && board[2] != " ")
  {
    winner = true;
  }

  // Checking diagonals
  if (board[0] == board[4] && board[4] == board[8] && board[0] != " ")
  {
    winner = true;
  }
  else if (board[2] == board[4] && board[4] == board[6] && board[3] != " ")
  {
    winner = true;
  }

  return winner;
}

// Is Board Filled
bool filled_up()
{
  bool isFilled = true;

  for (int i = 0; i < 9; i++)
    if (board[i] == " ")
      isFilled = false;

  return isFilled;
}

// Draw Board
void draw()
{
  cout << "     |     |      \n";
  cout << "  " << board[1 - 1] << "  |  " << board[2 - 1] << "  |  " << board[3 - 1] << "   \n";
  cout << "_____|_____|_____ \n";
  cout << "     |     |      \n";
  cout << "  " << board[4 - 1] << "  |  " << board[5 - 1] << "  |  " << board[6 - 1] << "   \n";
  cout << "_____|_____|_____ \n";
  cout << "     |     |      \n";
  cout << "  " << board[7 - 1] << "  |  " << board[8 - 1] << "  |  " << board[9 - 1] << "   \n";
  cout << "_____|_____|_____ \n\n";
}

// Set User Play Position
void set_position()
{
  cout << "Player " << player << "'s (Enter: (1-9))";
  while (!(cin >> position))
  {
    cout << "Please enter a valid number between (1-9)" << endl;
    cin.clear();
    cin.ignore();
  }

  while (board[position - 1] != " ")
  {
    cout << "Oops that position is already filled\n"
         << "Try again!\n"
         << endl;
    cin >> position;
    cout << endl;
  }
}

// Update Board
void update_board()
{
  if (player % 2 == 1)
    board[position - 1] = 'X';
  else
    board[position - 1] = 'O';
}

// Change Player
void change_player()
{
  if (player == 1)
    player++;
  else
    player--;
}

// Take Turn
void take_turn()
{
  // if (!is_winner() && !filled_up())
  while (!is_winner() && !filled_up())
  {
    // Invoking Game Functions
    set_position();
    update_board();
    change_player();
    draw();
  }
}

// End Game
void end_game()
{
  if (is_winner())
    cout << "There is a winner!" << endl;
  else if (filled_up())
    cout << "There is a tie!" << endl;
}