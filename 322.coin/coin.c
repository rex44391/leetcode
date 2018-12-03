/*
* this is a classic dynamic programming problem.
* but you can also use recursive to solve it
* (also need a table, or it will be very slow)
*/

int coinChange(int* coins, int coinsSize, int amount) {
    int *table = malloc(sizeof(int) * amount + 1);
		//create a table to record the answer for different amount
		//table[10] store the answer for 10 dollars
    for(int i = 0; i < amount + 1; i++)
        table[i] = INT_MAX;//give an init value
    table[0] = 0;//set up the answer of zero
    for(int i = 1; i < coinsSize; i++) {
        if(coins[i] < amount) {
            table[coins[i]] = 1;
        }
    }
    
    for(int i = 1; i < amount + 1; i++) {
        //build up the answer from 1 dollar
				if(table[i] < 2)
            continue;
        else {
            int min = INT_MAX;
            for(int j = 0; j < coinsSize; j++) {
						//if amount i has an answer, it's answer should be
						//(i - a coin's denomination)'s answer + 1
                if(i - coins[j] < 0) {
                    continue;
                } else {
                    if(table[i - coins[j]] != INT_MAX ) {
                        if( (table[i - coins[j]] + 1) < min)
                            min = table[i - coins[j]] + 1;
                    }
                }
            }
            table[i] = min;
        }
    }
    
    if(table[amount] == INT_MAX) {
        return -1;
    } else {
        return table[amount];
    }
}
