#include <stdio.h>
#include <stdlib.h>
#include "tic-tac-toe.h"  

void initialize_board(char board[]) {
    for (int i = 0; i < SIZE; i++) {
        board[i] = ' ';
    }
}

void print_board(char board[]) {
    clear_terminal();
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}

int check_winner(char board[]) {
    int winning_combinations[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, 
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  
        {0, 4, 8}, {2, 4, 6}              
    };

    for (int i = 0; i < 8; i++) {
        if (board[winning_combinations[i][0]] != ' ' &&
            board[winning_combinations[i][0]] == board[winning_combinations[i][1]] &&
            board[winning_combinations[i][1]] == board[winning_combinations[i][2]]) {
            return 1;
        }
    }

    return 0;
}

void player_move(char board[]) {
    int position;
    printf("Entrez la position (0-8) : ");
    scanf("%d", &position);

    while (position < 0 || position >= SIZE || board[position] != ' ') {
        printf("Position invalide. Réessayez: ");
        scanf("%d", &position);
    }

    board[position] = 'X';
}

void computer_move(char board[]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i] == ' ') {
            board[i] = 'O';
            break;
        }
    }
}

int is_board_full(char board[]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i] == ' ') {
            return 0;
        }
    }
    return 1; 
}

void clear_terminal() {
    system("clear");
}

int main() {
    char board[SIZE];
    int winner = 0, full_board = 0;

    initialize_board(board);

    while (!winner && !full_board) {
        print_board(board);
        player_move(board);
        winner = check_winner(board);

        if (!winner) {
            full_board = is_board_full(board);
            if (!full_board) {
                computer_move(board);
                winner = check_winner(board);
                full_board = is_board_full(board);
            }
        }
    }

    print_board(board);

    if (winner) {
        printf("Tu à gagné contre un robot !\n");
    } else {
        printf("Match nul !\n");
    }

    return 0;
}

