# n-queen OpenMP
Solving n-queen problem, tree-search, brute-force, sequential and parallel.



To compile with OpenMP
```cmd
    gcc -fopenmp queenSequetial.c
    gcc -fopenmp queenParallel.c
```

To execute the problem with 8 queens and 4 cores :
```cmd
    ./a.out 8 4
```

Expected results :

| number of queens | number of solution |
|------------------|--------------------|
| 1                | 1                  |
| 2                | 0                  |
| 3                | 0                  |
| 4                | 2                  |
| 5                | 10                 |
| 6                | 4                  |
| 7                | 40                 |
| 8                | 92                 |
| 9                | 352                |
| 10               | 724                |
| 11               | 2,680              |
| 12               | 14,200             |
| 13               | 73,712             |
| 14               | 365,592            |
| 15               | 2,279,184          |