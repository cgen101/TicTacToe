// File Name: GameState.cpp
//
// Author: Chloe Gentry, c638
// Collaborators: Joy Davis, hxo4
// Date: 4/17/2023
// Assignment Number: 6
// CS 2308 Spring 2023
//
//Implementation of the GameState member functions

#include "GameState.h"
using namespace std;

//***********************************************************
// checkLastPlayerWin: Checks if a player has won. 
// Returns true if player has won, otherwise returns false.
//***********************************************************

bool GameState::checkLastPlayerWin() {
    char targetSymbol = getCurrentPlayer() ? 'x' : 'o';
    int sumHorizontal, sumVertical;
    for (int i = 0; i < 3; ++i){
        sumHorizontal = 0;
        sumVertical = 0;
        for (int j = 0; j < 3; ++j){
            sumHorizontal += boardState[i][j] == targetSymbol;
            sumVertical += boardState[j][i] == targetSymbol;
        }
        if (sumHorizontal == 3 || sumVertical == 3)
            return true;
    }
    int sumDiagonal1 = 0, sumDiagonal2 = 0;
    for (int i = 0; i < 3; ++i){
        sumDiagonal1 += boardState[i][i] == targetSymbol;
        sumDiagonal2 += boardState[i][2 - i] == targetSymbol;
    }
    if (sumDiagonal1 == 3 || sumDiagonal2 == 3)
        return true;

    return false;
}

//***********************************************************
// GameState: Creates the empty game board.
//***********************************************************

GameState::GameState() {
  for (int i=0; i<3; ++i) { 
    for (int j=0; j<3; ++j) { 
      boardState[i][j]='_';
    }
  }
}

//***********************************************************
// getCurrentPlayer: Gets the current player (1 or 0)
// Returns 0 or 1 depending on whose turn it is.
//***********************************************************

int GameState::getCurrentPlayer() {
  if (moveStack.currStackSize%2==0) { 
    return 0;
  } 
  return 1;
}

//***********************************************************
// addMove: Makes sure a player's move is valid before adding
//   the appropriate char to the board and pushing the move to 
//   the stack.
// Move move: User-defined coordinates they wish to play (x,y).
// Returns 0 if stack is full, -1 if coordinate is not empty, 
//   or 1 if move is valid and was successfully added. 
//***********************************************************

int GameState::addMove(Move move) { 
  char player = 'x'; 
    if (getCurrentPlayer()==1) { 
      player = 'o'; 
    }
  int x=move.x; 
  int y=move.y;
    if (boardState[x][y]=='_') { 
      boardState[x][y]=player;
      moveStack.push(move); 
        if(moveStack.currStackSize==9) { 
          return 0;
        } else { 
          return 1; 
        }
    } else { 
      return -1;
    }       
} 

//***********************************************************
// undoLast: Checks if there is any move to undo before removing
//   a move from the board and from the stack. 
// Returns true if move was successfully removed, otherwise 
//   returns false.
//***********************************************************

bool GameState::undoLast() {
  if (moveStack.currStackSize==0) { 
    return false;
  }
  
  Move lastMove=moveStack.top(); 
  boardState[lastMove.x][lastMove.y]='_';
  moveStack.pop(); 
  
  return true;
}

//***********************************************************
// displayBoardState: Displays the current state of the board.
//***********************************************************

void GameState::displayBoardState(std::ostream& out) {
  for (int i=0; i<3; ++i) { 
    for (int j=0; j<3; ++j) { 
      out << boardState[i][j];
    }
    out << endl;
  }
}
  


