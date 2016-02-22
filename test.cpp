/**
 * test.cpp
 *
 * EECS 183, Winter 2015
 * Project 3: 0h h1 Test Suite
 *
 * Kyle Kramer & Julian Frankel
 * krkyle      & frankelj
 *
 * Tests all of the functions implemented in ohhi.cpp
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_has_no_threes_of_color();
void test_col_has_no_threes_of_color();
void test_board_has_no_threes();
void test_rows_are_different();
void test_cols_are_different();
void test_board_has_no_duplicates();
void test_solve_three_in_a_row();
void test_solve_three_in_a_column();

// declare more test functions here

int main() {
    test_count_unknown_squares();

    test_row_has_no_threes_of_color();
    
    test_col_has_no_threes_of_color();
    
    test_board_has_no_threes();
    
    test_rows_are_different();
    
    test_cols_are_different();
    
    test_board_has_no_duplicates();
    
    test_solve_three_in_a_row();
    
    test_solve_three_in_a_column();

    return 0;
}


void test_count_unknown_squares() {
    cout << "Begin testing count unknown squares" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"O-OX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << count_unknown_squares(board, size_1) << endl;

    // test case 2
    string test_board_2[] = {"----",
                             "OOO-",
                             "-XX-",
                             "--O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << count_unknown_squares(board, size_2) << endl;
    
    // test case 3
    string test_board_3[] = {"X-XX",
                             "OO-O",
                             "-X-X",
                             "O-O-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << count_unknown_squares(board, size_3) << endl;
    
    cout << "End testing count unknown squares" << endl;
}

void test_row_has_no_threes_of_color () {
    cout << "Begin testing row has no threes" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_1[] = {"O-OX",
                             "OOO-",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << row_has_no_threes_of_color(board, size_1, 1, BLUE) << endl;
    
    // test case 2
    string test_board_2[] = {"----",
                             "XXX-",
                             "-XX-",
                             "--O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << row_has_no_threes_of_color(board, size_2, 1, RED) << endl;
    
    // test case 3
    string test_board_3[] = {"----",
                             "XXX-",
                             "-XX-",
                             "--O-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << row_has_no_threes_of_color(board, size_3, 2, RED) << endl;
    
    // test case 4
    string test_board_4[] = {"----",
                             "XXX-",
                             "-XX-",
                             "--O-"};
    int size_4 = 3;
    read_board_from_string(board, test_board_4, size_4);
    cout << row_has_no_threes_of_color(board, size_4, 1, BLUE) << endl;
    
    cout << "End testing row has no threes" << endl;
}

void test_col_has_no_threes_of_color () {
    cout << "Testing col has no threes" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_1[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << col_has_no_threes_of_color(board, size_1, 1, RED) << endl;
    
    // test case 2
    string test_board_2[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << col_has_no_threes_of_color(board, size_2, 2, RED) << endl;
    
    // test case 3
    string test_board_3[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--O-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << col_has_no_threes_of_color(board, size_3, 2, BLUE) << endl;
    
    // test case 4
    string test_board_4[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--O-"};
    int size_4 = 3;
    read_board_from_string(board, test_board_4, size_4);
    cout << col_has_no_threes_of_color(board, size_4, 0, RED) << endl;
    
    cout << "End testing col has no threes" << endl;
}

void test_board_has_no_threes() {
    cout << "Begin testing board has no threes" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_1[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--X-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_has_no_threes(board, size_1) << endl;
    
    // test case 2
    string test_board_2[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_has_no_threes(board, size_2) << endl;
    
    // test case 3
    string test_board_3[] = {"--X-",
                             "XXX-",
                             "-XO-",
                             "--O-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << board_has_no_threes(board, size_3) << endl;
    
    // test case 4
    string test_board_4[] = {"--X-",
                             "-XX-",
                             "-XO-",
                             "OOO-"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << board_has_no_threes(board, size_4) << endl;
    
    // test case 5
    string test_board_5[] = {"-O-X",
                             "-XX-",
                             "-X-O",
                             "XOO-"};
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << board_has_no_threes(board, size_5) << endl;
    
    // test case 6
    string test_board_6[] = {"-O-X",
                             "-XX-",
                             "-X-O",
                             "X--X"};
    int size_6 = 4;
    read_board_from_string(board, test_board_6, size_6);
    cout << board_has_no_threes(board, size_6) << endl;
    
    cout << "End testing board has no threes" << endl;
}

void test_rows_are_different () {
    cout << "Begin testing rows are different" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_1[] = {"XOOX",
                             "XOOX",
                             "----",
                             "----"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << rows_are_different(board, size_1, 0, 1) << endl;
    
    // test case 2
    string test_board_2[] = {"XOOX",
                             "XXOO",
                             "----",
                             "----"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << rows_are_different(board, size_2, 0, 1) << endl;
    
    // test case 3
    string test_board_3[] = {"XO-X",
                             "XOOX",
                             "----",
                             "----"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << rows_are_different(board, size_3, 0, 1) << endl;
    
    // test case 4
    string test_board_4[] = {"XO-X",
                             "XOOX",
                             "----",
                             "----"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << rows_are_different(board, size_4, 2, 3) << endl;
    
    // test case 5
    string test_board_5[] = {"XO-X",
                             "XO-X",
                             "----",
                             "----"};
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << rows_are_different(board, size_5, 0, 1) << endl;
    
    cout << "End testing rows are different" << endl;
}

void test_cols_are_different() {
    cout << "Begin testing cols are different" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_1[] = {"XX--",
                             "OO--",
                             "OO--",
                             "XX--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << cols_are_different(board, size_1, 0, 1) << endl;
    
    // test case 2
    string test_board_2[] = {"XX--",
                             "OX--",
                             "OO--",
                             "XX--"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << cols_are_different(board, size_2, 0, 1) << endl;
    
    // test case 3
    string test_board_3[] = {"XX--",
                             "OO--",
                             "-O--",
                             "XX--"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << cols_are_different(board, size_3, 0, 1) << endl;
    
    // test case 4
    string test_board_4[] = {"XX--",
                             "OO--",
                             "-O--",
                             "XX--"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << cols_are_different(board, size_4, 2, 3) << endl;
    
    // test case 5
    string test_board_5[] = {"XX--",
                             "OO--",
                             "----",
                             "XX--"};
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << cols_are_different(board, size_5, 0, 1) << endl;
    
    cout << "End testing cols are different" << endl;
}

void test_board_has_no_duplicates() {
    cout << "Begin testing board has no duplicates" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_1[] = {"OO--",
                             "XXOO",
                             "XXO-",
                             "O-X-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_has_no_duplicates(board, size_1) << endl;
    
    // test case 2
    string test_board_2[] = {"OO--",
                             "XXOO",
                             "XXOO",
                             "O-O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_has_no_duplicates(board, size_2) << endl;
    
    cout << "End testing board has no duplicates" << endl;
}

void test_solve_three_in_a_row() {
    cout << "Begin testing solve three in a row" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_1[] = {"----",
                             "XX--",
                             "-XX-",
                             "--X-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    solve_three_in_a_row(board, size_1, 1, true);
    
    // test case 2
    string test_board_2[] = {"----",
                             "XX--",
                             "-XX-",
                             "--X-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    solve_three_in_a_row(board, size_2, 2, true);
    
    // test case 3
    string test_board_3[] = {"----",
                             "X-X-",
                             "----",
                             "--X-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    solve_three_in_a_row(board, size_3, 1, true);
    
    // test case 4
    string test_board_4[] = {"----",
                             "--XX",
                             "----",
                             "--X-"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    solve_three_in_a_row(board, size_4, 1, true);
    
    cout << "End testing solve three in a row" << endl;

}

void test_solve_three_in_a_column () {
    cout << "Begin testing solve three in a column" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_1[] = {"----",
                             "XX--",
                             "-XX-",
                             "--X-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    solve_three_in_a_column(board, size_1, 1, true);
    
    // test case 2
    string test_board_2[] = {"----",
                             "X-X-",
                             "----",
                             "--X-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    solve_three_in_a_column(board, size_2, 2, true);
    
    // test case 3
    string test_board_3[] = {"--X-",
                             "X-X-",
                             "----",
                             "----"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    solve_three_in_a_column(board, size_3, 2, true);
    
    // test case 4
    string test_board_4[] = {"----",
                             "X---",
                             "--X-",
                             "--X-"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    solve_three_in_a_column(board, size_4, 2, true);
    
    cout << "End testing solve three in a column" << endl;
}