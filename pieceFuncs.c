#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZEM 10
#define SIZEN 20

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

struct piecetype * createPieceTypes(){
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
    int i, j;

    for(i = 0; i < 2; i++){
        for(j = 0; j < 4; j++){
            printf("%d ", piece.layout[i][j]);
        }
        printf("\n");
    }
}

struct piece * createPiece() {
    struct piece * p;
    p = malloc(sizeof(Piece));
    int rnd = rand()%7;
    p->type = pTypes[rnd];
    //p->x = 5;//center
    //p->y = 16;//top
    p->x = 4;
    p->y = 0;
    return p;
}

void pinThePieceOnTheBoard() {
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
}






