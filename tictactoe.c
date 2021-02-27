#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void PlayGame(char ttt[3][3]);
void PrintTable(char ttt[3][3]);
void ResetGame(char ttt[3][3]);
void Help();

int CheckEnd(char ttt[3][3]);





int main(int argc, char *argv[]) {
	char tictactoe[3][3] = {0};
	int menuInput;
	bool gameIsOn = true;
	
	// Loop while game is running
	//
	while(gameIsOn){
		
		
		// Print Menu Options and ask for int input  
		//
		printf("========== Main Menu ==========\n\n1)\tPlay Game\n2)\tExit Game\n\nInput: ");
		scanf("%d", &menuInput);
		
		// Menu Switch
		//
		switch (menuInput){
			case 1:
				PlayGame(tictactoe);
				PrintTable(tictactoe);
				ResetGame(tictactoe);
				break;
			case 2:
				gameIsOn = false;
				//ExitGame();
				break;
			default:
				printf(".\n.\n.\n! Warning ! : Invalid input!\n.\n.\n.\n");
				break;
		}	
	}
	
	return 0;
}

void PlayGame(char ttt[3][3]){
	char p1Name[25];
	char p2Name[25];
	int input;
	
	bool win;
	
	srand(time(NULL));
	
	int turn = rand() % 2;
	
	
	
	printf("%i", turn);
	
	// Intro / Get Names
	//
	printf("\n////////////////////////////////////////////////////\n////////////////////////////////////////////////////\n\n\n\t    Welcome To Tic Tac Toe!\n\n\t\tBy Jack Johnson\n\n\n////////////////////////////////////////////////////\n////////////////////////////////////////////////////\n\n\n");
	printf("Player 1, Please enter your name... \n\n P1 Name:\t");
	scanf("%s", p1Name);
	printf("--\nWelcome %s! You will play with X's.\n\n", &p1Name);
	printf("Player 2, Please enter your name... \n\n P2 Name:\t");
	scanf("%s", p2Name);
	printf("--\nWelcome %s! You will play with O's.\n\n", &p2Name);
	
	while(!win){
		printf("\n\t %c | %c | %c", ttt[0][0], ttt[0][1], ttt[0][2]);
		printf("\n\t------------");
		printf("\n\t %c | %c | %c", ttt[1][0], ttt[1][1], ttt[1][2]);
		printf("\n\t------------");
		printf("\n\t %c | %c | %c", ttt[2][0], ttt[2][1], ttt[2][2]);
		printf("\n\n\n Player %i, it's your turn!\t\t(For help, type '0' -- zero.)\n Input:\t", turn+1);
		scanf("%d", &input);
		if(input == 0){
			Help();
		}
		else{
			switch (turn){
				default:
					printf("Error: Invalid Turn!\n");
					return;
				
				case 0:
					if(input < 4 && ttt[0][input - 1] == 0){
						ttt[0][input - 1] = 'X';
					}
					else if(3 < input < 7 && ttt[1][input - 4] == 0){
						ttt[1][input - 4] = 'X';	
					}
					else if(6 < input < 10 && ttt[2][input - 7] == 0){
						ttt[2][input - 7] = 'X';	
					}
					else{
						printf("\n\n!!!!!\tInvalid input!\n");
						break;
					}
					turn = 1;
					break;
				case 1:
					if(input < 4 && ttt[0][input - 1] == 0){
						ttt[0][input - 1] = 'O';	
					}
					else if(3 < input < 7 && ttt[1][input - 4] == 0){
						ttt[1][input - 4] = 'O';
					}
					else if(6 < input < 10 && ttt[2][input - 7] == 0){
						ttt[2][input - 7] = 'O';
					}
					else{
						printf("Invalid input!\n");
						break;
					}
					turn = 0;
					break;
			}
		}
		
		int winStatus = CheckEnd(ttt);
		
		if(winStatus == 1){
			printf("\n\n........------...............------.......\n\n\t\t%s has won! WOO! YEAH!\n\n........------...............------.......\n\n\n", &p1Name);
			break;
		}
		else if(winStatus == 2){
			printf("\n\n........------.......\n\n\t\t%s has won! WOO! YEAH!\n\n........------.......\n\n\n", &p2Name);
			break;
		}
		
		bool full = true;
		int i;
		int j;
		
		for (i= 0; i<=2; i++){
			for(j = 0; j<=2; j++){
				if(ttt[i][j] != 0){
					continue;
				}
				else{
					full = false;
					break;
				}
				
			}
			if(!full){
				break;
			}
		}
		
		if(!full){
			continue;
		}
		
		printf("\n\n........------...............------...............------...............------.......\n\n\t\tIt's a tie.....\n\t\t\tTry Again!\n\n........------...............------...............------...............------.......\n\n\n");
		return;
		
		
	}
	
	
	return;
}

void Help(){
	printf(".......\n.\n.\nHelp:\n\n  1 | 2 | 3\n------------\n  4 | 5 | 6\n------------\n  7 | 8 | 9\n\n");
	printf("Enter the corresponding number to place an X or an O on that spot.\nFirst to three in a row, wins!\n\n.........\n");
	return;
}

int CheckEnd(char ttt[3][3]){
	if(ttt[0][0] == 'X' && ttt[0][1] == 'X' && ttt[0][2] == 'X'){
		printf("Win!");
		return 1;
	} 	
	else if(ttt[1][0] == 'X' && ttt[1][1] == 'X' && ttt[1][2] == 'X'){
		printf("win!");
		return 1;
	}
	else if(ttt[2][0] == 'X' && ttt[2][1] == 'X' && ttt[2][2] == 'X'){
		printf("Win");
		return 1;
	}
	else if(ttt[0][0] == 'X' && ttt[1][0] == 'X' && ttt[2][0] == 'X'){
		printf("winm!");
		return 1;
	
	}
	else if(ttt[0][1] == 'X' && ttt[1][1] == 'X' && ttt[2][1] == 'X'){
		printf("foj");
		return 1;
	}
	else if(ttt[0][2] == 'X' && ttt[1][2] == 'X' && ttt[2][2] == 'X'){
		printf("win;");
		return 1;
	}
	else if(ttt[0][2] == 'X' && ttt[1][1] == 'X' && ttt[2][0] == 'X'){
		printf("ye");
		return 1;
	}
	else if(ttt[0][0] == 'X' && ttt[1][1] == 'X' && ttt[2][2] == 'X'){
		printf("uye");
		return 1;
	}
	
	else if(ttt[0][0] == 'O' && ttt[0][1] == 'O' && ttt[0][2] == 'O'){
		printf("Win!");
		return 2;
	} 	
	else if(ttt[1][0] == 'O' && ttt[1][1] == 'O' && ttt[1][2] == 'O'){
		printf("win!");
		return 2;
	}
	else if(ttt[2][0] == 'O' && ttt[2][1] == 'O' && ttt[2][2] == 'O'){
		printf("Win");
		return 2;
	}
	else if(ttt[0][0] == 'O' && ttt[1][0] == 'O' && ttt[2][0] == 'O'){
		printf("winm!");
		return 2;
	}
	else if(ttt[0][1] == 'O' && ttt[1][1] == 'O' && ttt[2][1] == 'O'){
		printf("foj");
		return 2;
	}
	else if(ttt[0][2] == 'O' && ttt[1][2] == 'O' && ttt[2][2] == 'O'){
		printf("win;");
		return 2;
	}
	else if(ttt[0][2] == 'O' && ttt[1][1] == 'O' && ttt[2][0] == 'O'){
		printf("ye");
		return 2;
	}
	else if(ttt[0][0] == 'O' && ttt[1][1] == 'O' && ttt[2][2] == 'O'){
		printf("uye");
		return 2;
	}
	else{
		return 0;
	}
	
}


void PrintTable(char ttt[3][3]){
	printf("\n\t %c | %c | %c", ttt[0][0], ttt[0][1], ttt[0][2]);
	printf("\n\t------------");
	printf("\n\t %c | %c | %c", ttt[1][0], ttt[1][1], ttt[1][2]);
	printf("\n\t------------");
	printf("\n\t %c | %c | %c\n\n", ttt[2][0], ttt[2][1], ttt[2][2]);
	
	return;
}

void ResetGame(char ttt[3][3]){
	int i;
	int j;
	
	for(i = 0; i<=2; i++ ){
		for(j = 0; j <= 2; j++){
			ttt[i][j] = 0;
		}
	}
	
	return;
}



