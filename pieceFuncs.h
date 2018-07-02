#include <stdio.h>
#include <stdlib.h>
#include "pieceFuncs.c"

void printPieceType(struct piecetype piece);

struct piecetype * createPieceTypes();

struct piece * createPiece();

void pinThePieceOnTheBoard();

int collisionVerification(int dir);

void updatePiece();
