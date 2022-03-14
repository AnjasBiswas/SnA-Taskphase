#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

char board[3][3];
const char PLAYER='O';//default player symbol
const char PLAYER2='X';//default player symbol
const char COMPUTER = 'X';//default computer symbol
char win=' ';//to store the winner of game


void resetBoard();
void printBoard();
int checkFree();
void playerMove(char);
void computerMove();
char checkWinner();

int main(){

    int mode;
    
    resetBoard();//resetting the board for a new game

    printf("Enter 1 for Player vs Player OR Enter 2 for Player vs Computer\n");
    scanf("%d",&mode);//user input for the mode of game
    
    while (win==' '&& checkFree() != 0){
        
        playerMove(PLAYER);
        win=checkWinner();
        if(win!=' ' || checkFree()==0)
            break;//exit if winner is found
        printBoard();
    
        if(mode==1){//checkng the mode
            playerMove(PLAYER2);
            win=checkWinner();
            if(win!=' ' || checkFree()==0)
                break;
        }else{
            computerMove();
            win=checkWinner();
            if(win!=' ' || checkFree()==0)
                break;
        }

        printBoard();//printing the board
    }

    printBoard();

    if(win==PLAYER)
        printf("Congratulation you have won ");
    else if(win==PLAYER2 && mode==1)
        printf("Player 2 have won");
    else if (win==COMPUTER && mode==2)
        printf("Sorry Computer has won ");
    else
        printf("Its is tie");
    //printing the results
    
    return 0;
}

void resetBoard(){

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j]=' ';//clearing the board
        }
    }
}
void printBoard(){
    //print the board in an output terminal
    printf(" %c | %c | %c ",board[0][0],board[0][1],board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",board[2][0],board[2][1],board[2][2]);
    printf("\n");
}
int checkFree(){

    int space=9;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(board[i][j]!=' ')//chechkin for free spaces
                space--;
        }
    }
    return space;//returning the no of spaces left
}
void playerMove(char sym){

    int x,y;
    do
    {
        printf("Enter the row::");
        scanf("%d",&x);//taking row as input
        x--;
        printf("Enter the Column::");
        scanf("%d",&y);//taking column as input
        y--;
        
        if(board[x][y]!=' ')//checking for free spot
            printf("Space is already filled ");
        else{
            board[x][y]=sym;
            break;
        }

    } while (board[x][y] !=' ');//running the input process until a vadil move is obtained
    
}
void computerMove(){

    srand(time(0));//randomiser with respect to time as input
    int x,y;

    if(checkFree()>0){

        do{
            x=rand()%3;//generating random no within 1 to 3
            y=rand()%3;
        }while(board[x][y]!=' ');
        board[x][y]=COMPUTER;

    }else win=' ';
}
char checkWinner(){

    for(int i=0;i<3;i++){//checking for similar in row
        if(board[i][0]==board[i][1]&&board[i][0]==board[i][2])
            return board[i][0];
    }

    for(int j=0;j<3;j++){//checking for similar in column
        if(board[0][j]==board[1][j]&&board[0][j]==board[2][j])
            return board[0][j];
    }
    if(board[0][0]==board[1][1]&&board[0][0]==board[2][2])
            return board[0][0];//chechking for right diagonal

    if(board[0][2]==board[1][1]&&board[0][2]==board[2][0])
            return board[0][2];//checking for left diagonal

    return ' ';//return blank is no match

}