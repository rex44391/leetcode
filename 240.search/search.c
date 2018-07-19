/* Beating other 80% submissions, and it's super concise and understandable.
*/

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    for(int i = 0; i < matrixRowSize; i++) {
        for(int j = 0; j < matrixColSize; j++) {
            if(matrix[i][j] == target)
                return true;
        }
    }
    return false;
}
