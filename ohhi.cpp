/**
 * ohhi.cpp
 *
 * EECS 183, Winter 2015
 * Project 3: 0h h1
 *
 * Kyle Kramer & Julian Frankel
 * krkyle      & frankelj
 *
 * This project allows users to play and solve 0h h1 boards in the command 
 * line
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

///////////////////////////////////////
// UTILITY FUNCTIONS //////////////////
///////////////////////////////////////

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    
    // variable and nested for loops to check each square of the board
    int numUnknown = 0;
    
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) {
            if (board[i][j] == UNKNOWN) {
                numUnknown++;
            }
        }
    }
    
    return numUnknown;
}


///////////////////////////////////////
// VALIDITY CHECKS ////////////////////
///////////////////////////////////////

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {
    
    // for loop to check if there are three consecutive colors in a row
    for (int i = 0; i < size; i++) {
        if ((board[row][i] == color) && (board[row][i + 1] ==
             color) && (board[row][i + 2] == color)) {
            return false;
        }
    }
    
    return true;
}

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
    
    // for loop to check if there are three consecutive colors in a column
    for (int i = 0; i < size; i++) {
        if ((board[i][col] == color) && (board[i + 1][col] ==
            color) && (board[i + 2][col] == color)) {
            return false;
        }
    }
    
    return true;
    
}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    
    // for loop checks rows first and then columns if rows are good
    for (int i = 0; i < size; i++) {
        if ((!row_has_no_threes_of_color(board, size, i, RED)) ||
            (!row_has_no_threes_of_color(board, size, i, BLUE))) {
            return false;
        }
        if ((!col_has_no_threes_of_color(board, size, i, RED)) ||
            (!col_has_no_threes_of_color(board, size, i, BLUE))) {
            return false;
        }
    }
    
    // returns true if all is good with the board
    return true;
}

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {
    
    // if the squares are the same, count will increment
    int count = 0;
    for (int i = 0; i < size; i++) {
        if ((board[row1][i] == UNKNOWN) || (board[row2][i] == UNKNOWN)) {
            return true;
        }
        else if (board[row1][i] == board[row2][i]) {
            count++;
        }
    }
    
    // if all the squares are the same, it will return false
    if (count == size) {
        return false;
    }
    else {
        return true;
    }
    
    return true;
}

bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
    
    // if the squares are the same, count will increment
    int count = 0;
    for (int i = 0; i < size; i++) {
        if ((board[i][col1] == UNKNOWN) || (board[i][col2] == UNKNOWN)) {
            return true;
        }
        else if (board[i][col1] == board[i][col2]) {
            count++;
        }
    }
    
    // if all the squares are the same, it will return false
    if (count == size) {
        return false;
    }
    else {
        return true;
    }
    
    return true;

}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    
    // checks to make sure there are no duplicate rows or columns
    for (int k = 0; k < size; k++) {
        for (int l = k + 1; l < size; l++) {
            if (!rows_are_different(board, size, k, l) ||
                (!cols_are_different(board, size, k, l))) {
                return false;
            }
        }
    }
    
    return true;
}


///////////////////////////////////////
// SOLVING FUNCTIONS //////////////////
///////////////////////////////////////

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    
    // loop goes through every possible scenario for rows
    for (int i = 0; i < size; i++) {
        if (board[row][i] == board[row][i + 2]) {
            if (board[row][i] == RED) {
                mark_square_as(board, size, row, i + 1, BLUE, announce);
                return;
            }
            else if (board[row][i] == BLUE) {
                mark_square_as(board, size, row, i + 1, RED, announce);
                return;
            }
        }
        if (board[row][0] == board[row][1]) {
            if (board[row][0] == RED) {
                mark_square_as(board, size, row, 2, BLUE, announce);
                return;
            }
            else if (board[row][0] == BLUE) {
                mark_square_as(board, size, row, 2, RED, announce);
                return;
            }
        }
        if (board[row][1] == board[row][2]) {
            if (board[row][1] == BLUE) {
                mark_square_as(board, size, row, 0, RED, announce);
                mark_square_as(board, size, row, 3, RED, announce);
                return;
            }
            else if (board[row][1] == RED) {
                mark_square_as(board, size, row, 0, BLUE, announce);
                mark_square_as(board, size, row, 3, BLUE, announce);
                return;
            }
        }
        if (board[row][2] == board[row][3]) {
            if (board[row][2] == BLUE) {
                mark_square_as(board, size, row, 1, RED, announce);
                return;
            }
            else if (board[row][2] == RED) {
                mark_square_as(board, size, row, 1, BLUE, announce);
                return;
            }
        }
    }
    return;
}

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
    
    // loop goes through every possible column scenario
    for (int i = 0; i < size; i++) {
        if (board[i][col] == board[i + 2][col]) {
            if (board[i][col] == RED) {
                mark_square_as(board, size, i + 1, col, BLUE, announce);
                return;
            }
            else if (board[i][col] == BLUE) {
                mark_square_as(board, size, i + 1, col, RED, announce);
                return;
            }
        }
        if (board[0][col] == board[1][col]) {
            if (board[0][col] == RED) {
                mark_square_as(board, size, 2, col, BLUE, announce);
                return;
            }
            else if (board[0][col] == BLUE) {
                mark_square_as(board, size, 2, col, RED, announce);
                return;
            }
        }
        if (board[1][col] == board[2][col]) {
            if (board[1][col] == BLUE) {
                mark_square_as(board, size, 0, col, RED, announce);
                mark_square_as(board, size, 3, col, RED, announce);
                return;
            }
            else if (board[1][col] == RED) {
                mark_square_as(board, size, 0, col, BLUE, announce);
                mark_square_as(board, size, 3, col, BLUE, announce);
                return;
            }
        }
        if (board[2][col] == board[3][col]) {
            if (board[2][col] == RED) {
                mark_square_as(board, size, 1, col, BLUE, announce);
                return;
            }
            else if (board[2][col] == BLUE) {
                mark_square_as(board, size, 1, col, RED, announce);
                return;
            }
        }
    }
    return;
}


void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
    
    // loop goes through and solves the row if there's 2 of one color
    for (int i = 0; i < size; i++) {
        
    }
}

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce) {
    // your code here
}


///////////////////////////////////////
// GAMEPLAY FUNCTIONS /////////////////
///////////////////////////////////////

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    // your code here
    return false;
}

bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {
    // your code here
    return false;
}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    // your code here
    return false;
}


///////////////////////////////////////
// S'MORE FUNCTIONS ///////////////////
///////////////////////////////////////


void solve_lookahead_row(int board[MAX_SIZE][MAX_SIZE],
                         int size,
                         int row,
                         bool announce) {
    // your code here
}

void solve_lookahead_column(int board[MAX_SIZE][MAX_SIZE],
                            int size,
                            int col,
                            bool announce) {
    // your code here
}
