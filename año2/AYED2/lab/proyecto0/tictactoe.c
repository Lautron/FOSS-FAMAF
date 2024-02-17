#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define BOARD_SIZE 3
#define CELL_MAX (BOARD_SIZE * BOARD_SIZE - 1)

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
  int cell = 0;
  printf("\t .................................................\n");
  for (int row = 0; row < BOARD_SIZE; ++row) {
    for (int column = 0; column < BOARD_SIZE; ++column) {
      printf("\t | %d: %c ", cell, board[row][column]);
      ++cell;
    }
    printf("\t | \n");
    printf("\t .................................................\n");
  }
}

typedef struct coords{
  int c1[2];
  int c2[2];
  int c3[2];
} coords;

bool are_equal(coords pos, char board[BOARD_SIZE][BOARD_SIZE]) {
  return (
      (board[pos.c1[0]][pos.c1[1]] == board[pos.c2[0]][pos.c2[1]])
      &&
      (board[pos.c2[0]][pos.c2[1]] == board[pos.c3[0]][pos.c3[1]])
      &&
      (board[pos.c1[0]][pos.c1[1]] != '-')
      );
}

char check_row(char board[BOARD_SIZE][BOARD_SIZE], int rowNum) {
  return are_equal((coords){{rowNum, 0}, {rowNum, 1}, {rowNum, 2}}, board);
}

char check_col(char board[BOARD_SIZE][BOARD_SIZE], int colNum) {
  return are_equal((coords){{0, colNum}, {1, colNum}, {2, colNum}}, board);
}

char check_diag1(char board[BOARD_SIZE][BOARD_SIZE]) {
  return are_equal((coords){{0, 0}, {1, 1}, {2, 2}}, board);
}

char check_diag2(char board[BOARD_SIZE][BOARD_SIZE]) {
  return are_equal((coords){{2, 0}, {1, 1}, {0, 2}}, board);
}

char get_winner(char board[BOARD_SIZE][BOARD_SIZE])
{
  board = board;
  char winner = '-';

  for (int i = 0; i < BOARD_SIZE; ++i) {
    if (check_row(board, i)){
      winner = board[i][0];
    }

    else if (check_col(board, i)){
      winner = board[0][i];
    }
  }

  if (check_diag1(board)){
    winner = board[0][0];
  }

  else if (check_diag2(board)){
    winner = board[2][0];
  }

  return winner;
}

bool has_free_cell(char board[BOARD_SIZE][BOARD_SIZE])
{
  board = board;

  // IMPLEMENTAR
  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      if (board[i][j] == '-') {
	return true;
      }
    }
  }
  return false;
}

int main(void)
{
  printf("TicTacToe [InCoMpLeTo :'(]\n");

  char board[BOARD_SIZE][BOARD_SIZE] = {
    { '-', '-', '-' },
    { '-', '-', '-' },
    { '-', '-', '-' }
  };

  char turn = 'X';
  char winner = '-';
  int cell = 0;
  while (winner == '-' && has_free_cell(board)) {
    print_board(board);
    printf("\nTurno %c - Elija posición (número del 0 al 8): ",
	turn);
    int scanf_result = scanf("%d", &cell);
    if (scanf_result <= 0) {
      printf("Error al leer un número desde teclado\n");
      exit(EXIT_FAILURE);
    }
    if (cell >= 0 && cell <= CELL_MAX) {
      int row = cell / BOARD_SIZE;
      int colum = cell % BOARD_SIZE;
      if (board[row][colum] == '-') {
	board[row][colum] = turn;
	turn = turn == 'X' ? 'O' : 'X';
	winner = get_winner(board);
      } else {
	printf("\nCelda ocupada!\n");
      }
    } else {
      printf("\nCelda inválida!\n");
    }
  }
  print_board(board);
  if (winner == '-') {
    printf("Empate!\n");
  } else {
    printf("Ganó %c\n", winner);
  }
  return 0;
}
