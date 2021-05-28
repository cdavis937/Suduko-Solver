#include "HeaderFiles/Grid.h"
#include <iostream>

bool Grid::isSafe(int row, int col, int num){

    //Check to see that the number is not in the row
    for(int i = 0; i < 9; i++){
        
        if(grid[row][i] == num){
            return false;
        }

    }

    //Check to see that the number is not in the column
    for(int i = 0; i < 9; i++){


        if(grid[i][col] == num) {
            return false;
        }

    }


    //Create starting indicies for checking the sub square
    int beginRow = row - row % 3;
    int beginCol = col - col % 3;

    //Check to make sure that the subsquare does not have the number
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[beginRow + i][beginCol + j] == num){
                return false;
            }
        }
    }
    
    //Return true as long as long as tests passed
    return true;

}

bool Grid::solvePuzzle(int row, int col){

    //If we reach past the last row and column solve the puzzle
    if(row == 8 && col == 9){
        return true;
    }

    //If columns are over 8 then reset it back to 0
    if(col == 9){
        row++;
        col = 0;
    }

    /*
    / As long as the number at that position is not 0 then call recusion raising the column
    */
    if(grid[row][col] != 0){
        return solvePuzzle(row, col + 1);
    }

    /*
    /Go through and make sure the number is safe, if it is then put it in and try to test the next position
    /if it does not work out come back and change the number so that it does
    */

    for(int i = 1; i <= 9; i++){

        if(isSafe(row, col, i)){
            
            grid[row][col] = i;
            
            if(solvePuzzle(row, col + 1)){
                return true;
            }

        }

        grid[row][col] = 0;

    }
    
    //Return false if it can be solved with any combination
    return false;

}

void Grid::printGrid(){

    //Print out the header for the grid interface
    std::cout << std::endl << "  012|345|678" << std::endl;
    std::cout << "-------------" << std::endl; 

    for(int i = 0; i < 9; i++){
        
        //Print out row number and a divider
        std::cout << i << "|";

        for(int j = 0; j < 9; j++){

            //If three have been printed then print a divider
            if(j == 3 || j == 6){
            std::cout << "|";

        }
            //Print out the number
            std::cout << grid[j][i];

        }

        std::cout << std::endl;

        //If three have been printed vertically then print a divider
        if(i == 2 || i == 5){
            std::cout << "-------------" << std::endl;
        }

    }

}

void Grid::posInput(){

    int rowPos = 9;

    //Grab a valid row position
    while(rowPos > 8 || rowPos < 0){
        
        std::cout << "Enter Row:";

        std::cin >> rowPos;

    }

    int colPos = 9;

    //Grab a valid column position
    while(colPos > 8 || colPos < 0){
        
        std::cout << "Enter Column:";

        std::cin >> colPos;
        
    }

    int num = 10;

    //Grab a valid number
    while(num > 9 || num < 1){

        std::cout << "Enter Number:";

        std::cin >> num;

    }

    //Store the number position
    grid[rowPos][colPos] = num;

}

Grid::Grid(){

    //Initialize the grid to all zeros
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            grid[j][i] = 0;
        }
    }
}
