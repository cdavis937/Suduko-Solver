#include <iostream>
#include "HeaderFiles/Grid.h"

int main(){

    Grid grid;

    char sel = 'f';

    //Run as long as user wants to input numbers
    while(sel == 'f'){

        //Print grid for user to see
        grid.printGrid();

        //Grab and store position of their input
        grid.posInput();

        //Print the updated grid for the user to see
        grid.printGrid();

        //Ask the user what they want to do
        std::cout << "Enter f to enter another number" << std::endl << "Enter s to solve the puzzle";
        std::cout << std::endl << "Your selection:";

        std::cin >> sel;

    }

    //Let the user know that the puzzle is being solved
    std::cout << std::endl << "Solving..." << std::endl;

    //If the puzzle is completely solved then print it, otherwise let the user know there is no solution
    if(grid.solvePuzzle(0,0)){
        grid.printGrid();
    }else{
        std::cout << "No solution" << std::endl;
    }

}