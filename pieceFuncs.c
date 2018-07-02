#include <stdio.h>
#include <stdlib.h>
#include "pieceFuncs.h"

struct piecetype{
    int layout[2][4];
};

struct piece{
    PieceType type;
    int x;
    int y;
};

PieceType * createPieceTypes(){
    static PieceType pieceTypes[7];
    //piecetype 1: I
    pieceTypes[0].layout[0][0] = 1;
    pieceTypes[0].layout[0][1] = 1;
    pieceTypes[0].layout[0][2] = 1;
    pieceTypes[0].layout[0][3] = 1;
    pieceTypes[0].layout[1][0] = 0;
    pieceTypes[0].layout[1][1] = 0;
    pieceTypes[0].layout[1][2] = 0;
    pieceTypes[0].layout[1][3] = 0;

    //piecetype2: T
    pieceTypes[1].layout[0][0] = 0;
    pieceTypes[1].layout[0][1] = 1;
    pieceTypes[1].layout[0][2] = 0;
    pieceTypes[1].layout[0][3] = 0;
    pieceTypes[1].layout[1][0] = 1;
    pieceTypes[1].layout[1][1] = 1;
    pieceTypes[1].layout[1][2] = 1;
    pieceTypes[1].layout[1][3] = 0;

    //piecetype3: quadrado
    pieceTypes[2].layout[0][0] = 0;
    pieceTypes[2].layout[0][1] = 1;
    pieceTypes[2].layout[0][2] = 1;
    pieceTypes[2].layout[0][3] = 0;
    pieceTypes[2].layout[1][0] = 0;
    pieceTypes[2].layout[1][1] = 1;
    pieceTypes[2].layout[1][2] = 1;
    pieceTypes[2].layout[1][3] = 0;

    //piecetype4: L
    pieceTypes[3].layout[0][0] = 0;
    pieceTypes[3].layout[0][1] = 0;
    pieceTypes[3].layout[0][2] = 1;
    pieceTypes[3].layout[0][3] = 0;
    pieceTypes[3].layout[1][0] = 1;
    pieceTypes[3].layout[1][1] = 1;
    pieceTypes[3].layout[1][2] = 1;
    pieceTypes[3].layout[1][3] = 0;

    //piecetype5: L invertido
    pieceTypes[4].layout[0][0] = 1;
    pieceTypes[4].layout[0][1] = 1;
    pieceTypes[4].layout[0][2] = 1;
    pieceTypes[4].layout[0][3] = 0;
    pieceTypes[4].layout[1][0] = 0;
    pieceTypes[4].layout[1][1] = 0;
    pieceTypes[4].layout[1][2] = 1;
    pieceTypes[4].layout[1][3] = 0;

    //piecetype6: N
    pieceTypes[5].layout[0][0] = 1;
    pieceTypes[5].layout[0][1] = 1;
    pieceTypes[5].layout[0][2] = 0;
    pieceTypes[5].layout[0][3] = 0;
    pieceTypes[5].layout[1][0] = 0;
    pieceTypes[5].layout[1][1] = 1;
    pieceTypes[5].layout[1][2] = 1;
    pieceTypes[5].layout[1][3] = 0;

    //piecetype6: N invertido
    pieceTypes[6].layout[0][0] = 0;
    pieceTypes[6].layout[0][1] = 1;
    pieceTypes[6].layout[0][2] = 1;
    pieceTypes[6].layout[0][3] = 0;
    pieceTypes[6].layout[1][0] = 1;
    pieceTypes[6].layout[1][1] = 1;
    pieceTypes[6].layout[1][2] = 0;
    pieceTypes[6].layout[1][3] = 0;

    return pieceTypes;
}

void printPieceType(PieceType piece){
    int i, j;

    for(i = 0; i < 2; i++){
        for(j = 0; j < 4; j++){
            printf("%d ", piece.layout[i][j]);
        }
        printf("\n");
    }
}

int main(){
    /*PieceType* tipoPeca = createPieceTypes();
    int i;

    for(i=0; i<7; i++){
        printPieceType(tipoPeca[i]);
        printf("\n");
    }*/

    return 0;
}
