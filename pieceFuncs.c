#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZEM 10
#define SIZEN 20
#define DEFAULTGAMESPEED 30

struct piecetype{
    int layout[2][4];
    float r, g, b;
}PieceType;

struct piece{
    struct piecetype type;
    int x;
    int y;
}Piece;

struct boardPlace{
    int active;
    float r;
    float g;
    float b;
};

struct piecetype * pTypes = NULL;
struct piece *activePiece = NULL;
struct boardPlace board[SIZEN][SIZEM];
int timeCount = 0;
int gameSpeed = DEFAULTGAMESPEED;//frames to move
int gameOver = 0;
int score = 0;
int nextPiece = 0;

struct piecetype * createPieceTypes(){
    //create all the piece types
    srand(time(NULL));
    struct piecetype *pieceTypes;
    pieceTypes = malloc(sizeof(struct piecetype) * 7);

    //piecetype 1: I
    pieceTypes[0].layout[0][0] = 1;
    pieceTypes[0].layout[0][1] = 1;
    pieceTypes[0].layout[0][2] = 1;
    pieceTypes[0].layout[0][3] = 1;
    pieceTypes[0].layout[1][0] = 0;
    pieceTypes[0].layout[1][1] = 0;
    pieceTypes[0].layout[1][2] = 0;
    pieceTypes[0].layout[1][3] = 0;
    pieceTypes[0].r = 0.0f;
    pieceTypes[0].g = 1.0f;
    pieceTypes[0].b = 0.0f;

    //piecetype2: T
    pieceTypes[1].layout[0][0] = 0;
    pieceTypes[1].layout[0][1] = 1;
    pieceTypes[1].layout[0][2] = 0;
    pieceTypes[1].layout[0][3] = 0;
    pieceTypes[1].layout[1][0] = 1;
    pieceTypes[1].layout[1][1] = 1;
    pieceTypes[1].layout[1][2] = 1;
    pieceTypes[1].layout[1][3] = 0;
    pieceTypes[1].r = 1.0f;
    pieceTypes[1].g = 1.0f;
    pieceTypes[1].b = 0.0f;

    //piecetype3: quadrado
    pieceTypes[2].layout[0][0] = 0;
    pieceTypes[2].layout[0][1] = 1;
    pieceTypes[2].layout[0][2] = 1;
    pieceTypes[2].layout[0][3] = 0;
    pieceTypes[2].layout[1][0] = 0;
    pieceTypes[2].layout[1][1] = 1;
    pieceTypes[2].layout[1][2] = 1;
    pieceTypes[2].layout[1][3] = 0;
    pieceTypes[2].r = 0.0f;
    pieceTypes[2].g = 1.0f;
    pieceTypes[2].b = 1.0f;

    //piecetype4: L
    pieceTypes[3].layout[0][0] = 0;
    pieceTypes[3].layout[0][1] = 0;
    pieceTypes[3].layout[0][2] = 1;
    pieceTypes[3].layout[0][3] = 0;
    pieceTypes[3].layout[1][0] = 1;
    pieceTypes[3].layout[1][1] = 1;
    pieceTypes[3].layout[1][2] = 1;
    pieceTypes[3].layout[1][3] = 0;
    pieceTypes[3].r = 1.0f;
    pieceTypes[3].g = 0.0f;
    pieceTypes[3].b = 0.0f;

    //piecetype5: L invertido
    pieceTypes[4].layout[0][0] = 1;
    pieceTypes[4].layout[0][1] = 1;
    pieceTypes[4].layout[0][2] = 1;
    pieceTypes[4].layout[0][3] = 0;
    pieceTypes[4].layout[1][0] = 0;
    pieceTypes[4].layout[1][1] = 0;
    pieceTypes[4].layout[1][2] = 1;
    pieceTypes[4].layout[1][3] = 0;
    pieceTypes[4].r = 0.0f;
    pieceTypes[4].g = 0.0f;
    pieceTypes[4].b = 1.0f;

    //piecetype6: N
    pieceTypes[5].layout[0][0] = 1;
    pieceTypes[5].layout[0][1] = 1;
    pieceTypes[5].layout[0][2] = 0;
    pieceTypes[5].layout[0][3] = 0;
    pieceTypes[5].layout[1][0] = 0;
    pieceTypes[5].layout[1][1] = 1;
    pieceTypes[5].layout[1][2] = 1;
    pieceTypes[5].layout[1][3] = 0;
    pieceTypes[5].r = 1.0f;
    pieceTypes[5].g = 0.0f;
    pieceTypes[5].b = 1.0f;

    //piecetype6: N invertido
    pieceTypes[6].layout[0][0] = 0;
    pieceTypes[6].layout[0][1] = 1;
    pieceTypes[6].layout[0][2] = 1;
    pieceTypes[6].layout[0][3] = 0;
    pieceTypes[6].layout[1][0] = 1;
    pieceTypes[6].layout[1][1] = 1;
    pieceTypes[6].layout[1][2] = 0;
    pieceTypes[6].layout[1][3] = 0;
    pieceTypes[6].r = 0.5f;
    pieceTypes[6].g = 0.2f;
    pieceTypes[6].b = 0.8f;

    return pieceTypes;
}

void printPieceType(struct piecetype piece){
    //print the pieceType
    int i, j;

    for(i = 0; i < 2; i++){
        for(j = 0; j < 4; j++){
            printf("%d ", piece.layout[i][j]);
        }
        printf("\n");
    }
}

struct piece * createPiece() {
    //create a new piece
    struct piece * p;
    p = malloc(sizeof(Piece));
    p->type = pTypes[nextPiece];
    nextPiece = rand()%7;
    printf("NextPiece:%i\n", nextPiece);
    p->x = 4;
    p->y = 0;
    return p;
}

int collisionVerification(int dir) {
    //Recieves a direction and return if there is a collision
    //dir:
    //0->noDirection, 1-> UP, 2-> RIGHT, 3-> DOWN, 4-> LEFT
    //Return:
    //0 -> no collision
    //1 -> collision
    int i, j;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 4; j++){
          if(activePiece->type.layout[i][j] == 1) {
            //for each part of the active piece
            switch(dir) {
                //the same place
                case 0:
                    if(i+activePiece->y < 0 || i+activePiece->y >= SIZEN ||
                        j+activePiece->x < 0 || j+activePiece->x >= SIZEM ||
                        board[i+activePiece->y][j+activePiece->x].active){
                        return 1;
                    }
                    break;
                //UP
                case 1:
                    if(i+activePiece->y-1 < 0 || board[i+activePiece->y-1][j+activePiece->x].active){
                        return 1;
                    }
                    break;
                //RIGHT
                case 2:
                    if(j+activePiece->x+1 >= SIZEM || board[i+activePiece->y][j+activePiece->x+1].active){
                        return 1;
                    }
                    break;
                //DOWN
                case 3:
                    if(i+activePiece->y+1 >= SIZEN || board[i+activePiece->y+1][j+activePiece->x].active){
                        return 1;
                    }
                    break;
                //LEFT
                case 4:
                    if(j+activePiece->x-1 < 0 || board[i+activePiece->y][j+activePiece->x-1].active){
                        return 1;
                    }
                    break;
                //ERROR
                default:
                    return 1;
            }
            //board[i+activePiece->y][j+activePiece->x].active = 1;
          }
        }
    }
    return 0;
}

void pinThePieceOnTheBoard() {
    //Pin the piece on the board
    int i, j;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 4; j++){
          if(activePiece->type.layout[i][j] == 1) {
            board[i+activePiece->y][j+activePiece->x].active = 1;
            board[i+activePiece->y][j+activePiece->x].r = activePiece->type.r;
            board[i+activePiece->y][j+activePiece->x].g = activePiece->type.g;
            board[i+activePiece->y][j+activePiece->x].b = activePiece->type.b;
          }
        }
    }
    free(activePiece);
    activePiece = createPiece();
    if(collisionVerification(0) == 1) {
        printf("GAME OVER!!!\n");
        gameOver = 1;
    }
}

void updatePiece() {
    timeCount++;
    if(timeCount >= gameSpeed) {
        if(collisionVerification(3) == 0) {
            activePiece->y += 1;
        }else {
            pinThePieceOnTheBoard();
        }
        timeCount = 0;
    }
}

void resetLine(int line) {
    int i, j;
    for(j=0 ; j<SIZEM ; j++) {
        board[line][j].active = 0;
    }
    for(i=line-1 ; i>=0 ; i--) {
        for(j=0 ; j<SIZEM ; j++) {
            board[i+1][j].active = board[i][j].active;
            board[i][j].active = 0;
        }
    }
}

void fullLineVerification() {
    int i, j, fullLine=0, qtdReset=0;
    for(i=0 ; i<SIZEN ; i++) {
        fullLine = 1;
        for(j=0 ; j<SIZEM ; j++) {
            if(board[i][j].active == 0) {
                fullLine = 0;
                break;
            }
        }
        if(fullLine == 1) {//full line detected
            resetLine(i);
            qtdReset++;
        }
    }
    if(qtdReset > 0) {
        score += 100*qtdReset*qtdReset;
        printf("Score:%i\n", score);
    }
}




