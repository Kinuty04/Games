#include <iostream>


#define SPACE ' '
#define UNDER_SCORE '_'


using namespace std;

//<<>>

int count = 0;



class Matrix{
private:
    int rows, cols;
    int data[10][10];
    int j;

public:
    Matrix(int nr, int nc){

        rows = nr;
        cols = nc;

        for (int r = 0; r < nr; r++){
            for (int c = 0; c < nc; c++){
                data[r][c] = 0;
            }
        }
    }

    

    /* You can see all of these on the terminal */
    void printMatrix(){

        int i, j;
        cout << "\n\n\n";

        printf("\x1b[H\x1b[2J\x1b[3J");

        if(count != 0)
            cout << "\n\n" << "      Match started!" << "\n\n";
        else
            cout << "\n\n" << "      The game begins and continues!" << "\n\n";
    
        cout << "     ____  ____  ____  ____  ____  ____  ____  ____" << endl;


        for (i = 0; i < rows; i++){

            cout << "     |";   
            for(int s=0; s<44; s++) cout << SPACE;
            cout << "|" << endl;
            

            cout << "     |  ";

            for (j = 0; j < cols; j++){

                if (data[i][j] == 0){
                    cout << "|__|" << "  ";
                } else{
                    if (data[i][j] == 1)
                        cout << "|BK|" << "  ";
                    else
                        cout << "|WH|" << "  ";
                }
            }

            cout << "| " << i + 1 << endl;
        }

        
        cout << "     |";   
        for(int s=0; s<44; s++) cout << UNDER_SCORE;
        cout << "|" << "\n\n";
        
        cout << "          1     2     3     4     5     6     7";
        cout << "\n\n";

        count++;
    }


    int &operator()(int r, int c) { return data[r][c]; }


    int value(int column){
        int j;

        for (j = 5; j >= 0; j--)
            if (data[j][column] == 0)
                break;

        if (j == -1)
            return -1;

        return j;
    }


    // Matrix reset
    void resetMatrix() {
        for (int i = 0; i < rows; i++) 
            for (int j = 0; j < cols; j++) 
                data[i][j] = 0;
    }



    /* The verify f checks whether I have achieved "four in a row".
       Check in all possible directions: horizontally, vertically, and diagonally.*/
    
       int verify(){

        bool consecutiveHorizontal = false;
        for (int i = 0; i < 6; i++){
            for (int j = 0; j <= 7 - 4; j++){ // 7 - 4 = 3, to control blocks of 4
                if ((data[i][j] == 1 && data[i][j + 1] == 1 &&
                     data[i][j + 2] == 1 && data[i][j + 3] == 1) ||
                    (data[i][j] == 2 && data[i][j + 1] == 2 &&
                     data[i][j + 2] == 2 && data[i][j + 3] == 2)){
                    consecutiveHorizontal = true;
                    break;
                }
            }
        }

        bool consecutiveVertical = false;
        for (int i = 0; i < 7; i++){
            for (int j = 0; j <= 6 - 4; j++){ // 6 - 4 = 2
                if ((data[j][i] == 1 && data[j + 1][i] == 1 &&
                     data[j + 2][i] == 1 && data[j + 3][i] == 1) ||
                    (data[j][i] == 2 && data[j + 1][i] == 2 &&
                     data[j + 2][i] == 2 && data[j + 3][i] == 2)){
                    consecutiveVertical = true;
                    break;
                }
            }
        }

        bool consecutiveDiagonal = false;

        // Check main diagonals (i+j = const)
        for (int i = 0; i < 6; i++){
            for (int j = 0; j < 7; j++){
                // Check if there is a main diagonal of at least 4 elements
                if (i + 3 < 6 && j + 3 < 7){
                    // Ensure that the diagonal has at least 4 elements
                    if (data[i][j] == 1 && data[i + 1][j + 1] == 1 &&
                        data[i + 2][j + 2] == 1 && data[i + 3][j + 3] == 1){
                        consecutiveDiagonal = true;
                    }

                    if (data[i][j] == 2 && data[i + 1][j + 1] == 2 &&
                        data[i + 2][j + 2] == 2 && data[i + 3][j + 3] == 2){
                        consecutiveDiagonal = true;
                    }
                }
                

                if (i + 3 < 6 && j - 3 >= 0){
                    // Ensure that the diagonal has at least 4 elements
                    if (data[i][j] == 1 && data[i + 1][j - 1] == 1 &&
                        data[i + 2][j - 2] == 1 && data[i + 3][j - 3] == 1){
                        consecutiveDiagonal = true;
                    }

                    if (data[i][j] == 2 && data[i + 1][j - 1] == 2 &&
                        data[i + 2][j - 2] == 2 && data[i + 3][j - 3] == 2){
                        consecutiveDiagonal = true;
                    }
                }
            }
        }

        /*
        // Check secondary diagonals (i-j = const)
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 7; j++){
                // Check if there is a secondary diagonal with at least 4 elements
            }
        }*/

        // It might make sense, but the way it’s positioned (and where it is right now) it doesn’t.
        // cout << (sonoConsecutiviDiagonale) << endl;

        if (consecutiveHorizontal)
            return 1;
        if (consecutiveVertical)
            return 1;
        if (consecutiveDiagonal)
            return 1;

        return 0;
    }
};



/*
              _____________________
             /                     \
            |                       |
            |   Connect Four Game   |
            |                       |
             \_____________________/

*/



int main(){

    Matrix M(6, 7);

    int column, row, color=0, ris = 0;
    char letter;
    string player;



    // Game
    
    while (1){
        again:


        M.resetMatrix();

        cout << "\n\n" << "      The game starts! " << "\n" << endl;

        M.printMatrix();


        while(1){
            
            if(color % 2 == 0) player = "Black";
            else               player = "White";


            do{
                cout << "\n\n" << player << " 's turn." << endl;
                cout << "  In which column do you want to insert: ";

                std::cin >> column;
                column--;

                row = M.value(column);

                if (row != -1 && color % 2 == 0)
                    M(row, column) = 1;

                if (row != -1 && color % 2 == 1)
                    M(row, column) = 2;
                
                cout << endl;

            }while(row == -1);

            color += 1;

            M.printMatrix();

            ris = M.verify();

            if(ris != 0){
                cout << "\n\n" << player << " win the game!" << endl;
                break;
            }
        }


        cout << "\n\n";
        

        while(1){

            cout << "      Do you want to continue? [y]/[Y]\n      Otherwise, enter [n]/[N] to finish: ";
            cin >> letter;
            if(letter == 'n' || letter == 'N')
                return 0;
            if(letter == 'y' || letter == 'Y')
                goto again;
        }
    }
}
