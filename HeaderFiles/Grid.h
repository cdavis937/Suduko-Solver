class Grid {

    private:

        int grid[9][9];
        
    public:

        bool isSafe(int row, int col, int num);

        bool solvePuzzle(int row, int col);

        void printGrid();

        void posInput();

        Grid();

};