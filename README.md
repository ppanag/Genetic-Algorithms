## Fast genetic algorithm library in C, to solve non-linear optimization problems.

Compile with:
```
    gcc -o executable *.c -lm
```

Run (1000 generations):
```
    chmod a+x executable
    ./executable 1000
```

Define your own function to be optimized:  
    Change the files zz_costfunction.h and zz_costfunction.c

Future work:  
    Parallel processing with distributed populations.
