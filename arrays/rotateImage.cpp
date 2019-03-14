/**
*Note: Try to solve this task in-place (with O(1) additional memory), since this is what you'll be asked to do during an interview.
*You are given an n x n 2D matrix that represents an image. Rotate the image by 90 degrees (clockwise).
**/

std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {
    int halfSize =  a.size()/2;
    for(int i=0; i < halfSize ; i++) {
        for(int j=0; j < halfSize; ++j) {
            int swap, nr, nc; //nr and nc represent next row and column respectively
            nc=j;
            nr=i;
            swap = a[nr][nc];
            for (int k = 0; k < 4; ++k) { //It is a square so we have to swap 4 elements
                int NColumn = a.size() -nr -1;
                int NRow = nc;
                int Nswap = a[NRow][NColumn];
                a[NRow][NColumn] = swap;
                swap = Nswap;
                nc = NColumn;
                nr = NRow;
            }
        }
    }
        if (a.size()%2 != 0) {
            int row = (a.size()/2); //The elemnts that's missing
            for (int i = 0; i <halfSize; ++i) {
                int aux = a[row][i];
                int nc, nr;
                nc = i;
                nr = row;
                for (int k = 0; k < 4; ++k) { //It is a square so we have to swap 4 elements
                    int NColumn = a.size() -nr -1;
                    int NRow = nc;
                    int Nswap = a[NRow][NColumn];
                    a[NRow][NColumn] = aux;
                    aux = Nswap;
                    nc = NColumn;
                    nr = NRow;
                }
            }
        }
    return a;
}
