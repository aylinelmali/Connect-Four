#include <stdio.h>

void printBoard(int r, int c, char arr[7][8]){
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			printf("%c ", arr[i][j]);
		}
	printf("\n");
	}
}

int boardFull(char arr[7][8]){
	if(arr[1][1] != '.' && arr[1][2] != '.' && arr[1][3] != '.' && arr[1][4] != '.' && arr[1][5] != '.' && arr[1][6] != '.' && arr[1][7] != '.'){
		return 1;}
	return 0;
}

int convertColToNum(char column){
	int col;
	if(column == 'A'){col = 1;}
	else if(column == 'B'){col = 2;}
	else if(column == 'C'){col = 3;}
	else if(column == 'D'){col = 4;}
	else if(column == 'E'){col = 5;}
	else if(column == 'F'){col = 6;}
	else{col = 7;}
	return col;
}

char convertNumToCol(int number){
	char col;
	if(number == 1){col = 'A';}
	else if(number == 2){col = 'B';}
	else if(number == 3){col = 'C';}
	else if(number == 4){col = 'D';}
	else if(number == 5){col = 'E';}
	else if(number == 6){col = 'F';}
	else{col = 'G';}
	return col;
}

int columnOpen(char arr[7][8], int col){
	if(arr[1][col] != '.'){return 0;}
	return 1;
}

int placeCoin(char arr[7][8], char coin, int col){
	int row = 6;
	int placed = 0;
	while(placed == 0){
		if(arr[row][col] == '.'){
			arr[row][col] = coin; 
			placed = 1;
			}
		else{--row;}
	}
	return row;
}

int checkHoriTwo(char arr[7][8], int row, int col){
	if(row == 6){
		if(col - 1 > 0 && col + 2 < 8){
			if(arr[row][col] == arr[row][col+1] && arr[row][col-1] == '.' && arr[row][col+2] == '.'){
				return 1;
			}
		}
		if(col - 2 > 0 && col + 1 < 8){
			if(arr[row][col] == arr[row][col-1] && arr[row][col-2] == '.' && arr[row][col+1] == '.'){
				return 2;
			}
		}
	}
	return 0;
}

int checkVertThree(char arr[7][8], int row, int col){
	if(row + 2 < 7 && row - 1 > 0){
		if(arr[row][col] == arr[row+1][col] && arr[row+1][col] == arr[row+2][col]){
			return 1;
		}
	}
	return 0;
}

int checkDiagThree(char arr[7][8], int row, int col){
	if(row + 2 < 7 && row - 1 > 0){
		if(col + 2 < 8 && col - 1 > 0){
			if(arr[row][col] == arr[row+1][col+1] && arr[row+1][col+1] == arr[row+2][col+2]){
				if(arr[row][col-1] != '.'){return 1;}
			}
		}
		if(col - 2 > 0 && col + 1 < 7){
			if(arr[row][col] == arr[row+1][col-1] && arr[row+1][col-1] == arr[row+2][col-2]){
				if(arr[row][col+1] != '.'){return 2;}
			}
		}	
	}
	return 0;
}

int checkHoriThree(char arr[7][8], int row, int col){
	if(col + 2 < 8){
		if(arr[row][col] == arr[row][col+1] && arr[row][col+1] == arr[row][col+2]){
			if(col + 3 < 8 && arr[row][col+3] == '.'){
				if(row == 6){return 3;}
				if(arr[row+1][col+3] != '.'){return 3;}
			}
			if(col - 1 > 0 && arr[row][col-1] == '.'){
				if(row == 6){return -1;}
				if(arr[row+1][col-1] != '.'){return -1;}
			}
		}
	}
	if(col - 2 > 0){
		if(arr[row][col] == arr[row][col-1] && arr[row][col-1] == arr[row][col-2]){
			if(col - 3 < 0 && arr[row][col-3] == '.'){
				if(row == 6){return -3;}
				if(arr[row+1][col-3] != '.'){return -3;}
			}
			if(col + 1 < 8 && arr[row][col+1] == '.'){
				if(row == 6){return 1;}
				if(arr[row+1][col+1] != '.'){return 1;}
			}
		}
	}
	if(col + 1 < 8 && col - 1 > 0){
		if(arr[row][col-1] == arr[row][col] && arr[row][col] == arr[row][col+1]){
			if(col - 2 > 0 && arr[row][col-2] == '.'){
				if(row == 6){return -2;}
				if(arr[row+1][col-2] != '.'){return -2;}
			}
			if(col + 2 < 8 && arr[row][col+2] == '.'){
				if(row == 6){return 2;}
				if(arr[row+1][col+2] != '.'){return 2;}
			}
		}
	}
	return 0;
}

int checkVertFour(char arr[7][8], int row, int col){
	if(row + 3 < 7){
		if(arr[row][col] == arr[row+1][col] && arr[row+1][col] == arr[row+2][col] && arr[row+2][col] == arr[row+3][col]){
			return 1;
		}
	}
	return 0;
}

int checkDiagFour(char arr[7][8], int row, int col){
	if(row + 3 < 7){
		if(col + 3 < 8){
			if(arr[row][col] == arr[row+1][col+1] && arr[row+1][col+1] == arr[row+2][col+2] && arr[row+2][col+2] == arr[row+3][col+3]){
				return 1;
			}
		}
		if(col - 3 > 0){
			if(arr[row][col] == arr[row+1][col-1] && arr[row+1][col-1] == arr[row+2][col-2] && arr[row+2][col-2] == arr[row+3][col-3]){
				return 1;
			} 
		}
	}
	if(row + 2 < 7 && row - 1 > 0){
		if(col + 1 < 8 && col - 2 > 0){
			if(arr[row+2][col-2] == arr[row+1][col-1] && arr[row+1][col-1] == arr[row][col] && arr[row][col] == arr[row-1][col+1]){
				return 1;
			}
		}
		if(col + 2 < 8 && col - 1 > 0){
			if(arr[row+2][col+2] == arr[row+1][col+1] && arr[row+1][col+1] == arr[row][col] && arr[row][col] == arr[row-1][col-1]){
				return 1;
			}
		}
	}
	if(row + 1 < 7 && row - 2 > 0){
		if(col - 1 > 0 && col + 2 < 8){
			if(arr[row+1][col-1] == arr[row][col] && arr[row][col] == arr[row-1][col+1] && arr[row-1][col+1] == arr[row-2][col+2]){
				return 1;
			}
		}
		if(col + 1 < 8 && col - 2 > 0){
			if(arr[row+1][col+1] == arr[row][col] && arr[row][col] == arr[row-1][col-1] && arr[row-1][col-1] == arr[row-2][col-2]){
				return 1;
			}
		}
	}
	if(row - 3 > 7){
		if(col + 3 < 8){
			if(arr[row][col] == arr[row-1][col+1] && arr[row-1][col+1] == arr[row-2][col+2] && arr[row-2][col+2] == arr[row-3][col+3]){
				return 1;
			}
		}
		if(col - 3 > 0){
			if(arr[row][col] == arr[row-1][col-1] && arr[row-1][col-1] == arr[row-2][col-2] && arr[row-2][col-2] == arr[row-3][col-3]){
				return 1;
			}
		}
	}
	return 0;
} 

int checkHoriFour(char arr[7][8], int row, int col){
	if(col + 3 < 8){
		if(arr[row][col] == arr[row][col+1] && arr[row][col+1] == arr[row][col+2] && arr[row][col+2] == arr[row][col+3]){
			return 1;
		} 
	}
	if(col - 3 > 0){
		if(arr[row][col] == arr[row][col-1] && arr[row][col-1] == arr[row][col-2] && arr[row][col-2] == arr[row][col-3]){
			return 1;
		}
	}
	if(col + 2 < 8 && col - 1 > 0){
		if(arr[row][col-1] == arr[row][col] && arr[row][col] == arr[row][col+1] && arr[row][col+1] == arr[row][col+2]){
			return 1;
		}
	}
	if(col + 1 < 8 && col - 2 > 0){
		if(arr[row][col-2] == arr[row][col-1] && arr[row][col-1] == arr[row][col] && arr[row][col] == arr[row][col+1]){
			return 1;
		}
	}
	return 0;
}

int compMove(char arr[7][8], int row, int col){
	int move = col;
	if(checkVertThree(arr, row, col) == 1){return col;}
	if(checkDiagThree(arr, row, col) == 2 || checkHoriThree(arr, row, col) == 1 || checkHoriTwo(arr, row, col) == 2){return col+1;}
	if(checkDiagThree(arr, row, col) == 1 || checkHoriThree(arr, row, col) == -1 || checkHoriTwo(arr, row, col) == 1){return col-1;}
	if(checkHoriThree(arr, row, col) == 2){return col+2;}
	if(checkHoriThree(arr, row, col) == -2){return col-2;}
	if(checkHoriThree(arr, row, col) == 3){return col+3;}
	if(checkHoriThree(arr, row, col) == -3){return col-3;}
	if(columnOpen(arr, move) == 0){
		while(columnOpen(arr, move) == 0){
			if(move == 0){move = 7;}
			if(columnOpen(arr, move) == 1){break;}
			move--;
		}
	}
	return move;
}

void main(void){
	char board[7][8] = {{' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G'}, 
			{'6', '.', '.', '.', '.', '.', '.', '.'}, 
			{'5', '.', '.', '.', '.', '.', '.', '.'},
			{'4', '.', '.', '.', '.', '.', '.', '.'},
			{'3', '.', '.', '.', '.', '.', '.', '.'},
			{'2', '.', '.', '.', '.', '.', '.', '.'},
			{'1', '.', '.', '.', '.', '.', '.', '.'}};
	int gameOver = 0;
	int playerFirst;
	int gameStart = 0;
	int compCol;
	int compRow;
	char playerArr[21];
	char compArr[21];
	int pCount = 0;
	int cCount = 0;
	while(gameStart == 0){
		char answer;
		printf("Type P for Player to go first, or C for Computer to go first. \n");
		scanf(" %c", &answer);
		if(answer == 'P'){playerFirst = 1; gameStart = 1;}
		if(answer == 'C'){playerFirst = 0; gameStart = 1;}
		if(answer != 'C' && answer != 'P'){printf("Invalid input. \n");}
	}
	printBoard(7, 8, board);
	if(playerFirst == 0){
		printf("Computer turn \n");
		compCol = 4;
		compRow = placeCoin(board, 'X', 4);
		compArr[cCount] = 'D';
		cCount++;
		printBoard(7, 8, board);
		}
	while(gameOver == 0){
		char column;
		printf("Pick a column, A, B, C, D, E, F, or G, or Q to quit. \n");
		scanf(" %c", &column);
		if(column == 'Q'){break;}
		if(column != 'A' && column != 'B' && column != 'C' && column != 'D' && column != 'E' && column != 'F' && column != 'G' && column != 'Q'){
			printf("Invalid input. \n");
			continue;
		}
		int col = convertColToNum(column);
		if(columnOpen(board, col) == 0){
			printf("That column is full. Please pick another, or type Q to quit. \n");
			continue;
		}
		playerArr[pCount] = column;
		pCount++;
		int row;
		if(playerFirst == 1){row = placeCoin(board, 'X', col);}
		else{row = placeCoin(board, 'O', col);}
		printBoard(7, 8, board);
		if(checkVertFour(board, row, col) == 1 || checkHoriFour(board, row, col) == 1 || checkDiagFour(board, row, col) == 1){
			printf("Four in a row. Player wins! \n");
			printf("Player moves: \n");
			for(int i = 0; i < pCount; i++){
				printf("%c ", playerArr[i]);
			}
			printf("\n");
			gameOver = 1;
			break;
		}
		else if(boardFull(board) == 1){
			printf("Board is full. Tie \n");
			printf("Player moves: \n");
			for(int a = 0; a < pCount; a++){
				printf("%c ", playerArr[a]);
			}
			printf("\n");
			printf("Computer moves: \n");
			for(int b = 0; b < cCount; b++){
				printf("%c ", compArr[b]);
			}
			printf("\n");
			gameOver = 1;
			break;
		}
		printf("Computer turn \n");
		compCol = compMove(board, row, col);
		char compColumn = convertNumToCol(compCol);
		compArr[cCount] = compColumn;
		cCount++;
		if(playerFirst == 1){compRow = placeCoin(board, 'O', compCol);}
		else{compRow = placeCoin(board, 'X', compCol);}
		printBoard(7, 8, board);
		if(checkVertFour(board, compRow, compCol) == 1 || checkHoriFour(board, compRow, compCol) == 1 || checkDiagFour(board, compRow, compCol) == 1){
			printf("Four in a row. Computer wins! \n");
			printf("Computer moves: \n");
			for(int j = 0; j < cCount; j++){
				printf("%c ", compArr[j]);
			}
			printf("\n");
			gameOver = 1;
			break;
		}
		else if(boardFull(board) == 1){
			printf("Board is full. Tie \n");
			printf("Player moves: \n");
			for(int x = 0; x < pCount; x++){
				printf("%c ", playerArr[x]);
			}
			printf("\n");
			printf("Computer moves: \n");
			for(int y = 0; y < cCount; y++){
				printf("%c ", compArr[y]);
			}
			gameOver = 1;
			break;
		}
	}
}
