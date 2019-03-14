/*
*Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 grid with numbers in such a way that each column, each row, 
*and each of the nine 3 × 3 sub-grids that compose the grid all contain all of the numbers from 1 to 9 one time.
*Implement an algorithm that will check whether the given grid of numbers represents a valid Sudoku puzzle according to the layout 
*rules described above. Note that the puzzle represented by grid does not have to be solvable.
*/

bool sudoku2(std::vector<std::vector<char>> grid) {
    /* We create two boolean vectors, of size 9x9, a 
     * The columns identifies the i-nth row or column on the sudoku grid
     * The rows identifies that number+1 in the sudoku grid
     * For example columns[4,5] represents the number 6 in the 4th columns (0 indexed)
     *True indicates that the number is present in that row or column
     
     The cost of this algorithm is O(n)
     */
    std::vector<std::vector<bool>> columns(9, std::vector<bool>(9, false));
    std::vector<std::vector<bool>> rows(9, std::vector<bool>(9, false));
    
    for (int i = 0; i < 9; i+=3) {
        for (int j = 0; j < 9; j+=3) {
            std::vector<bool> square(9, false);
            for (int row_square = 0; row_square < 3; ++row_square) {
                for (int col_square = 0; col_square < 3; ++col_square) {
                    char tmp = grid[row_square+i][col_square+j];
                    if(tmp != '.') {
                        if (square[tmp-'1']) return false;
                        if (rows[row_square+i][tmp-'1']) return false;
                        if (columns[col_square+j][tmp-'1']) return false;
                        square[tmp-'1'] = true;
                        rows[row_square+i][tmp-'1'] = true;
                        columns[col_square+j][tmp-'1'] = true;
                    }
                }
            }
        }
    }
    return true;
}
