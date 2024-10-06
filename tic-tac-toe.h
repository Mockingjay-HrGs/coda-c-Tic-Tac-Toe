#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#define SIZE 9

void initialize_board(char board[]);
void print_board(char board[]);
int check_winner(char board[]);
void player_move(char board[]);
void computer_move(char board[]);
int is_board_full(char board[]);
void clear_terminal();

#endif
