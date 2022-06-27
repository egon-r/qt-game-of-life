#include "golgridmodel.h"

GolGridModel::GolGridModel(int boardSize)
{
    ResizeBoard(boardSize);
}

/*
Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
Any live cell with two or three live neighbours lives on to the next generation.
Any live cell with more than three live neighbours dies, as if by overpopulation.
Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
*/
void GolGridModel::NextIteration()
{
    BoardState newState[bStateSize];
    std::memcpy(newState, bState, sizeof(BoardState)*bStateSize);

    for(int x = 0; x < bStateRowSize; x++)
    {
        for(int y = 0; y < bStateRowSize; y++)
        {
            int neighbours = GetNeighbourCountAt(x,y);
            if(GetStateAt(x,y) == alive)
            {
                if(neighbours < 2)
                {
                    newState[bStateRowSize * y + x] = dead;
                }else if(neighbours == 2 | neighbours == 3)
                {
                    newState[bStateRowSize * y + x] = alive;
                }else if(neighbours >= 3)
                {
                    newState[bStateRowSize * y + x] = dead;
                }
            }else
            {
                if(neighbours == 3)
                {
                    newState[bStateRowSize * y + x] = alive;
                }
            }
        }
    }

    std::memcpy(bState, newState, sizeof(BoardState)*bStateSize);
}

void GolGridModel::ResizeBoard(int newSize)
{
    bStateSize = newSize*newSize;
    bStateRowSize = newSize;
    bState = new BoardState[bStateSize];
    for(int i = 0; i < bStateSize; i++)
    {
        bState[i] = dead;
    }
}

void GolGridModel::RandomizeBoardState()
{
    for(int x = 0; x < bStateRowSize; x++){
        for(int y = 0; y < bStateRowSize; y++){
            SetStateAt(x,y,BoardState(rand() % last));
        }
    }
}

int GolGridModel::GetNeighbourCountAt(int xCenter, int yCenter)
{
    int nCount = 0;

    for(int x = -1; x <= 1; x++)
    {
        for(int y = -1; y <= 1; y++)
        {
            if((xCenter + x >= 0 && xCenter + x <= bStateRowSize) &&
               (yCenter + y >= 0 && yCenter + y <= bStateRowSize))
            {

                if(!(xCenter+x == xCenter && yCenter+y == yCenter))
                {
                    if(GetStateAt(xCenter+x, yCenter+y) == alive)
                    {
                        nCount++;
                    }
                }
            }
        }
    }
    return nCount;
}

BoardState GolGridModel::GetStateAt(int x, int y)
{
    return bState[bStateRowSize *y + x];
}

void GolGridModel::SetStateAt(int x, int y, BoardState newState)
{
    bState[bStateRowSize *y+x] = newState;
}

BoardState* GolGridModel::GetBoardState()
{
    return bState;
}

int GolGridModel::GetBoardSize()
{
    return bStateRowSize;
}
