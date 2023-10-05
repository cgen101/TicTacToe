// File Name: main.cpp
//
// Author: Chloe Gentry, c638
// Collaborators: Joy Davis, hxo4
// Date: 4/17/2023
// Assignment Number: 6
// CS 2308 Spring 2023
//
// This program is a tic tac toe game, where 2 users can either
//   enter a coordinate to play a move, or undo the last 
//   player's move.

#include <iostream>
#include "GameState.h"
using namespace std; 

int main() { 
  GameState game;
  Move move; 
  string input;
  int x, y;
  int prevPlayer;
  int currMove;
  int count=0;

  GameState();
  game.displayBoardState(cout); 

  do { 
    cout << "Player " << game.getCurrentPlayer() << " make a turn." << endl;
    cin >> input;
    
    if (input=="undo") { 
      if (game.undoLast()==false) { 
        cout << "No moves to undo." << endl;
      } else { 
      game.displayBoardState(cout);
      count--;
      }
    } else if (input != "move") { 
        getline (cin, input); 
        cout << "Invalid command" << endl;
    
    } else { 
      cin >> x >> y;  
      prevPlayer=game.getCurrentPlayer();
      currMove=game.addMove(Move(x, y)); 

        if (currMove == -1) { 
          cout << "Incorrect move. Please try again." << endl;
        } else if (x<0||x>2||y<0||y>2) { 
          cout << "Invalid command" << endl;
        } else {
          game.displayBoardState(cout);
          count++;
        }

        if (count==9) { 
        break;
        } 
    }
  } while (game.checkLastPlayerWin()!=1);

  if (game.checkLastPlayerWin()==0) 
    cout << "It's a draw!" << endl;
  else 
    cout << "Player " << prevPlayer << " won!" << endl;
  
}