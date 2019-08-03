#include <iostream>	
#include <random>
#include <ctime>
using namespace std;

int main() {
	const int height = 8, width = 16;
	int playerX = 1, playerY = 1;
	int enemyX = 12, enemyY = 4;
	int trophyX = 14, trophyY = 6;
	int playerHealth = 100;
	char input;
	int enemyHealth = 34;
	bool gameIsDone = false;
	char board[height][width] = {
			{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
			{'#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
			{'#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
			{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
			{'#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
			{'#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
			{'#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
			{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
	};
	
	

	while (playerHealth >= 0 && gameIsDone != true) {
		board[playerY][playerX] = '@';
		board[trophyY][trophyX] = 'T';
		if (enemyHealth > 0) {
			board[enemyY][enemyX] = 'G';
		}
		srand(time(0));
		int randNum = rand() % 6 + 1;
		


		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cout << board[i][j];
			}
			cout << endl;
		}
		cout << "Your health is " << playerHealth << "\n";
		cout << "Enemy health is " << enemyHealth << "\n";
		cin >> input;
		system("cls");
		//Player move
		switch (input) {


		case 's': 
			if (board[playerY + 1][playerX] != '#') {
				board[playerY][playerX] = ' ';
				playerY++;
			}
			break;
		case 'w': 
			if (board[playerY - 1][playerX] != '#') {
				board[playerY][playerX] = ' ';
				playerY--;
			}
			break;
		case 'd':
			if (board[playerY][playerX + 1] != '#') {
				board[playerY][playerX] = ' ';
				playerX++;
			}
			break;
		case 'a': 
			if (board[playerY][playerX - 1] != '#') {
				board[playerY][playerX] = ' ';
				playerX--;
			}
			break;
			
		}
			if (enemyHealth > 0) {
				if (board[enemyY][enemyX] == board[playerY][playerX]) {
					cout << "\nYou're in combat!\n You lost 4 health\n";
					cout << "\nEnemy lost 10 health\n";
					playerHealth = playerHealth - 4;
					enemyHealth = enemyHealth - 10;
					board[enemyY][enemyX] = 'X';
				}
			}
			//Enemy move
			 switch (randNum)
			 {
			 case 1:
				 if (board[enemyY][enemyX + 1] != '#') {
					 board[enemyY][enemyX] = ' ';
					 enemyX++;
				 }
				 break;
			 case 2:
				 if (board[enemyY][enemyX - 1] != '#') {
					 board[enemyY][enemyX] = ' ';
					 enemyX--;
				 }
				 break;
			 case 3:
				 if (board[enemyY + 1][enemyX] != '#') {
					 board[enemyY][enemyX] = ' ';
					 enemyY++;
				 }
				 break;
			 case 4:
				 if (board[enemyY - 1][enemyX] != '#') {
					 board[enemyY][enemyX] = ' ';
					 enemyY--;
				 }
				 break;
			 default:
				 break;
			 }
				
		if (board[trophyY][trophyX] == board[playerY][playerX]) {
			gameIsDone = true;
			
		}
		
		
		
	}
	 
	if (playerHealth <= 0) { 
		cout << "\nYou lose\n"; 
	}
	else if(enemyHealth <= 0) {
		cout << "\nYou Win\n";
	}
	else if (enemyHealth >= 0 && gameIsDone == true) {
		cout << "\nDid you win, really...?\n";
	}
	
}
