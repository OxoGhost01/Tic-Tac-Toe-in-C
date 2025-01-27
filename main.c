# include <stdio.h>
# include <stdlib.h>

void main();
void printGrid(char grid[]);
int place(char grid[], int x, char player);
void changePlayer(char *p);
int check(char grid[]);

void main()
{
    char player = 'X';
    char grid[9] = "         ";
    int checkWin = 0;
    int choice = 0;
    char *p = &player;
    printf("Welcome to the Tic Tac Toe game !\n\n");
    while (!checkWin){
        choice = 0;
        printGrid(grid);
        do{
            printf("Player %c, enter your move (1-9): ", player);
            scanf("%d", &choice);
            printf("\n");
            choice--;
        }while (place(grid, choice, player));
        changePlayer(p);
        checkWin = check(grid);
    }
}

void printGrid(char grid[]){
    printf("\n %c | %c | %c", grid[0], grid[1], grid[2]);
    printf("\n---|---|---");
    printf("\n %c | %c | %c", grid[3], grid[4], grid[5]);
    printf("\n---|---|---");
    printf("\n %c | %c | %c\n\n", grid[6], grid[7], grid[8]);
}

int place(char grid[], int x, char player){
    if(x < 0 || x > 8){
        printf("Invalid move! Try again.\n");
        return 1;
    }
    else if(grid[x] == ' '){
        grid[x] = player;
        return 0;
    }
    else{
        printf("Invalid move! Try again.\n");
        return 1;
    }
    
}

void changePlayer(char *p){
    if(*p == 'X'){
        *p = 'O';
    }
    else{
        *p = 'X';
    }
}

int check(char grid[]){
    for(int i = 0; i < 3 ; i++){
        if(grid[i*3] == grid[i*3+1] && grid[i*3+1] == grid[i*3+2] && grid[i*3] != ' '){
            if(grid[i*3] == 'X'){
                printf("Player X wins!\n");
            }
            else{
                printf("Player O wins!\n");
            }
            return 1;
        }
        if(grid[i] == grid[i+3] && grid[i+3] == grid[i+6] && grid[i]!= ' '){
            if(grid[i] == 'X'){
                printf("Player X wins!\n");
            }
            else{
                printf("Player O wins!\n");
            }
            return 1;
        }
    }
    if(grid[0] == grid[4] && grid[4] == grid[8] && grid[0]!=' '){
        if(grid[0] == 'X'){
                printf("Player X wins!\n");
            }
            else{
                printf("Player O wins!\n");
            }
        return 1;
    }
    if(grid[2] == grid[4] && grid[4] == grid[6] && grid[2]!=' '){
        if(grid[2] == 'X'){
                printf("Player X wins!\n");
            }
            else{
                printf("Player O wins!\n");
            }
        return 1;
    }
    return 0;
}
