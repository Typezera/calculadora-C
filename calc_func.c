#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "calc_func.h"
int sum(int a, int b){
    return a + b;
};

int subtraction(int a, int b){
    return a - b;
}

int multiplication(int a, int b){
    return a * b;
}


int division(int a, int b){
    if (b == 0)
    {
        printf("\x1b[31m[ERROR] \x1b[0m Possível divisão por zero, insira um valor valido.\n");
        return -1;
    }
    return a / b;
}

