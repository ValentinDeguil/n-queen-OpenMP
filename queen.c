#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int search(int queenPlaced[], int N, int currentRow);
void showIntArray(int queenPlaced[], int N);
bool tryNewQueen();

int main(int argc, char *argv[]){

    //Initializing value
    int N = atoi(argv[1]);
    bool *boolCol, *boolRow;
    boolCol = malloc(N*sizeof (bool));
    boolRow = malloc(N*sizeof (bool));
    int queenPlaced[N];
    for (int i = 0; i < N ; i++){
        boolCol[i] = false;
        boolRow[i] = false;
        queenPlaced[i] = -1;
    }

    //Starting algorithm
    int result = 0;
    for (int i = 0; i < N ; i++){
        queenPlaced[0] = i;
        //result += search(queenPlaced, int N, int currentRow);
        showIntArray(queenPlaced, N);
    }

}

int search(int queenPlaced[], int N, int currentRow){
    for (int i = 0; i < N ; i++){
        bool isPossible = tryNewQueen();
    }
    return 0;
}

bool tryNewQueen(){
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