/*
* Based on the problem's definition, a judge should
* (1) be trusted by every people except for himself => he need N - 1 people's trust
* (2) trust no other people => he himself trust 0 people
* the solution's time and space complexity are both O(N)
*/

int findJudge(int N, int** trust, int trustRowSize, int *trustColSizes) {
    int *from = malloc(sizeof(int) * N);
    int *to = malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++) { 
        from[i] = 0;// i-th person trust how many people
        to[i] = 0;// i-th person is trusted by how many people
    }
    for(int i = 0; i < trustRowSize; i++) {
        from[trust[i][0] - 1] += 1;
        to[trust[i][1] - 1] += 1;
    }
    
    for(int i = 0; i < N; i++) {
				//check the condition of a judge
        if(to[i] == (N - 1) && from[i] == 0)
            return i + 1;
    }
    return -1;
}
