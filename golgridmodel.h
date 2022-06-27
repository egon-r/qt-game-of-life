#ifndef GOLGRIDMODEL_H
#define GOLGRIDMODEL_H

#include <math.h>
#include <cstring>
#include <QDebug>

typedef enum{
    dead, alive,
    last
}BoardState;

class GolGridModel
{
private:
    BoardState *bState;
    int bStateSize;
    int bStateRowSize;

public:
    GolGridModel(int boardSize);
    void NextIteration();

    void ResizeBoard(int newSize);
    void RandomizeBoardState();
    int GetNeighbourCountAt(int xCenter, int yCenter);
    BoardState GetStateAt(int x, int y);
    void SetStateAt(int x, int y, BoardState newState);
    BoardState* GetBoardState();
    int GetBoardSize();
};

#endif // GOLGRIDMODEL_H
