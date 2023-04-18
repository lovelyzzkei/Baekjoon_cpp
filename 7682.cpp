#include <iostream>
#include <string>
#include <utility>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); 

using namespace std;

string input;

void countOX(int &numX, int &numO)
{
    for (int i = 0; i < 9; i++) {
        if (input[i] == 'X') numX++;
        else if (input[i] == 'O') numO++;
    }
}

void bingo(int &threeX, int &threeO, bool &isParallel)
{
    int rowThreeX = 0, rowThreeO = 0;
    int colThreeX = 0, colThreeO = 0;
    
    // three O, X in row
    for (int row = 0; row < 3; row++) {
        if (input[row*3] == 'O' && input[row*3+1] == 'O' && input[row*3+2] == 'O')
            rowThreeO++;
        if (input[row*3] == 'X' && input[row*3+1] == 'X' && input[row*3+2] == 'X')
            rowThreeX++;  
    }

    if (rowThreeX > 1 || rowThreeO > 1)
        isParallel = true;

    for (int col = 0; col < 3; col++) {
        if (input[0*3+col] == 'O' && input[1*3+col] == 'O' && input[2*3+col] == 'O')
            colThreeO++;
        if (input[0*3+col] == 'X' && input[1*3+col] == 'X' && input[2*3+col] == 'X')
            colThreeX++;
    }

    if (colThreeX > 1 || colThreeO > 1)
        isParallel = true;

    threeX = rowThreeX + colThreeX;
    threeO = rowThreeO + colThreeO;

    if (input[0] == 'O' && input[4] == 'O' && input[8] == 'O') threeO++;
    if (input[0] == 'X' && input[4] == 'X' && input[8] == 'X') threeX++;

    if (input[2] == 'O' && input[4] == 'O' && input[6] == 'O') threeO++;
    if (input[2] == 'X' && input[4] == 'X' && input[6] == 'X') threeX++;

}

int main(void)
{
    FAST_IO;
    while (true) {
        cin >> input;
        if (!input.compare("end"))
            break;

        int numX = 0, numO = 0, threeX = 0, threeO = 0;
        bool inValid = true, isParallel = false;
        
        countOX(numX, numO);
        bingo(threeX, threeO, isParallel);

        if (numX == numO)
        {
            if (threeO == 1 && threeX == 0 && !isParallel) 
                inValid = false;
        }
        if (numX == numO + 1)
        {
            if (!isParallel && ((numX + numO == 9 && threeO == 0 && threeX == 0) || (threeO == 0 && threeX >= 1)))
                inValid = false;
        }

        if (inValid)
            cout << "invalid" << endl;
        else
            cout << "valid" << endl;
    }

    return 0;
}