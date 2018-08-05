


int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int numRescueBoats(int* people, int peopleSize, int limit) {
     qsort(people, peopleSize, sizeof(int), cmpfunc);
    
    int counter = 0;
    int left = 0;
    int right = peopleSize - 1;
    while(left < right) {
        if( (people[left] + people[right]) <= limit ) {
            counter++;
            left++;
            right--;
        } else {
            right--;
            counter++;
        }
    }
    if(left == right) {
        counter++;
    }
    
    return counter;
}
