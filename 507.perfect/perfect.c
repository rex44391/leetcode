/*
* after checking the wiki page of perfect number
* I noticed that there are very few perfect number in a limited range
* so to make the most efficient algorithm, I decided to just hard code the numbers.
* And of course it beats other 100% of submissions
*/

bool checkPerfectNumber(int num) {
    if(num == 6 || num == 28 || num == 496 || num == 8128 || num == 33550336)
        return true;
    return false;
}
