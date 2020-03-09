/*Name: Matthew Quigley
Email: quigleym@purdue.edu
Lab Time: Friday 7:30am

Project Title: Lab #2 - the Maze
Description: The program will solve a 6x6 maze. It will print out the original maze, and then print out a version of the maze with the correct path marked by "+" symbol. Dead ends will be marked with "x" symbol. Finally the program 
also prints out every attempt made in order of directions along with every retry. */

#include <stdio.h>
#include <stdlib.h>
//The maze variable which will change and update.
char maze[6][6] = {
						{'S','#','#','#','#','#'},
						{'.','.','.','.','.','#'},
						{'#','.','#','#','#','#'},
						{'#','.','#','#','#','#'},
						{'.','.','.','#','.','G'},
						{'#','#','.','.','.','#'},
					}; 
//The original maze that only updates dead ends. 
char oMaze[6][6] = {
						{'S','#','#','#','#','#'},
						{'.','.','.','.','.','#'},
						{'#','.','#','#','#','#'},
						{'#','.','#','#','#','#'},
						{'.','.','.','#','.','G'},
						{'#','#','.','.','.','#'},
					};
//Starting Points
int x = 0; 
int y = 0;
//Create Pointers for Starting points
int *xa = &x;
int *ya = &y;
//print out current maze version
void printMaze(){
	for (int i = 0; i <= 5; i++)
	{
		for(int j = 0; j <= 5; j++)
		{
				printf("%c ", *(&maze[i][j]));
				
		}
		printf("\n");
	}
}

//Reset function resets maze removing + while keeping dead ends (X)
void reset (){
    
    char temp[6][6];
    
    for (int w = 0; w <= 5; w++)
	{
		for(int z = 0; z <= 5; z++)
		{
				temp[w][z] = *(&oMaze[w][z]);
		}
	}

	for (int i = 0; i <= 5; i++)
	{
		for(int j = 0; j <= 5; j++)
		{
				*(&maze[j][i]) = temp[j][i];
				//printf("\n %d", *(&maze[j][i]));
		}
	}
	
	*(&maze[*ya][*xa]) = 'x'; //Change value of dead ends 
	*(&oMaze[*ya][*xa]) = 'x';
}
//Runs through the maze unitl it finds a succesful path					
void mazeGo ( int x, int y){
//Stores the characters at the current position and the character at each respective direction 	
	char *current = &maze[y][x];
	char *North = &maze[y-1][x];
	char *East = &maze[y][x+1];
	char *South = &maze[y+1][x];
	char *West = &maze[y][x-1];
//If else statement that runs through directions	
		if (*current == 'G'){ //If current spot = 'G' exit program
	            printf("\n");
		    printMaze();
		    printf("\n Success \n");
		    exit(0);
		}
		else if (*North == '.'||*North == 'G'){
			*current = '+'; //marks current path with +
			*ya = *ya - 1; //moves symbol
			printf("\n North");
			mazeGo(*xa,*ya); //north
		}
		else if (*East == '.'||*East =='G'){
		    *current = '+';
		    *xa = *xa + 1;
		    printf("\n East");
			mazeGo(*xa,*ya); //East
		}
		else if (*South == '.'||*South =='G'){
		    *current = '+';
		    *ya = *ya + 1;
		    printf("\n South");
			mazeGo(*xa,*ya); //south
		}
		else if (*West == '.'||*West =='G'){
		    *current = '+';
		    *xa = *xa - 1;
		    printf("\n West");
			mazeGo(*xa,*ya); //West
		}
		else{
		    printf("\n retry");
		    reset();
		    *xa = 0;
	        *ya = 0;
		    mazeGo(*xa,*ya);
		}
}

int main() //main function runs through operation
{
	printf("\n");
	printMaze();
	mazeGo (*xa,*ya);
	return 0; 
}
