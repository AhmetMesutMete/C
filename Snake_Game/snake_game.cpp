#include <stdio.h>
#include <stdlib.h>

int main(){
	int row1, row2, row3, column1, column2, column3, counter, size, foodrow, foodcolumn, point;
	char rotation;
	point = 0;
	size = 0;
	printf("Please enter the size of game area(min 5): ");
	scanf("%i", &size);
	
	if(size < 5){
		printf("You have to enter integer values more than 5");
		return 0;
	}
	
	row1 = rand() %(size - 3) + 1;
	row2 = row1;
	row3 = row2;
	
	column3 = rand() %(size - 4) + 1;
	column2 = column3 + 1;
	column1 = column2 + 1;
	
	char array[size][size];
	counter = 1;
	char direction = 'd';
	foodrow = rand() % (size - 2) + 1;
	foodcolumn = rand() %(size - 2) + 1;
	while((row1 == foodrow && column1 == foodcolumn) || (row2 == foodrow && column2 == foodcolumn) || (row3 == foodrow && column3 == foodcolumn)){
		foodrow = rand() % (size - 2) + 1;
		foodcolumn = rand() %(size - 2) + 1;
	}
	while(counter != 0){
		system("cls");
		if(row1 == foodrow && column1 == foodcolumn){
			point += 10;
			while((row1 == foodrow && column1 == foodcolumn) || (row2 == foodrow && column2 == foodcolumn) || (row3 == foodrow && column3 == foodcolumn)){
				foodrow = rand() % (size - 2) + 1;
				foodcolumn = rand() %(size - 2) + 1;
			}
		}
		printf("Point: %i \n", point);
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				if(i != 0 && i != (size-1) && j != 0 && j != (size-1)){
					array[i][j] = ' ';
					array[row1][column1] = 's';
					array[row2][column2] = 'n';
					array[row3][column3] = 'k';
					array[foodrow][foodcolumn] = '*';			
				}
				else{
					array[i][j] = '0';
				}
			}
		}	
		for(int k = 0; k < size; k++){
			for(int l = 0; l < size; l++){
				printf("%c",array[k][l]);
				if(l == (size - 1) ){
					printf("\n");
				}
			}
		}
		printf("Head of the snake is 's'. Please press a for left, d for right, w for up and s for down : \n");
		scanf(" %c", &rotation);
		
		if((!(direction == 'd' && rotation == 'a') && !(direction == 'a' && rotation == 'd') && !(direction == 'w' && rotation == 's') && !(direction == 's' && rotation == 'w')) 
		&& (rotation == 'w' || rotation == 'a' || rotation == 's' || rotation == 'd')){
			row3 = row2;
			column3 = column2;
			row2 = row1;
			column2 = column1;
			switch(rotation){
				case 'w':
					row1--;
					break;
				case 'a':
					column1--;
					break;
				case 'd':
					column1++;
					break;
				case 's':
					row1++;
					break;		
			}
			direction = rotation;
		}
		else if(rotation != 'w' || rotation != 'a' || rotation != 's' || rotation != 'd'){
			printf("You can not enter characters except 's', 'a', 'w' and 'd'\n");
		}
		else{
			printf("snake can not turn back\n");
		}
		
		if(row1 == 0 || row1 == (size - 1) || column1 == 0 || column1 == (size - 1)){
			printf("Game over....\n");
			counter = 0;
		}
	}
	return 0;
}
