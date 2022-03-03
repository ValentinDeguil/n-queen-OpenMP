#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

int search(int queenPlaced[], int N, int currentRow);
void showIntArray(int queenPlaced[], int N);
bool tryNewQueen();
void test();

int main(int argc, char *argv[]){

    //Initializing value
    int N = atoi(argv[1]);
    int nbThread = atoi(argv[2]);
    int queenPlaced[N];
    for (int i = 0; i < N ; i++){
        queenPlaced[i] = -1;
    }

    //Starting algorithm
    int result = 0;
    double start, end;
    start = omp_get_wtime();

    #pragma omp parallel num_threads (nbThread) private (queenPlaced)
    {

        #pragma omp for schedule (dynamic)
        for (int i = 0; i < N; i++) {
            queenPlaced[0] = i;
            result += search(queenPlaced, N, 1);
        }
    }
    end = omp_get_wtime();

    printf("time : %f ", end - start);
    printf("result = %d\n", result);
}

int search(int queenPlaced[], int N, int currentRow){
    if(currentRow == N){
        return 1;
    }
    int subResult = 0;
    int newQueenPlaced[N];
    for (int i = 0; i < N ; i++){
        newQueenPlaced[i] = queenPlaced[i];
    }

    for (int i = 0; i < N ; i++){
        if(tryNewQueen(queenPlaced, currentRow, i)){
            newQueenPlaced[currentRow] = i;
            subResult += search(newQueenPlaced, N, currentRow+1);
        }
    }
    return subResult;
}

bool tryNewQueen(int queenPlaced[], int currentRow, int i){
    for (int j = 0; j < currentRow; j++){
        if (queenPlaced[j] == i || fabs(j - currentRow) == fabs(queenPlaced[j] - i)){ //ici, on check si ya pas déjà une reine dans la colonne
            return false;
        }
    }
    return true;
}



//---------------- Debug functions ----------------//

void showIntArray(int queenPlaced[], int N){ //temp
    printf("[%d", queenPlaced[0]);
    for (int i = 1; i < N; i++){
        printf(",%d", queenPlaced[i]);
    }
    printf("]\n");
}

void test(){
    printf("start test\n");
    printf("true = %i\n", true);
    printf("false = %i\n", false);
    int queenPlaced[5] = {2,0,3,-1,-1};
    printf("%i\n", tryNewQueen(queenPlaced, 3, 2));
    printf("start test\n");
}