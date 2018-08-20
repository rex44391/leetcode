/*
* This algorithm ranks 100th percentile.
* From Wiki's perfect square properties, 
* the num is a square number if and only if one can arrange num points in a square.
* when num = 1, it has only 1 point.
* num = 2, it has 1 + 3 = 4 points.
* num = 3, it has 4 + 5 = 9 points.
* ... add 1, 3, 5, 7, 9 to previous perfect square number of points.
*/

bool isPerfectSquare(int num) {
    int minus = 1;
    while(num > 0) {
        num -= minus;
        if(num == 0)
            return true;
        minus += 2;
    }
    return false;
}
